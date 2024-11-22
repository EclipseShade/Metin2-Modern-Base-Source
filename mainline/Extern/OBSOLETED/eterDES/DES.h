#ifndef __INC_ETERDES_DES_H__
#define __INC_ETERDES_DES_H__

extern int DES_Encryption(const BYTE * byKey, const BYTE *byInput, int iLength, BYTE *byOutput);
extern int DES_Decryption(const BYTE * byKey, const BYTE *byInput, int iLength, BYTE *byOutput);

#endif
