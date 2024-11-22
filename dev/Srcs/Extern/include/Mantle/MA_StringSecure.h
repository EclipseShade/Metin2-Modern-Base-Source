/**
* @file		MA_StringSecure.h
* @brief	MA_StringSecure class 
* @author	Standil (cpascal@cpascal.net)
* 
* @version	2008/03/12 cpascal - First Release
*/

#ifndef	_MA_STRINGSECURE_H_
#define	_MA_STRINGSECURE_H_

#define MA_SECURE_FILL_BUFFER_PATTERN		0x00

#define	MA_SECURE_FILL_STRING( STRING, SIZE, OFFSET )											\
{																	\
	if( ((SIZE) != (MA_SIZE)-1) && ((SIZE) != MA_XINT_MAX) && (((MA_SIZE)(OFFSET)) < (SIZE)) )					\
		memset( (STRING) + (OFFSET), (MA_SECURE_FILL_BUFFER_PATTERN), ((SIZE) - (OFFSET)) * sizeof( *(STRING) ) );		\
}

#define	MA_SECURE_FILL_BUFFER( BUFFER, SIZE, OFFSET )											\
{																	\
	if( ((SIZE) != (MA_SIZE)-1) && ((SIZE) != MA_XINT_MAX) && (((MA_SIZE)OFFSET) < (SIZE)) )					\
		memset( (BUFFER) + (OFFSET), (MA_SECURE_FILL_BUFFER_PATTERN), ((SIZE) - (OFFSET)) );					\
}

#if	defined( _NTR_DEBUG )
	#if defined( _NTR_STRICT )
		#define	MA_SECURE_FILL_STRING_A					MA_SECURE_FILL_STRING
		#define	MA_SECURE_FILL_STRING_W					MA_SECURE_FILL_STRING
	#else
		#define	MA_SECURE_FILL_STRING_A( STRING, SIZE, OFFSET )									\
		{															\
			if( ((SIZE) != (MA_SIZE)-1) && ((SIZE) != MA_XINT_MAX) && (((MA_SIZE)(OFFSET)) < (SIZE)) )			\
				*((STRING) + ((SIZE) - (OFFSET) - 1)) = '\0';								\
		}

		#define	MA_SECURE_FILL_STRING_W( STRING, SIZE, OFFSET )									\
		{															\
			if( ((SIZE)!= (MA_SIZE)-1) && ((SIZE) != MA_XINT_MAX) && (((MA_SIZE)(OFFSET)) < (SIZE)) )			\
				*((STRING) + ((SIZE) - (OFFSET) - 1)) = L'\0';								\
		}
	#endif
#else
	#if defined( _NTR_STRICT )
		#define	MA_SECURE_FILL_STRING_A( STRING, SIZE, OFFSET )									\
		{															\
			if( ((SIZE)!= (MA_SIZE)-1) && ((SIZE) != MA_XINT_MAX) && (((MA_SIZE)(OFFSET)) < (SIZE)) )			\
				*((STRING) + ((SIZE) - (OFFSET) - 1)) = '\0';								\
		}

		#define	MA_SECURE_FILL_STRING_W( STRING, SIZE, OFFSET )									\
		{															\
			if( ((SIZE)!= (MA_SIZE)-1) && ((SIZE) != MA_XINT_MAX) && (((MA_SIZE)(OFFSET)) < (SIZE)) )			\
				*((STRING) + ((SIZE) - (OFFSET) - 1)) = L'\0';								\
		}
	#else
		#define	MA_SECURE_FILL_STRING_A( STRING, SIZE, OFFSET )
		#define	MA_SECURE_FILL_STRING_W( STRING, SIZE, OFFSET )
	#endif
#endif

#endif /* !_MA_STRINGSECURE_H_ */
