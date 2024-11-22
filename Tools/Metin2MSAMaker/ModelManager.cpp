#include "stdafx.h"
#include "ModelManager.h"


CModel::CModel()
	: m_model(0), m_modelInstance(0), m_file(0), m_fileInfo(0)
{
}

CModel::~CModel()
{
	Destroy();
}

bool CModel::Load(const fs::path& path)
{
	BOOST_VERIFY(fs::is_regular_file(path));

	granny_file* m_file = GrannyReadEntireFile(path.string().c_str());
	granny_file_info* m_fileInfo = GrannyGetFileInfo(m_file);
	granny_file_info* info = m_fileInfo;

	BOOST_VERIFY(1 == info->ModelCount);

	m_model = info->Models[0];

	GrannyFreeFileSection(m_file, GrannyStandardRigidVertexSection);
	GrannyFreeFileSection(m_file, GrannyStandardRigidIndexSection);
	GrannyFreeFileSection(m_file, GrannyStandardDeformableIndexSection);
	GrannyFreeFileSection(m_file, GrannyStandardTextureSection);	

	return true;
}

void CModel::Destroy()
{
	if (m_file)
	{
		GrannyFreeFile(m_file);
		m_file = 0;
	}
}

bool CModel::IsGrannyFile(const fs::path& path)
{
	if (false == fs::is_regular_file(path))
		return false;

	std::string ext = boost::algorithm::to_lower_copy(path.extension());

	return ext == ".gr2";
}

bool CModel::IsGrannyModelFile(const fs::path& path)
{
	BOOST_VERIFY(fs::is_regular_file(path) && "File not found!");

	granny_file* file = GrannyReadEntireFile(path.string().c_str());
	BOOST_VERIFY(file && "Failed to open granny file");

	granny_file_info* info = GrannyGetFileInfo(file);
	BOOST_VERIFY(file && "Failed to read granny file info");

	const bool bResult = 0 < info->ModelCount;

	GrannyFreeFile(file);

	return bResult;
}

CModelManager::CModelManager()
{
}

CModelManager::~CModelManager()
{
	Destroy();
}

// 주어진 경로와 그 상위 경로에서 그래니 모델 파일을 찾오보고 있으면 등록한 후 찾은거 리턴
// depth가 1이면 상위 폴더까지 탐색, 늘어날수록 그 상위까지 찾음
CModel* CModelManager::AutoRegisterAndGetModel(const fs::path& initPath, int depth)
{
	fs::path curPath = initPath;

	while (depth--)
	{
		curPath = curPath.parent_path();

		for (fs::directory_iterator endIter, iter(curPath); iter != endIter; ++iter)
		{
			const fs::path& path = iter->path();

			if (CModel::IsGrannyFile(path) && CModel::IsGrannyModelFile(path))
			{
				return this->RegisterModel(path);
			}			
		}
	}

	return 0;
}

CModel* CModelManager::RegisterModel(const fs::path& path)
{	
	if (false == fs::is_regular_file(path))
		return 0;

	const std::string key = path.parent_path().string();

	CModel* model = GetModel(key);

	// 같은 key 로 등록된 게 있으면 그냥 무조건 true 리턴. 진짜 같은지 그런거 검사 안함여 귀찮
	if (0 != model)
		return model;
	
	model = new CModel();

	if (model->Load(path))
	{
		m_modelMap.insert(std::make_pair(key, model));
		return model;
	}

	delete model;

	return 0;
}

void CModelManager::Destroy()
{
	for (TModelCache::iterator iter = m_modelMap.begin(); iter != m_modelMap.end(); ++iter)
	{
		CModel* model = iter->second;

		model->Destroy();
		delete model;
	}

	m_modelMap.clear();

}

CModel* CModelManager::GetModel(const fs::path& path)
{
	const std::string key = path.parent_path().string();

	TModelCache::iterator iter = m_modelMap.find(key);

	if (m_modelMap.end() == iter)
		return 0;

	return iter->second;
}