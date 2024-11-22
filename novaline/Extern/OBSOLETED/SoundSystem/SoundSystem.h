#pragma once

#if defined(EL_SS_DEVEL)
	#define EL_SS_API
#elif defined(EL_SS_STATIC)
    #define EL_SS_API
    #ifdef _DEBUG
        #pragma comment(lib, "soundsystem_sd.lib")
    #else
        #pragma comment(lib, "soundsystem_s.lib")
    #endif
#elif defined(EL_SS_EXPORT)
    #define EL_SS_API __declspec(dllexport)
#elif defined(EL_SS_IMPORT)
    #define EL_SS_API __declspec(dllimport)
    #ifdef EL_SS_DEBUG
        #pragma comment(lib, "soundsystem_d.lib")
    #else
        #pragma comment(lib, "soundsystem.lib")
    #endif
#else
    #define EL_SS_API
    #error  EL_SS_DEVEL, EL_SS_STATIC, EL_SS_EXPORT, EL_SS_IMPORT
#endif

EL_SS_API	void ELSS_InitRedistPathz(const char* redist_path);
EL_SS_API	bool ELSS_Startup();
EL_SS_API	void ELSS_Cleanup();
EL_SS_API	bool ELSS_OpenStream(const char* fileName);
EL_SS_API	void ELSS_CloseStream();
EL_SS_API	bool ELSS_PlayStreamOnce();
EL_SS_API	bool ELSS_PlayStreamLoop();
EL_SS_API	void ELSS_SetStreamOn();
EL_SS_API	void ELSS_SetStreamOff();
EL_SS_API	bool ELSS_IsStreamSet();

EL_SS_API	unsigned ELSS_OpenSample(const char* fileName);
EL_SS_API	void ELSS_CloseSample(unsigned handle);
EL_SS_API	bool ELSS_PlaySampleOnce(unsigned handle);
EL_SS_API	bool ELSS_PlaySampleOnce2d(unsigned handle, float vol, float pan);
EL_SS_API	void ELSS_CloseAllSamples();
EL_SS_API	void ELSS_SetSampleOn();
EL_SS_API	void ELSS_SetSampleOff();
EL_SS_API	bool ELSS_IsSampleSet();
