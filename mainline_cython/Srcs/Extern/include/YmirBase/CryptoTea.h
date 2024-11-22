#pragma once

typedef unsigned int EL_TEA_WORD;
typedef unsigned int EL_TEA_BLOCK_COUNT;

typedef unsigned char EL_TEA_SECRET_KEY[16];

struct EL_TEA_BLOCK_BUFFER
{
	EL_TEA_WORD sy;
	EL_TEA_WORD sz;
};

EL_BASE_API EL_SIZE EL_TEA_CalcBlockCount(EL_SIZE size);
EL_BASE_API EL_TEA_BLOCK_BUFFER* EL_TEA_Encrypt(EL_TEA_BLOCK_BUFFER* dstBlocks, EL_TEA_BLOCK_BUFFER* srcBlocks, EL_SIZE blockCount, const EL_TEA_SECRET_KEY* secretKey);
EL_BASE_API EL_TEA_BLOCK_BUFFER* EL_TEA_Decrypt(EL_TEA_BLOCK_BUFFER* dstBlocks, EL_TEA_BLOCK_BUFFER* srcBlocks, EL_SIZE blockCount, const EL_TEA_SECRET_KEY* secretKey);
