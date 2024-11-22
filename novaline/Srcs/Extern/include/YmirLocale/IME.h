#ifndef _YMIRLOCALE_IME_H_
#define _YMIRLOCALE_IME_H_

enum EL_AppTextInputState
{ 
	APP_TEXT_INPUT_STATE_OFF, 
	APP_TEXT_INPUT_STATE_ON, 
	APP_TEXT_INPUT_STATE_ENGLISH,
};

struct EL_AppTextInputContext
{
	std::wstring input;
	std::wstring comp;

	EL_AppTextInputState inputState;
};

class EL_AppTextInput
{
public:
	virtual ~EL_AppTextInput() {}

	virtual bool IsFull(const wchar_t* newCharPtr, int newCharLen) = 0;

	virtual void Twinkle() = 0;
	virtual void Invalidate(const EL_AppTextInputContext& context) = 0;		

	virtual void LeaveFocus(const EL_AppTextInputContext& context) = 0;	

	virtual void KeyReturn(const EL_AppTextInputContext& context) = 0;
	virtual void KeyTabPrev(const EL_AppTextInputContext& context) = 0;
	virtual void KeyTabNext(const EL_AppTextInputContext& context) = 0;

	virtual const EL_AppTextInputContext&	GetContext() = 0;
};

class EL_IME
{
public:
	static	EL_IME& GetIME();
	
	virtual ~EL_IME() {}

	virtual EL_AppTextInput* GetFocus() = 0;
	virtual void	SetFocus(EL_AppTextInput* newHandlerPtr) = 0;

	virtual void	SetInputState(EL_AppTextInputState state) = 0;
	virtual void	SetInputW(const std::wstring& input) = 0;
	
	virtual int		GetInput(char* text, int maxLen) = 0;
	virtual int		GetComp(char* text, int maxLen) = 0;	
	virtual int		GetReading(char* text, int maxLen) = 0;

	virtual void	GetUnderLine(int* start, int* end) = 0;	

	virtual bool	IsVerticalReading() = 0;
	virtual bool	IsVerticalCandidate() = 0;

	virtual EL_AppTextInputState GetInputState() = 0;

	virtual int			GetCharSet() = 0;
	virtual int			GetCodePage() = 0;
	virtual LANGID		GetLangId() = 0;	
	virtual wchar_t*	GetIndicator() = 0;	

	virtual void				ClearInput() = 0;
	virtual void				ClearComp() = 0;
	
	virtual const std::wstring&	GetInputW() = 0;
	virtual const std::wstring&	GetCompW() = 0;
	virtual const std::wstring&	GetReadingW() = 0;
};

#endif /* !_YMIRLOCALE_IME_H_ */
