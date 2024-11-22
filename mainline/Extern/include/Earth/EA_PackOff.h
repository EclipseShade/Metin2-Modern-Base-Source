#ifndef	_EA_PACKOFF_H_
#define	_EA_PACKOFF_H_

#if _NTR_SUPPORTS_PRAGMA_PACK == 1
	#if defined( _NTR_WINDOWS )
		#pragma pack( pop )
	#endif
	#undef EA_PACK
#else
	#undef EA_PACK
#endif

#endif //!_EA_PACKOFF_H_