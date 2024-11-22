#ifndef	_MA_PATH_H_
#define	_MA_PATH_H_

_NTR_EXTERN_C_BEGIN

#if !defined( MA_DEFAULT_PATH_DELIMITERA ) || !defined( MA_DEFAULT_PATH_DELIMITERW )
#define	MA_DEFAULT_PATH_DELIMITERA			'\\'
#define	MA_DEFAULT_PATH_DELIMITERW			L'\\'
#endif

#if defined( _NTR_UNICODE )
	#define	MA_PathSplitFileName					MA_PathSplitFileNameW
	#define	MA_PathSplit							MA_PathSplitW
	#define	MA_PathSplitDrivePath					MA_PathSplitDrivePathW
	#define	MA_PathSplitPathEvenExtension			MA_PathSplitPathEvenExtensionW
	#define	MA_PathSplitDrivePathEvenExtension		MA_PathSplitDrivePathEvenExtensionW
	#define	MA_PathMergeFileName					MA_PathMergeFileNameW
	#define	MA_PathAppendExtension					MA_PathAppendExtensionW
	#define	MA_PathMerge							MA_PathMergeW
	#define	MA_PathMergeEvenExtension				MA_PathMergeEvenExtensionW
	#define	MA_PathMergeSmart					MA_PathMergeSmartW
	#define	MA_PathCompare							MA_PathCompareW
	#define	MA_PathCompareCI						MA_PathCompareCIW
	#define MA_PathAppendAsterisk					MA_PathAppendAsteriskW
	#define MA_PathAppendAsteriskWithSubdirectory	MA_PathAppendAsteriskWithSubdirectoryW
	#define	MA_PathMatchFileName					MA_PathMatchFileNameW
	#define	MA_PathIsRelativeDirectory				MA_PathIsRelativeDirectoryW
	#define	MA_PathIsRelative						MA_PathIsRelativeW
	#define	MA_PathMakeRelative						MA_PathMakeRelativeW
	#define	MA_PathMakeAbsolute						MA_PathMakeAbsoluteW
	#define	MA_PathIsUNC							MA_PathIsUNCW
	#define	MA_PathSplitUNC							MA_PathSplitUNCW
	#define MA_PathRemoveSlashDotSlash				MA_PathRemoveSlashDotSlashW
	#define MA_PathRemoveDotDots					MA_PathRemoveDotDotsW
	#define MA_PathStandardizeWindows				MA_PathStandardizeWindowsW
	#define MA_PathStandardizeUnix					MA_PathStandardizeUnixW
	#define MA_PathStandardizeURI					MA_PathStandardizeURIW
#elif	defined( _NTR_UTF8 )
	#define	MA_PathSplitFileName					MA_PathSplitFileNameE
	#define	MA_PathSplit							MA_PathSplitE
	#define	MA_PathSplitDrivePath					MA_PathSplitDrivePathE
	#define	MA_PathSplitPathEvenExtension			MA_PathSplitPathEvenExtensionE
	#define	MA_PathSplitDrivePathEvenExtension		MA_PathSplitDrivePathEvenExtensionE
	#define	MA_PathMergeFileName					MA_PathMergeFileNameE
	#define	MA_PathAppendExtension					MA_PathAppendExtensionE
	#define	MA_PathMerge							MA_PathMergeE
	#define	MA_PathMergeEvenExtension				MA_PathMergeEvenExtensionE
	#define	MA_PathMergeSmart					MA_PathMergeSmartE
	#define	MA_PathCompare							MA_PathCompareE
	#define	MA_PathCompareCI						MA_PathCompareCIE
	#define MA_PathAppendAsterisk					MA_PathAppendAsteriskE
	#define MA_PathAppendAsteriskWithSubdirectory	MA_PathAppendAsteriskWithSubdirectoryE
	#define	MA_PathMatchFileName					MA_PathMatchFileNameE
	#define	MA_PathIsRelativeDirectory				MA_PathIsRelativeDirectoryE
	#define	MA_PathIsRelative						MA_PathIsRelativeE
	#define	MA_PathMakeRelative						MA_PathMakeRelativeE
	#define	MA_PathMakeAbsolute						MA_PathMakeAbsoluteE
	#define	MA_PathIsUNC							MA_PathIsUNCE
	#define	MA_PathSplitUNC							MA_PathSplitUNCE
	#define MA_PathRemoveSlashDotSlash				MA_PathRemoveSlashDotSlashE
	#define MA_PathRemoveDotDots					MA_PathRemoveDotDotsE
	#define MA_PathStandardizeWindows				MA_PathStandardizeWindowsE
	#define MA_PathStandardizeUnix					MA_PathStandardizeUnixE
	#define MA_PathStandardizeURI					MA_PathStandardizeURIE
#else
	#define	MA_PathSplitFileName					MA_PathSplitFileNameA
	#define	MA_PathSplit							MA_PathSplitA
	#define	MA_PathSplitDrivePath					MA_PathSplitDrivePathA
	#define	MA_PathSplitPathEvenExtension			MA_PathSplitPathEvenExtensionA
	#define	MA_PathSplitDrivePathEvenExtension		MA_PathSplitDrivePathEvenExtensionA
	#define	MA_PathMergeFileName					MA_PathMergeFileNameA
	#define	MA_PathAppendExtension					MA_PathAppendExtensionA
	#define	MA_PathMerge							MA_PathMergeA
	#define	MA_PathMergeEvenExtension				MA_PathMergeEvenExtensionA
	#define	MA_PathMergeSmart					MA_PathMergeSmartA
	#define	MA_PathCompare							MA_PathCompareA
	#define	MA_PathCompareCI						MA_PathCompareCIA
	#define MA_PathAppendAsterisk					MA_PathAppendAsteriskA
	#define MA_PathAppendAsteriskWithSubdirectory	MA_PathAppendAsteriskWithSubdirectoryA
	#define	MA_PathMatchFileName					MA_PathMatchFileNameA
	#define	MA_PathIsRelativeDirectory				MA_PathIsRelativeDirectoryA
	#define	MA_PathIsRelative						MA_PathIsRelativeA
	#define	MA_PathMakeRelative						MA_PathMakeRelativeA
	#define	MA_PathMakeAbsolute						MA_PathMakeAbsoluteA
	#define	MA_PathIsUNC							MA_PathIsUNCA
	#define	MA_PathSplitUNC							MA_PathSplitUNCA
	#define MA_PathRemoveSlashDotSlash				MA_PathRemoveSlashDotSlashA
	#define MA_PathRemoveDotDots					MA_PathRemoveDotDotsA
	#define MA_PathStandardizeWindows				MA_PathStandardizeWindowsA
	#define MA_PathStandardizeUnix					MA_PathStandardizeUnixA
	#define MA_PathStandardizeURI					MA_PathStandardizeURIA
#endif

#if defined( _NTR_WINDOWS )
	#define MA_PathStandardize					MA_PathStandardizeWindows
	#define MA_PathStandardizeA					MA_PathStandardizeWindowsA
	#define MA_PathStandardizeW					MA_PathStandardizeWindowsW
	#define MA_PathStandardizeE					MA_PathStandardizeWindowsE
#else
	#define MA_PathStandardize					MA_PathStandardizeUnix
	#define MA_PathStandardizeA					MA_PathStandardizeUnixA
	#define MA_PathStandardizeW					MA_PathStandardizeUnixW
	#define MA_PathStandardizeE					MA_PathStandardizeUnixE
#endif

/*
 * Function: MA_PathSplitFileName
 * Break a file name into components.
 *
 * Parameters:
 *	szSourceFileName [in]	- Null-terminated full path string.
 *	szFileName [out]		- Optional. Buffer of filename to save.
 *	sizeFileName [in]		- The size of szFileName in single-byte or wide characters.
 *	szExtension [out]		- Optional. Buffer of extension to save.
 *	sizeExtension [in]		- The size of szExtension in single-byte or wide characters.
 *
 * Returns:
 *  MA_TRUE					- Successful.
 *	MA_FALSE				- szSourceFileName is NULL or szFileName and szExtension is NULL
 */
MA_BOOL 	MA_PathSplitFileNameA( MA_PCSTR szSourceFileName, MA_PSTR szFileName, MA_SIZE sizeFileName, MA_PSTR szExtension, MA_SIZE sizeExtension );
MA_BOOL		MA_PathSplitFileNameW( MA_PCWSTR szSourceFileName, MA_PWSTR szFileName, MA_SIZE sizeFileName, MA_PWSTR szExtension, MA_SIZE sizeExtension );
MA_BOOL		MA_PathSplitFileNameE( MA_PCESTR szSourceFileName, MA_PESTR szFileName, MA_SIZE sizeFileName, MA_PESTR szExtension, MA_SIZE sizeExtension );

/*
 * Function: MA_PathSplit
 * Break a path name into components.
 *
 * Parameters:
 *	szSourceFileName [in]	- Null-terminated full path string.
 *	szDrive [out]			- Optional drive letter, followed by colon(:)
 *	sizeDrive [in]			- The size of the szDrive in single-byte or wide characters.
 *	szDirectory [out]		- Optional. Buffer of directory to save.
 *	sizeDirectory [in]		- The size of szDirectory in single-byte or wide characters.
 *	szLeaf [out]			- Optional. Buffer of last element to save.
 *	sizeLeaf [in]			- The size of szLeaf in single-byte or wide characters.
 *	szFileName [out]		- Optional. Buffer of filename to save(has extension).
 *	sizeFileName [in]		- The size of szFileName in single-byte or wide characters.
 *
 * Returns:
 *  MA_TRUE					- Successful.
 *	MA_FALSE				- szSourceFileName is NULL or szFileName and szExtension is NULL
 */
MA_BOOL		MA_PathSplitA( MA_PCSTR szSourcePath, MA_PSTR szDirectory, MA_SIZE sizeDirectory, MA_PSTR szLeaf, MA_SIZE sizeLeaf );
MA_BOOL		MA_PathSplitW( MA_PCWSTR szSourcePath, MA_PWSTR szDirectory, MA_SIZE sizeDirectory, MA_PWSTR szLeaf, MA_SIZE sizeLeaf );
MA_BOOL		MA_PathSplitE( MA_PCESTR szSourcePath, MA_PESTR szDirectory, MA_SIZE sizeDirectory, MA_PESTR szLeaf, MA_SIZE sizeLeaf );
MA_BOOL		MA_PathSplitDrivePathA( MA_PCSTR szSourcePath, MA_PSTR szDrive, MA_SIZE sizeDrive, MA_PSTR szDirectory, MA_SIZE sizeDirectory, MA_PSTR szFileName, MA_SIZE sizeFileName );
MA_BOOL		MA_PathSplitDrivePathW( MA_PCWSTR szSourcePath, MA_PWSTR szDrive, MA_SIZE sizeDrive, MA_PWSTR szDirectory, MA_SIZE sizeDirectory, MA_PWSTR szFileName, MA_SIZE sizeFileName );
MA_BOOL		MA_PathSplitDrivePathE( MA_PCESTR szSourcePath, MA_PESTR szDrive, MA_SIZE sizeDrive, MA_PESTR szDirectory, MA_SIZE sizeDirectory, MA_PESTR szFileName, MA_SIZE sizeFileName );

/*
 * Function: MA_PathSplitPathEvenExtension
 * Break a path name into components.
 *
 * Parameters:
 *	szSourceFileName [in]		- Null-terminated full path string.
 *	szDrive [out]			- Optional. Drive letter, followed by colon(:)
 *	sizeDrive [in]			- The size of the szDrive in single-byte or wide characters.
 *	szDirectory [out]		- Optional. Buffer of directory to save.
 *	sizeDirectory [in]		- The size of szDirectory in single-byte or wide characters.
 *	szLeaf [out]			- Optional. Buffer of last element to save.
 *	sizeLeaf [in]			- The size of szLeaf in single-byte or wide characters.
 *	szFileName [out]		- Optional. Buffer of filename to save(has extension).
 *	sizeFileName [in]		- The size of szFileName in single-byte or wide characters.
 *	szExtension [out]		- Optional. Buffer of extension to save.
 *	sizeExtension [in]		- The size of szExtension in single-byte or wide characters.
 *
 * Returns:
 *  MA_TRUE					- Successful.
 *	MA_FALSE				- szSourceFileName is NULL or szFileName and szExtension is NULL
 */
MA_BOOL		MA_PathSplitPathEvenExtensionA( MA_PCSTR szSourcePath, MA_PSTR szDirectory, MA_SIZE sizeDirectory, MA_PSTR szFileName, MA_SIZE sizeFileName, MA_PSTR szExtension, MA_SIZE sizeExtension );
MA_BOOL		MA_PathSplitPathEvenExtensionW( MA_PCWSTR szSourcePath, MA_PWSTR szDirectory, MA_SIZE sizeDirectory, MA_PWSTR szFileName, MA_SIZE sizeFileName, MA_PWSTR szExtension, MA_SIZE sizeExtension );
MA_BOOL		MA_PathSplitPathEvenExtensionE( MA_PCESTR szSourcePath, MA_PESTR szDirectory, MA_SIZE sizeDirectory, MA_PESTR szFileName, MA_SIZE sizeFileName, MA_PESTR szExtension, MA_SIZE sizeExtension );
MA_BOOL		MA_PathSplitDrivePathEvenExtensionA( MA_PCSTR szSourcePath, MA_PSTR szDrive, MA_SIZE sizeDrive, MA_PSTR szDirectory, MA_SIZE sizeDirectory, MA_PSTR szFileName, MA_SIZE sizeFileName, MA_PSTR szExtension, MA_SIZE sizeExtension );
MA_BOOL		MA_PathSplitDrivePathEvenExtensionW( MA_PCWSTR szSourcePath, MA_PWSTR szDrive, MA_SIZE sizeDrive, MA_PWSTR szDirectory, MA_SIZE sizeDirectory, MA_PWSTR szFileName, MA_SIZE sizeFileName, MA_PWSTR szExtension, MA_SIZE sizeExtension );
MA_BOOL		MA_PathSplitDrivePathEvenExtensionE( MA_PCESTR szSourcePath, MA_PESTR szDrive, MA_SIZE sizeDrive, MA_PESTR szDirectory, MA_SIZE sizeDirectory, MA_PESTR szFileName, MA_SIZE sizeFileName, MA_PESTR szExtension, MA_SIZE sizeExtension );

/*
 * Function: MA_PathMergeFileName
 * Create a file name from components.
 *
 * Parameters:
 *	szDestination [out]		- Full path buffer.
 *	sizeDestination [in]	- The size of szDestination in single-byte or wide characters.
 *	szFileName [in]			- Optional. Null-terminated filename string.
 *	szExtension [in]		- Optional. Null-terminated extension string.
 *
 * Returns:
 *  MA_TRUE					- Successful.
 *  MA_FALSE				- szDestination is NULL or all other string is NULL.
 */
MA_BOOL		MA_PathMergeFileNameA( MA_PSTR szDestination, MA_SIZE sizeDestination, MA_PCSTR szFileName, MA_PCSTR szExtension );
MA_BOOL		MA_PathMergeFileNameW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szFileName, MA_PCWSTR szExtension );
MA_BOOL		MA_PathMergeFileNameE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szFileName, MA_PCESTR szExtension );

/*
 * Function: MA_PathAppendExtension
 * Appends a extension to an existing null-terminated path.
 *
 * Parameters:
 *	szDestination [out]		- Full path buffer.
 *	sizeDestination [in]	- The size of szDestination in single-byte or wide characters.
 *	szExtension [in]		- Optional. Null-terminated extension string.
 *
 * Returns:
 *  MA_TRUE					- Successful.
 *  MA_FALSE				- szDestination is NULL or szExtension is NULL
 */
MA_BOOL		MA_PathAppendExtensionA( MA_PSTR szDestination, MA_SIZE sizeDestination, MA_PCSTR szExtension );
MA_BOOL		MA_PathAppendExtensionW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szExtension );
MA_BOOL		MA_PathAppendExtensionE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szExtension );

/*
 * Function: MA_PathAppendExtension
 * Create a path name from components.
 *
 * Parameters:
 *	szDestination [out]		- Full path buffer.
 *	sizeDestination [in]	- The size of szDestination in single-byte or wide characters.
 *	szDirectory [in]		- Optional. Null-terminated directory string.
 *	szLeaf [in]				- Optional. Null-terminated last element string.
 *	szExtension [in]		- Optional. Null-terminated extension string.
 *	szDrive [in]			- Optional. Null-terminated drive string.
 *	szFileName [in]			- Optional. Null-terminated filename string.
 */
MA_BOOL		MA_PathMergeA( MA_PSTR szDestination, MA_SIZE sizeDestination, MA_PCSTR szDirectory, MA_PCSTR szLeaf );
MA_BOOL		MA_PathMergeW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szDirectory, MA_PCWSTR szLeaf );
MA_BOOL		MA_PathMergeE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szDirectory, MA_PCESTR szLeaf );
MA_BOOL		MA_PathMergeSmartA( MA_PSTR szDestination, MA_SIZE sizeDestination, MA_PCSTR szDirectory, MA_PCSTR szLeaf );
MA_BOOL		MA_PathMergeSmartW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szDirectory, MA_PCWSTR szLeaf );
MA_BOOL		MA_PathMergeSmartE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szDirectory, MA_PCESTR szLeaf );

/*
 * Function: MA_PathAppendExtension
 * Create a path name from components.
 *
 * Parameters:
 *	szDestination [out]		- Full path buffer.
 *	sizeDestination [in]		- The size of szDestination in single-byte or wide characters.
 *	szDirectory [in]		- Optional. Null-terminated directory string.
 *	szLeaf [in]			- Optional. Null-terminated last element string.
 *	szExtension [in]		- Optional. Null-terminated extension string.
 *	szDrive [in]			- Optional. Null-terminated drive string.
 *	szFileName [in]			- Optional. Null-terminated filename string.
 *	szExtension [in]		- Optional. Null-terminated extension string.
 */
MA_BOOL		MA_PathMergeEvenExtensionA( MA_PSTR szDestination, MA_SIZE sizeDestination, MA_PCSTR szDirectory, MA_PCSTR szFileName, MA_PCSTR szExtension );
MA_BOOL		MA_PathMergeEvenExtensionW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szDirectory, MA_PCWSTR szFileName, MA_PCWSTR szExtension );
MA_BOOL		MA_PathMergeEvenExtensionE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szDirectory, MA_PCESTR szFileName, MA_PCESTR szExtension );
//MA_BOOL		MA_PathMergeEvenExtensionA( MA_PSTR szDestination, MA_SIZE sizeDestination, MA_PCSTR szDrive, MA_PCSTR szDirectory, MA_PCSTR szFileName, MA_PCSTR szExtension );
//MA_BOOL		MA_PathMergeEvenExtensionW( MA_PWSTR szDestination, MA_SIZE sizeDestination, MA_PCWSTR szDrive, MA_PCWSTR szDirectory, MA_PCWSTR szFileName, MA_PCWSTR szExtension );
//MA_BOOL		MA_PathMergeEvenExtensionE( MA_PESTR szDestination, MA_SIZE sizeDestination, MA_PCESTR szDrive, MA_PCESTR szDirectory, MA_PCESTR szFileName, MA_PCESTR szExtension );

/*
 * Function: MA_PathCompare
 * Compares two pathes (case sensitive).
 *
 * Parameters:
 *	szDestination [in]		- Null-terminated path to compare. 
 *	szSource [in]			- Null-terminated path to compare. 
 *	nCompareLength [in]		- Number of characters to compare.
 *
 * Returns:
 *	The return value indicates the relation of the substrings of szDestination and szSource as follows.
 *
 *	return < 0	- szDestination substring less than szSource substring
 *	return = 0	- szDestination substring identical to szSource substring 
 *	return > 0	- szDestination substring greater than szSource substring 
 */
MA_XINT		MA_PathCompareA( MA_PCASTR szDestination, MA_PCSTR szSource, MA_SIZE nCompareLength );
MA_XINT		MA_PathCompareW( MA_PCWSTR szDestination, MA_PCWSTR szSource, MA_SIZE nCompareLength );
MA_XINT		MA_PathCompareE( MA_PCESTR szDestination, MA_PCESTR szSource, MA_SIZE nCompareLength );


MA_BOOL		MA_PathAppendAsteriskA( MA_PASTR IN szPath, MA_SIZE sizePath, MA_PCASTR IN szDirentName );
MA_BOOL		MA_PathAppendAsteriskW( MA_PWSTR IN szPath, MA_SIZE sizePath, MA_PCWSTR IN szDirentName );
MA_BOOL		MA_PathAppendAsteriskE( MA_PESTR IN szPath, MA_SIZE sizePath, MA_PCESTR IN szDirentName );


MA_BOOL		MA_PathAppendAsteriskWithSubdirectoryA( MA_LPASTR OUT szPath, MA_SIZE IN sizePath, MA_LPCASTR IN tszDirentName, MA_LPCASTR IN tszSubDirent, MA_SIZE IN sizeSubDirent );
MA_BOOL		MA_PathAppendAsteriskWithSubdirectoryW( MA_LPWSTR OUT szPath, MA_SIZE IN sizePath, MA_LPCWSTR IN tszDirentName, MA_LPCWSTR IN tszSubDirent, MA_SIZE IN sizeSubDirent );
MA_BOOL		MA_PathAppendAsteriskWithSubdirectoryE( MA_LPESTR OUT szPath, MA_SIZE IN sizePath, MA_LPCESTR IN tszDirentName, MA_LPCESTR IN tszSubDirent, MA_SIZE IN sizeSubDirent );

/*
 * Function: MA_PathCompareCI
 * Compares two pathes (case sensitive).
 *
 * Parameters:
 *	szDestination [in]		- Null-terminated path to compare. 
 *	szSource [in]			- Null-terminated path to compare. 
 *	nCompareLength [in]		- Number of characters to compare.
 *
 * Returns:
 *	The return value indicates the relation of the substrings of szDestination and szSource as follows.
 *
 *	return < 0	- szDestination substring less than szSource substring
 *	return = 0	- szDestination substring identical to szSource substring 
 *	return > 0	- szDestination substring greater than szSource substring 
 */
MA_XINT		MA_PathCompareCIA( MA_PCSTR szDestination, MA_PCSTR szSource, MA_SIZE nCompareLength );
MA_XINT		MA_PathCompareCIW( MA_PCWSTR szDestination, MA_PCWSTR szSource, MA_SIZE nCompareLength );
MA_XINT		MA_PathCompareCIE( MA_PCESTR szDestination, MA_PCESTR szSource, MA_SIZE nCompareLength );

#define	MA_FNM_NOESCAPE		0x01	/* Disable backslash escaping. */
#define	MA_FNM_PATHNAME		0x02	/* Slash must be matched by slash. */
#define MA_FNM_FILE_NAME	0x02
#define	MA_FNM_PERIOD		0x04	/* Period must be matched by period. */
#define	MA_FNM_LEADING_DIR	0x08	/* Ignore /<tail> after Imatch. */
#define	MA_FNM_CASEFOLD		0x10	/* Case insensitive search. */
#define	MA_FNM_IGNORECASE	MA_FNM_CASEFOLD

/*
 * Function: MA_PathMatchFileName
 * Searches the specified input string for an occurrence of the simple pattern parameter.
 * using pattern
 *
 * Parameters:
 *	szPattern [in]			- Null-terminated string to search for a match.
 *	szFileName [in]			- Null-terminated pattern to match.
 *	bCaseSenstive [in]		- Boolean of case sensitive or case insensitive.
 */
MA_BOOL	 	MA_PathMatchFileNameA( MA_PCSTR IN szPattern, MA_PCSTR IN szFileName, MA_XUINT dwFlags );
MA_BOOL		MA_PathMatchFileNameW( MA_PCWSTR IN szPattern, MA_PCWSTR IN szFileName, MA_XUINT dwFlags );
MA_BOOL		MA_PathMatchFileNameE( MA_PCESTR IN szPattern, MA_PCESTR IN szFileName, MA_XUINT dwFlags );

MA_BOOL		MA_PathIsRelativeDirectoryA( MA_PCASTR IN szPath );
MA_BOOL		MA_PathIsRelativeDirectoryW( MA_PCWSTR IN szPath );
MA_BOOL		MA_PathIsRelativeDirectoryE( MA_PCESTR IN szPath );

MA_BOOL		MA_PathIsRelativeA( MA_PCASTR IN szPath );
MA_BOOL		MA_PathIsRelativeW( MA_PCWSTR IN szPath );
MA_BOOL		MA_PathIsRelativeE( MA_PCESTR IN szPath );

// --------------------------------------------
// Absolute / Relative
// --------------------------------------------
MA_BOOL		MA_PathMakeRelativeA( MA_PASTR OUT szRelativePath, MA_SIZE IN sizePath, MA_PCASTR IN szStartPath, MA_PCASTR IN szSourcePath );
MA_BOOL		MA_PathMakeRelativeW( MA_PWSTR OUT szRelativePath, MA_SIZE IN sizePath, MA_PCWSTR IN szStartPath, MA_PCWSTR IN szSourcePath );
MA_BOOL		MA_PathMakeRelativeE( MA_PESTR OUT szRelativePath, MA_SIZE IN sizePath, MA_PCESTR IN szStartPath, MA_PCESTR IN szSourcePath );

MA_BOOL		MA_PathMakeAbsoluteA( MA_PASTR OUT szAbsolutePath, MA_SIZE IN sizePath, MA_PCASTR IN szStartFolder, MA_PCASTR IN szSourcePath );
MA_BOOL		MA_PathMakeAbsoluteW( MA_PWSTR OUT szAbsolutePath, MA_SIZE IN sizePath, MA_PCWSTR IN szStartFolder, MA_PCWSTR IN szSourcePath );
MA_BOOL		MA_PathMakeAbsoluteE( MA_PESTR OUT szAbsolutePath, MA_SIZE IN sizePath, MA_PCESTR IN szStartFolder, MA_PCESTR IN szSourcePath );

// --------------------------------------------
// UNC
// --------------------------------------------
MA_BOOL		MA_PathIsUNCA( MA_PCASTR IN szPath );
MA_BOOL		MA_PathIsUNCW( MA_PCWSTR IN szPath );
MA_BOOL		MA_PathIsUNCE( MA_PCESTR IN szPath );

MA_BOOL		MA_PathSplitUNCA( MA_PCASTR IN szSourceUNC, MA_PASTR OUT szHostName, MA_SIZE sizeHostName, MA_PASTR OUT szPath, MA_SIZE sizePath );
MA_BOOL		MA_PathSplitUNCW( MA_PCWSTR IN szSourceUNC, MA_PWSTR OUT szHostName, MA_SIZE sizeHostName, MA_PWSTR OUT szPath, MA_SIZE sizePath );
MA_BOOL		MA_PathSplitUNCE( MA_PCESTR IN szSourceUNC, MA_PESTR OUT szHostName, MA_SIZE sizeHostName, MA_PESTR OUT szPath, MA_SIZE sizePath );

// --------------------------------------------
// Misc.
// --------------------------------------------

// Remove any "/./" that remain in pcPath
MA_BOOL		MA_PathRemoveSlashDotSlashA( MA_PASTR IN szPath );
MA_BOOL		MA_PathRemoveSlashDotSlashW( MA_PWSTR IN szPath );
MA_BOOL		MA_PathRemoveSlashDotSlashE( MA_PESTR IN szPath );

MA_BOOL		MA_PathRemoveDotDotsA( MA_PASTR IN szPath );
MA_BOOL		MA_PathRemoveDotDotsW( MA_PWSTR IN szPath );
MA_BOOL		MA_PathRemoveDotDotsE( MA_PESTR IN szPath );

// Convert a file path from Windows/Unix to the Windows platform's format. 
MA_BOOL		MA_PathStandardizeWindowsA( MA_PASTR IN szPath );
MA_BOOL		MA_PathStandardizeWindowsW( MA_PWSTR IN szPath );
MA_BOOL		MA_PathStandardizeWindowsE( MA_PESTR IN szPath );

// Convert a file path from Windows/Unix to the Unix platform's format. 
MA_BOOL		MA_PathStandardizeUnixA( MA_PASTR IN szPath );
MA_BOOL		MA_PathStandardizeUnixW( MA_PWSTR IN szPath );
MA_BOOL		MA_PathStandardizeUnixE( MA_PESTR IN szPath );

// Convert a file path from Windows/Unix to the Unix platform's format. 
MA_BOOL		MA_PathStandardizeURIA( MA_PASTR IN szPath );
MA_BOOL		MA_PathStandardizeURIW( MA_PWSTR IN szPath );
MA_BOOL		MA_PathStandardizeURIE( MA_PESTR IN szPath );

_NTR_EXTERN_C_END

#endif /* !_MA_PATH_H_ */
