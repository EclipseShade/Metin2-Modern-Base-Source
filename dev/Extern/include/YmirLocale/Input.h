// EL_CInput.h - part if Multi-Language input class
//
// Copyright (C) 2000-2005, Kwon-il Lee
//
// Kwon-il Lee
// zupet@hitel.net

#ifndef _YMIRLOCALE_INPUT_H_
#define _YMIRLOCALE_INPUT_H_

#include "IME.h"

/*----------------------------------------------------------------------------*/ 
int GetCharsetFromLang(LANGID);
int	GetCodePageFromLang( LANGID langid );

/*----------------------------------------------------------------------------*/
class EL_CInput : public EL_IME
{
public:
	static EL_CInput& GetInstance()
	{
		static EL_CInput s_input;
		return s_input;
	}

	EL_CInput();
	virtual ~EL_CInput();

	virtual EL_AppTextInput*	GetFocus();
	virtual void	SetFocus(EL_AppTextInput* newAppTextInputPtr);

	void		Init(HWND hWnd);

	void		SetInputState(EL_AppTextInputState state);
	void		SetInputW(const std::wstring& input);
	
	int			GetInput(char* text, int maxLen);
	int			GetComp(char* text, int maxLen);
	
	int			GetReading(char* text, int maxLen);
	void		GetUnderLine(int* start, int* end);

	int			GetCandidate(DWORD index, char* text, int len);
	int			GetCandidateCount();
	int			GetCandidateSelection();
	int			GetCandidatePageSize();
	int			GetCandidatePageStart();	

	/* property */ 
	bool		IsVerticalReading(){ return m_bVerticalReading; }
	bool		IsVerticalCandidate(){ return m_bVerticalCandidate; }

	LANGID		GetLangId() { return m_langId; }
	int			GetCodePage() { return m_codePage; }	
	int			GetCharSet() { return GetCharsetFromLang(m_langId); }
	wchar_t*	GetIndicator() { return m_wszCurrIndicator; }

	EL_AppTextInputState GetInputState() { return m_context.inputState; }

	/* messages */ 	
	bool		WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam);

	void		OnInputLanguageChange(HWND hWnd, WPARAM wParam, LPARAM lParam);
	bool		OnComposition(HWND hWnd, WPARAM wParam, LPARAM lParam);
	bool		OnEndComposition(HWND hWnd, WPARAM wParam, LPARAM lParam);
	bool		OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam);
	bool		OnChar(HWND hWnd, WPARAM wParam, LPARAM lParam);
	bool		OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
	bool		OnKeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

	/* context */
	virtual void				ClearInput();
	virtual void				ClearComp();

	virtual const std::wstring&	GetInputW();
	virtual const std::wstring&	GetCompW();
	virtual const std::wstring&	GetReadingW();



protected:
	void		SetupImeApi(HWND hWnd);
	void		GetImeId();
	bool		GetReadingWindowOrientation();
	void		GetPrivateReadingString(HWND hWnd);
	void		CheckToggleState(HWND hWnd);

	void		Invalidate();

protected:
	EL_AppTextInputContext	m_context;
	
	std::wstring		m_reading;
	std::vector<BYTE>	m_candidate;

	int					m_ulStart;
	int					m_ulEnd;
	
	HWND				m_hWnd;
	HKL					m_hkl;
	LANGID				m_langId;
	WORD				m_codePage;

	bool				m_bUnicodeIME;
	bool				m_bVerticalReading;
	bool				m_bVerticalCandidate;

	wchar_t*			m_wszCurrIndicator;

	DWORD				m_dwId[2];

	HINSTANCE			m_hDllIme;

	UINT				(WINAPI * _GetReadingString)( HIMC, UINT, LPWSTR, PINT, BOOL*, PUINT );
	BOOL				(WINAPI * _ShowReadingWindow)( HIMC, BOOL );

	EL_AppTextInput*			m_handlerPtr;
};

#endif /* _YMIRLOCALE_INPUT_H_ */
