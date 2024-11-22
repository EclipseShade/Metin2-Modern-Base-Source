#ifndef _EL_CSVFILE_H_
#define _EL_CSVFILE_H_

#include "FlatMemory.h"

class EL_CCSVFile : public EL_CFlatMemory
{
public:
	EL_CCSVFile();
	virtual ~EL_CCSVFile();

	EL_BOOL		Load( MA_LPCTSTR tszFileName );

	// Not implemented yet
	EL_BOOL		Load( MA_LPCTSTR tszBuffer, MA_SIZE sizeBuffer );

	// Not implemented yet
	EL_BOOL		Save( MA_LPCTSTR tszFileName );
};

#endif /* !_EL_CSVFILE_H_ */
