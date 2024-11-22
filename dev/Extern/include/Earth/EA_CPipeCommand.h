/**
 * @file	EA_CPipeCommand.h
 * @brief	Process pipes class
 * @author	Standil (cpascal@cpascal.net)
 *
 * @version	2006/01/19 cpascal - First release
 */

#ifndef _EA_CPIPECOMMAND_H_
#define _EA_CPIPECOMMAND_H_

#if defined(_NTR_WINDOWS_INTEL)

_EA_NAMESPACE_BEGIN

class EA_CPipeCommand
{
public:
	enum PipeType {
		PIPE_STDIN	= 0x01,	///< stdin.
		PIPE_STDOUT	= 0x02,	///< stdout.
		PIPE_STDERR	= 0x04,	///< stderr.
		PIPE_ALL	= 0x07
	};
	enum ProcessCreationFlags {
		OPEN_STDIN	= 0x01,	///< Do open child's stdin.
		OPEN_STDOUT	= 0x02,	///< Do open child's stdout.
		OPEN_STDERR	= 0x04,	///< Do open child's stderr.
	};

public:
	EA_CPipeCommand( void );
	EA_CPipeCommand( MA_LPCTSTR szCommand, MA_LPCTSTR szDirectory = EA_NULL, ProcessCreationFlags eFlags = OPEN_STDOUT );

	~EA_CPipeCommand( void );

	EA_BOOL Open( MA_LPCTSTR szCommand, MA_LPCTSTR szDirectory = EA_NULL, ProcessCreationFlags eFlags = OPEN_STDOUT );
	void	Close( void );
	EA_BOOL	ClosePipe( PipeType eType );
	EA_BOOL	WaitExit( int *pnExitCode );
	EA_BOOL IsActive( void );

	EA_BOOL	Read( EA_LPBYTE lpBuffer, EA_SIZE sizeBuffer, EA_SIZE* psizeRead, int nPipeTypes = 0 );
	EA_BOOL	Write( EA_LPBYTE lpBuffer, EA_SIZE sizeBuffer, EA_SIZE* psizeWritten );

protected:
	HANDLE m_hChildProcess;
	HANDLE m_hChildThread;

	HANDLE m_hChildStdinRead;
	HANDLE m_hChildStdinWrite;
	HANDLE m_hChildStdoutRead;
	HANDLE m_hChildStdoutWrite;

private:
	/// Disable copy constructor and assignment.
	EA_CPipeCommand( const EA_CPipeCommand& );
	EA_CPipeCommand& operator= ( const EA_CPipeCommand& );
};

_EA_NAMESPACE_END

#endif /* _NTR_WINDOWS_INTEL */

#endif /* !_EA_CPIPECOMMAND_H_ */
