// Metin2MSAMaker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>

#include "ModelManager.h"

#pragma comment (lib, "granny2.lib")

typedef std::list<fs::path>	TPathInfoList;

// 이미 후처리가 된 MSA파일엔 아래 데이터들이 있다. 얘네 있는 애들은 덮어쓰면 안 됨 -_-;
static std::string s_IgnoreKeywords[] = { "ComboInputData", "AttackingData", "MotionEventData", "LoopData", };

bool FileIntoString(const fs::path& path, std::string* outString = NULL)
{
	assert(NULL != outString);

	fs::ifstream fs;
	std::string line;

	fs.open(path, std::ios::in);

	// 파일은 있는데 확인에 실패했다면 -_-; 무시하도록 한다.
	if (!fs.is_open())
	{
		char errorMsg[255] = {0, };
		strerror_s(errorMsg, sizeof(errorMsg), errno);

		printf("[FAIL] %s\n\t%s \n", path.string().c_str(), errorMsg);

		return true;
	}

	outString->clear();

	fs.clear();

	while(std::getline(fs, line))
		outString->append(line);

	return true;
}

/**
	이미 MSA파일이 있는지 검사하고, 있다면 후처리 데이터가 존재하기 때문에 덮어쓰면 안 되는 파일인지 검사 후 리턴
	@return true: 무시해야 함, false: 덮어써도 됨
*/
bool IsNeedIgnoreMSA(const fs::path& msaPath)
{
	if (false == fs::is_regular_file(msaPath))
		return false;

	std::string fileContent;
	if (false == FileIntoString(msaPath, &fileContent))
		return false;

	// 이미 존재하는 MSA 파일에 Ignore Keyword가 하나라도 있다면, 무시해도 좋다고 리턴함.
	for (size_t i = 0; i < _countof(s_IgnoreKeywords); ++i)
		if (fileContent.find(s_IgnoreKeywords[i]) != std::string::npos)
			return true;

	return false;
}

// 입력된 파일에서 Accumulation값을 구해야 하는지를 리턴한다.
bool IsNeedCalcAccumulation(const fs::path& path)
{
	// Accumulation값을 구해야 하는 파일들. 다른 모션들은 Accumulation 값이 있어도 쓰면 안 된다고 함..
	static std::string s_NeedCalcAccumulations[] = {"walk", "run" };

	// 파일 이름에 walk, run 등이 있으면 Accumulation 필요
	const std::string filename = boost::algorithm::to_lower_copy(path.file_string());

	for (size_t i = 0; i < _countof(s_NeedCalcAccumulations); ++i)
	{
		if (filename.find(s_NeedCalcAccumulations[i]) != std::string::npos)
			return true;
	}

	return false;
}


enum EResult
{
	EResult_OK,			///< 성공
	EResult_Ignore,		///< 무시 (이미 MSA 파일이 있고, 복잡한 형식인 경우이거나, 에니메이션 정보가 없는 경우 무시)
	EResult_Fail		///< 파일이 없거나, 애니메이션 정보가 없거나 등등...
};


// 입력된 파일을 분석해 MSA파일을 만드는 함수. 프로그램의 실질적인 main logic
EResult MakeMSA(const fs::path& filePath, std::string* outMsg = 0)
{
	const int axisCount = 3;
	bool bIsAccumulationMotion = true;
	granny_real32 duration = 0.0f;
	granny_matrix_4x4 modelMatrix = {0, };

	assert(0 != outMsg);

	*outMsg = "OK";

	if (false == CModel::IsGrannyFile(filePath))
		return EResult_Fail;

	fs::path basePath = filePath.parent_path();

	fs::path msaPath = basePath / (filePath.stem() + ".msa");

	if (IsNeedIgnoreMSA(msaPath))
	{
		*outMsg = "FAIL - Complicated MSA";
		return EResult_Ignore;
	}


	granny_file* grannyFile = GrannyReadEntireFile(filePath.string().c_str());
	granny_file_info* fileInfo = GrannyGetFileInfo(grannyFile);

	if (1 != fileInfo->AnimationCount)
	{
		*outMsg = "IGNORE - NO Animation";

		if (1 < fileInfo->AnimationCount)
			*outMsg = "IGNORE - Too many animations";

		if (0 < fileInfo->ModelCount)
		{
			CModelManager::Instance().RegisterModel(filePath);
			*outMsg = "IGNORE - MODEL FILE(NO Animation)";
		}

		GrannyFreeFile(grannyFile);
		return EResult_Ignore;
	}

	// 그래니 애니메이션 방식이 독특해서, 애니메이션 키를 확인하기 힘들어 애니메이션을 직접 재생 해 봐야 한다.
	// 애니메이션 파일엔 모델 정보가 아예 없어서 모델을 찾아서 읽고, 그 모델에 애니메이션을 적용함.

	CModel* modelWrapper = CModelManager::Instance().GetModel(filePath);
	if (0 == modelWrapper)
	{
		// 모델이 없다면 한 단계 상위 폴더에서 찾아봄
		modelWrapper = CModelManager::Instance().GetModel(filePath.parent_path());

		// 그래도 없으면 현재 폴더 및 상위 폴더에서 모델 파일을 검색 해 보고, 있으면 등록하도록 함.
		if (0 == modelWrapper)
		{
			modelWrapper = CModelManager::Instance().AutoRegisterAndGetModel(filePath, 2);
		}

		// 이래도 없다면-_- 즐
		if (0 == modelWrapper)
		{
			*outMsg = "FAIL - Can't find model file";
			GrannyFreeFile(grannyFile);
			return EResult_Fail;
		}
	}


	// 애니메이션이 한 개 이상인 경우가 있을까.. -_-; 일단은 한개라고 가정함. 한 모션 파일에 여러 애니메이션이 있는 경우는 없다는 듯.
	for (int i = 0; i < fileInfo->AnimationCount; ++i)
	{
		granny_animation* animation = fileInfo->Animations[i];
		granny_model* model = modelWrapper->GetModel();
		const int boneCount = model->Skeleton->BoneCount;
		duration = animation->Duration;

		// Accumulation값을 구해야 한다면, 애니메이션을 재생시켜봄으로써 관련 값을 구하도록 한다.
		// Granny의 Motion 파일 구조가 translate, rotation 키 등이 직관적이지 않아서 정확한 값을 구하려면 직접 재생 해 봐야 함. (디코딩하는 방법이 있을텐데 일단 재생시켜보는게 편하니 패스-_-)
		if (IsNeedCalcAccumulation(filePath))
		{
			int trackIndex = -1, bip01Index = -1;

			if (!GrannyFindTrackGroupForModel(animation, model->Name, &trackIndex))
				trackIndex = 0;

			if (1 > animation->TrackGroupCount)
			{
				*outMsg = "FAIL - Invalid Track Group Count";
				GrannyFreeFile(grannyFile);
				return EResult_Fail;
			}
			
			if (!GrannyFindBoneByName(model->Skeleton, "Bip01", &bip01Index))
				bip01Index = 0;

			granny_model_instance* modelInstance = GrannyInstantiateModel(model);

			granny_local_pose* localPose = GrannyNewLocalPose(boneCount);
			granny_world_pose* worldPose = GrannyNewWorldPose(boneCount); 

			//granny_control* control = GrannyPlayControlledAnimation(0.0f, animation, modelInstance);
			granny_controlled_animation_builder *builder = GrannyBeginControlledAnimation(0.0f, animation);
				GrannySetTrackGroupTarget(builder, trackIndex, modelInstance);
				GrannySetTrackGroupAccumulation(builder, trackIndex, GrannyConstantExtractionAccumulation);
			granny_control* control = GrannyEndControlledAnimation(builder);

			// 애니메이션 시작 position
			GrannySetControlClock(control, 0.0f);

			modelMatrix[0][0] = modelMatrix[1][1] = modelMatrix[2][2] = modelMatrix[3][3] = 1.0f;
			GrannyUpdateModelMatrix(modelInstance, 0.0f, (granny_real32*)modelMatrix, (granny_real32*)modelMatrix);

			modelMatrix[0][0] = modelMatrix[1][1] = modelMatrix[2][2] = modelMatrix[3][3] = 1.0f;
			GrannyUpdateModelMatrix(modelInstance, animation->Duration - 0.000001f, (granny_real32*)modelMatrix, (granny_real32*)modelMatrix);

			// 변화값이 대략 50이하인 경우는 제자리 모션이라는듯..? 확인필요
			if (40.0f < fabs(modelMatrix[3][1]))
				bIsAccumulationMotion = true;

			GrannyFreeControlOnceUnused(control);
			GrannyFreeCompletedModelControls(modelInstance);
			GrannyFreeLocalPose(localPose);
			GrannyFreeWorldPose(worldPose);

			GrannyFreeModelInstance(modelInstance);
		}
	}

	GrannyFreeFile(grannyFile);


#if 1
	FILE* fp = 0;
	fopen_s(&fp, msaPath.string().c_str(), "wt");

	if (0 == fp)
	{
		*outMsg = "FAIL - Can't write MSA file";
		return EResult_Fail;
	}


	// MSA 저장.. -_-; 꼭 이 포맷으로 저장해야 하는 듯..?? 
	fprintf(fp, "ScriptType               MotionData\n");
	fprintf(fp, "\n");

	fprintf(fp, "MotionFileName           \"%s\"\n", filePath.string().c_str());
	fprintf(fp, "MotionDuration           %f\n", duration);

	// Accumulation 값은 Y축만 세팅해야 한다고 함
	if (bIsAccumulationMotion)
	fprintf(fp, "Accumulation             %.2f\t%.2f\t%.2f\n", 0.0f, modelMatrix[3][1], 0.0f);

	fprintf(fp, "\n");

	fclose(fp);
#endif

	return EResult_OK;
}

int _tmain(int argc, _TCHAR* argv[])
{
	TPathInfoList pathInfoList;

	std::locale::global(std::locale("kor"));
	std::string msg;

	FILE* fpLog = 0;

	// stdout stream redirection to log file
	std::string logPath = std::string(argv[0]) + ".log";
	freopen_s(&fpLog, logPath.c_str(), "a+t", stdout);


	for (int i = 1; i < argc; ++i)
	{
		fs::path inPath  = argv[i];
		
		if (false == fs::exists(inPath))
			continue;

		const bool bIsDirectory = is_directory(inPath);

		if (CModel::IsGrannyFile(inPath))
		{
			if (CModel::IsGrannyModelFile(inPath))
			{
				// GR2 모델파일 처리를 여기서 하는 이유는, 이 로직에 들어왔다는 것 자체가 
				// 사용자가 직접 파일을 드래그 혹은 선택 한 것이므로 우선적으로 이 모델을 먼저 사용하도록 하기 위함.
				CModelManager::Instance().RegisterModel(inPath);
			}
			else
				pathInfoList.push_back(inPath);
		}

		// 사용자가 디렉토리를 선택한 경우에는 그 폴더에서 하위로 recursive 탐색해 모든 gr2파일을 찾아 처리한다.
		if (bIsDirectory)
		{
			for (boost::filesystem::recursive_directory_iterator end, dir_iter(inPath); dir_iter != end; ++dir_iter)
			{
				const fs::path& curPath = *dir_iter;

				if (CModel::IsGrannyFile(curPath))
					pathInfoList.push_back(curPath);
			}
		}
	}

	// 위에서 얻은 "MSA파일을 만들어야 할 GR2 파일들의 경로"를 가지고, 실제로 각각의 MSA파일들을 만들고 로그를 저장한다.
	for (TPathInfoList::iterator iter = pathInfoList.begin(); iter != pathInfoList.end(); ++iter)
	{
		const TPathInfoList::value_type& path = *iter;

		EResult resultCode = MakeMSA(path, &msg);

		// full path 찍히면 보기 좀 그래서 경로 줄임 -_-;
		fs::path parentPath = path.parent_path();
		std::string shortPath = parentPath.parent_path().filename() + "\\" + parentPath.filename() + "\\" + path.filename();;

		tm t;
		time_t timer;
		timer = time(NULL);
		localtime_s(&t, &timer);

		printf("%04d/%02d/%02d %02d:%02d:%02d [%s] %s\n", 
			t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec,			// 현재 시간
			msg.c_str(), shortPath.c_str());
	}

	CModelManager::Instance().Destroy();

	return 0;
}