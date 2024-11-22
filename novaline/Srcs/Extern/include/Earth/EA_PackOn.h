#ifndef	_EA_PACKON_H_
#define	_EA_PACKON_H_

#if _NTR_SUPPORTS_PRAGMA_PACK == 1
	#if defined( _NTR_WINDOWS )
		#pragma warning( disable : 4103 )
		#pragma pack( push, 1 )
		#define EA_PACK
	#else
		#ifdef __GNUC__
			#define EA_PACK		__attribute__((packed))
		#else
			#warning "Don't know how to pack here!"
			#define EA_PACK
		#endif
	#endif
#else
	#warning "Don't know how to pack here!"
	#define EA_PACK
#endif

#endif //!_EA_PACKON_H_