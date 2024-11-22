#ifndef _EA_IO_H_
#define _EA_IO_H_

_EA_NAMESPACE_BEGIN

/// OpenFlags enum
enum EA_EOpenFlags
{
	modeRead	= (int) 0x00000,	///< Read access
	modeWrite	= (int) 0x00001,	///< Write access (append mode, create if it doesn't exist)
	//modeReadWrite =    (int) 0x00002,
	//shareCompat =      (int) 0x00000,
	//shareExclusive =   (int) 0x00010,
	//shareDenyWrite =   (int) 0x00020,
	//shareDenyRead =    (int) 0x00030,
	//shareDenyNone =    (int) 0x00040,
	//modeNoInherit =    (int) 0x00080,
	modeCreate	= (int) 0x01000,	///< Create access (truncate)
	modeAll		= (int) 0x01001,	///< Read and write access (similliar as modeWrite, but not starting end of file)
	//modeNoTruncate =   (int) 0x02000,
	//typeText =         (int) 0x04000,	///< typeText and typeBinary are
	//typeBinary =       (int) 0x08000,	///< used in derived classes only
	//osNoBuffer =       (int) 0x10000,
	//osWriteThrough =   (int) 0x20000,
	//osRandomAccess =   (int) 0x40000,
	//osSequentialScan = (int) 0x80000,
	modeRemove	= (int) 0x0FFFF,
};

/// SeekFlags enum
enum EA_ESeekFlags
{
	seekBegin	= 0,			///< Base position is the beginning of the file.
	seekCurrent	= 1,			///< Base position is the current of the file pointer.
	seekEnd		= 2			///< Base position is the end-of-file position.
};

/// SeekFlags enum
enum EA_EIOFlags
{
	ioMEMORY	= 0,
	ioHANDLE,
	ioFILENAME
};

_EA_NAMESPACE_END

#endif /* !_EA_IO_H_ */

