/**
 * @file	MacroString.h
 * @brief	Macro substitution function
 * @author	Standil (cpascal@cpascal.net)
 *
 * Adapted from SSCLI
 *
 * @version	2006/05/21 cpascal - First release (macro substition class)
 * @version	2009/08/03 cpascal - Porting to YmirBase (macro substition function) / WideCharacter compatiability is lost.
 */

#ifndef _MACROSTRING_H_
#define _MACROSTRING_H_

#include "TStringTable.h"

EL_BOOL EL_MakeMacroString( LPTSTR tszDestination, size_t sizeDestination, LPTSTR tszSource, const EL_StringTable& rkStrTable );

#endif /* !_MACROSTRING_H_ */
