/*
   Copyright (C) Information Equipment co.,LTD.
   All rights reserved.
   Code by JaeHyuk Cho <mailto:minzkn@infoeq.com>
   CVSTAG="$Header$"
   */

#if !defined(__def_mzapi_header_mzseed_h__)
#define __def_mzapi_header_mzseed_h__ "mzseed.h"

#if !defined(__t_mzapi_dword__)
# define __t_mzapi_dword__ unsigned int
#endif

#if !defined(__t_mzapi_byte__)
# define __t_mzapi_byte__ unsigned char
#endif

#if !defined(__t_mzapi_void__)
# define __t_mzapi_void__ void
#endif

#if !defined(__t_mzapi_ptr__)
# define __t_mzapi_ptr__ __t_mzapi_void__ *
#endif

#if !defined(__t_mzapi_size__)
# if defined(size_t)
#  define __t_mzapi_size__ size_t
# else
#  define __t_mzapi_size__ unsigned int
# endif
#endif

#if !defined(__mzapi_const__)
# define __mzapi_const__ const
#endif

#if !defined(__mzapi_fastcall__)
# define __mzapi_fastcall__
#endif

#if !defined(__mzapi_static__)
# define __mzapi_static__ static
#endif

#if !defined(__mzapi_export__)
# define __mzapi_export__
#endif

#if !defined(__mzapi_import__)
# define __mzapi_import__ extern
#endif

#define __def_mzapi_seed_rounds__ (16)
#define __def_mzapi_seed_round_keys__ (__def_mzapi_seed_rounds__ << 1)
#define __def_mzapi_seed_block_size__ (16)

#define __mzapi_seed_peek__(m_cast,m_base,m_offset) ((m_cast)(((__t_mzapi_byte__ *)(m_base)) + (m_offset)))

#if defined(__cplusplus)
extern "C" {
#endif

#if !defined(__def_mzapi_source_mzseed_c__)
    __mzapi_import__ __t_mzapi_ptr__ (__mzapi_fastcall__ mzapi_seed_make_round_key)(__t_mzapi_ptr__ s_round_key, __mzapi_const__ __t_mzapi_ptr__ s_user_key);
    __mzapi_import__ __t_mzapi_ptr__ (__mzapi_fastcall__ mzapi_seed_encrypt_block)(__t_mzapi_ptr__ s_data, __mzapi_const__ __t_mzapi_ptr__ s_round_key);
    __mzapi_import__ __t_mzapi_ptr__ (__mzapi_fastcall__ mzapi_seed_decrypt_block)(__t_mzapi_ptr__ s_data, __mzapi_const__ __t_mzapi_ptr__ s_round_key);
    __mzapi_import__ __t_mzapi_ptr__ (__mzapi_fastcall__ mzapi_seed_encrypt)(__t_mzapi_ptr__ s_data, __t_mzapi_size__ s_size, __mzapi_const__ __t_mzapi_ptr__ s_round_key);
    __mzapi_import__ __t_mzapi_ptr__ (__mzapi_fastcall__ mzapi_seed_decrypt)(__t_mzapi_ptr__ s_data, __t_mzapi_size__ s_size, __mzapi_const__ __t_mzapi_ptr__ s_round_key);
#endif

/* by mhh */
#define EL_SEED_MAX_ROUNDS		__def_mzapi_seed_rounds__       /* user key  : 16       */
#define EL_SEED_MAX_ROUND_KEYS	__def_mzapi_seed_round_keys__   /* round key : 32       */
/*
 * example
 * unsigned char user_key[EL_SEED_MAX_ROUNDS];
 * unsigned char round_key[EL_SEED_MAX_ROUND_KEYS];
 * char data[256] = "Hello World";
 * int data_len = strlen(data);
 *
 * [generate random user_key]
 *      for (int i=0; i<EL_SEED_MAX_ROUNDS; ++i)
 *      {
 *              user_key[i] = 0x00 ~ 0xFF;
 *      }
 *
 * [make round_key]
 *      SEED_make_round_key(round_key, user_key);
 *
 * [encrypt data]
 *      SEED_encrypt(data, data_len, round_key);
 *
 * [decrypt data]
 *      SEED_decrypt(data, data_len, round_key);
 *
 */

/**
 * param: round_key     (OUTPUT)
 * param: user_key      (INPUT)
 */
EL_BASE_API EL_VOID* EL_SEED_MakeRoundKey(void* round_key, const void* user_key);

/**
 * param: data          (INPUT,OUTPUT)
 * param: data_len      (INPUT)
 * param: round_key     (INPUT)
 */
EL_BASE_API EL_VOID* EL_SEED_Encrypt(void* data, int data_len, const void* round_key);

/**
 * param: data          (INPUT,OUTPUT)
 * param: data_len      (INPUT)
 * param: round_key     (INPUT)
 */
EL_BASE_API EL_VOID* EL_SEED_Decrypt(void* data, int data_len, const void* round_key);

#if defined(__cplusplus)
}
#endif

#endif

/* vim: set expandtab: */
/* End of source */ 
