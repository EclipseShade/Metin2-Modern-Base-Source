#ifdef __cplusplus
extern "C" {
#endif

	extern int TEA_Encrypt(DWORD * dest, const DWORD * src, const DWORD * key, DWORD size);
	extern int TEA_Decrypt(DWORD * dest, const DWORD * src, const DWORD * key, DWORD size);

	extern int DES_Encrypt(DWORD *DstBuffer, const DWORD * SrcBuffer, const DWORD *KeyAddress, DWORD Length, DWORD *IVector);
	extern int DES_Decrypt(DWORD *DstBuffer, const DWORD * SrcBuffer, const DWORD *KeyAddress, DWORD Length, DWORD *IVector);

	extern int GOST_Encrypt(DWORD *DstBuffer, const DWORD * SrcBuffer, const DWORD *KeyAddress, DWORD Length, DWORD *IVector);
	extern int GOST_Decrypt(DWORD *DstBuffer, const DWORD * SrcBuffer, const DWORD *KeyAddress, DWORD Length, DWORD *IVector);

#ifdef __cplusplus
};
#endif
