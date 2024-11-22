////////////////////////////////////////////////////////////////////////////////
/// \file MiniDump.h
/// \author excel96
/// \date 2003.11.18
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef _WINDOWS_
    #include <windows.h>
#endif

////////////////////////////////////////////////////////////////////////////////
/// \class cMiniDump
/// \brief 미니 덤프를 실행하기 위한 클래스. 특별히 어떤 당위성이 있어서 만든 
/// 클래스는 아니고, 정적 변수와 함수를 가지고 있기 위해 만든 네임 스페이스 
/// 역할 클래스이다. 
///
/// 덤프의 초기화는 Install 함수를 통해 이루어진다. 프로그램 시작 부분 아무 
/// 곳에서나 cMiniDump::Install(...) 함수를 호출해주면 된다. 
///
/// <pre>
/// int main()
/// {
///     ...
///     cMiniDump::Install(cMiniDump::DUMP_LEVEL_LIGHT);
///     ...
/// }
/// </pre>
///
/// GUI를 사용할 수 있는 프로그램의 경우, 사용자에게 덤프 파일 생성 여부를 묻는
/// 것도 괜찮다고 생각해서, 대화창 콜백 함수를 하나 집어 넣었다. Install 함수를 
/// 통해 대화창 콜백 함수를 설정하면, 덤프 생성시 이를 확인해 먼저 대화창을 
/// 띄운다. 대화창이 IDOK로 끝나면, 덤프 파일을 생성하고, 그외의 값으로 끝나면 
/// 덤프 파일을 생성하지 않는다. 기본적인 대화창 함수를 구현하자면 대충 아래와 
/// 같을 것이다.
///
/// <pre>
/// BOOL CALLBACK CrashDialogProc(
///     HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM /*lParam*/)
/// {
///     RECT parent, dlg;
///     int x, y;
/// 
///     switch (iMessage)
///     {
///     case WM_INITDIALOG:
///         ::GetWindowRect(::GetForegroundWindow(), &parent);
///         ::GetWindowRect(hDlg, &dlg);
///         x = (parent.left + parent.right - dlg.right) / 2;
///         y = (parent.top + parent.bottom - dlg.bottom) / 2;
///         ::MoveWindow(hDlg, x, y, dlg.right, dlg.bottom, FALSE);
//          ...
///         return TRUE;
///     case WM_COMMAND:
///         switch (LOWORD(wParam))
///         {
///         case IDOK: EndDialog(hDlg, IDOK); break;
///         case IDCANCEL: EndDialog(hDlg, IDCANCEL); break;
///         default: break;
///         }
///         return FALSE;
///     default:
///         break;
///     }
/// 
///     return FALSE;
/// }
/// </pre>
////////////////////////////////////////////////////////////////////////////////

class MiniDump
{
public:
    /// 덤프할 데이터의 수준
    enum DumpLevel
    {
        DUMP_LEVEL_LIGHT = 1,  ///< MiniDumpNormal을 사용
        DUMP_LEVEL_MEDIUM, ///< MiniDumpWithDataSegs를 사용
        DUMP_LEVEL_HEAVY   ///< MiniDumpWithFullMemory를 사용
    };

private:
	enum
	{
		BUFFER_MAX = 32 * 1024,
	};

	typedef EL_VOID (*SEND_REPORT_PROC)();

    static DumpLevel s_DumpLevel;          ///< 덤프 레벨.
    static bool      s_AddTimeStamp;       ///< 날짜 기반 덤프 파일 이름 사용
    static TCHAR     s_AppName[_MAX_PATH]; ///< 덤프 파일 이름
    static TCHAR     s_CallStack[BUFFER_MAX];    ///< 콜스택 문자열
    static TCHAR     s_Modules[BUFFER_MAX];      ///< 모듈 문자열
    static LPCTSTR   s_DialogTemplate;     ///< 대화창 템플릿
    static DLGPROC   s_DialogProc;         ///< 대화창 프로시져
	static SEND_REPORT_PROC s_SendReportProc;

public:
    /// \brief 미니 덤프 기능을 초기화한다.
    static void Install(DumpLevel dumpLevel, bool addTimestamp=true, LPCTSTR dialogTemplate=NULL, DLGPROC dialogProc=NULL, SEND_REPORT_PROC SendReportProc=NULL);

    /// \brief 콜스택 문자열을 반환한다.
    static LPCTSTR GetCallStack() { return s_CallStack; }

    /// \brief 모듈 문자열을 반환한다.
    static LPCTSTR GetModules() { return s_Modules; }

	/// \brief 예외에 대한 정보를 받아서, 미니 덤프 파일을 생성한다. 
    static LONG WINAPI WriteDump(PEXCEPTION_POINTERS exPtrs);

	static bool IsDataSectionNeeded(PWCHAR pModuleName);

private:
    /// \brief 생성 금지
    MiniDump() {}

    /// \brief 복사 생성 금지
    MiniDump(const MiniDump&);

    /// \brief 대입 연산 금지
	MiniDump& operator = (const MiniDump&);

	static void GetCallStackOfAllThread(PEXCEPTION_POINTERS exPtrs);
};

