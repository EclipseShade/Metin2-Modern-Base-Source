#include "stdafx.h"

#include "time.h"
#include "RSACrypto.h"

using namespace Security;

//
// RSA key�� �����Ͽ�, ServerKey.Gen.h, PublicKey.Gen.h �ΰ��� ������ �����Ѵ�.
// PublicKey.Gen.h���� public key�� vector ���·� �����ϴ� CreatePublicKey() �Լ��� ������,
// ServerKey.Gen.h���� CreatePublicKey() �Լ��� private key�� vector ���·� �����ϴ� CreatePrivateKey() �Լ��� �ִ�.
//
// PublicKey.Gen.h�� ���Ӽ��� �� ���弭������ ����ϸ� public key�� �����Ǿ �������.
// ServerKey.Gen.h�� �ܺο� �����Ǿ�� �ȵȴ�. (�缳���� ���� ����)
//
int generateRSAKey()
{
	InitRandomSeed();

	RSACrypto::PublicKey publicKey;
	RSACrypto::PrivateKey privateKey;
	if (false == RSACrypto::GenerateKey(&publicKey, &privateKey))
	{
		printf("RSA key generation failed\n");
		return 1;
	}

	//
	// ������ Ű�� ���ۿ� ����
	//
	char privateKeyBuf[1024];
	size_t privateKeyBufLen = sizeof(privateKeyBuf);

	if (false == RSACrypto::StorePrivateKey(&privateKey, privateKeyBuf, privateKeyBufLen))
	{
		printf("RSA private key store failed\n");
		return 1;
	}

	char publicKeyBuf[1024];
	size_t publicKeyBufLen = sizeof(publicKeyBuf);

	if (false == RSACrypto::StorePublicKey(&publicKey, publicKeyBuf, publicKeyBufLen))
	{
		printf("RSA public key store failed\n");
		return 1;
	}

	//
	// ������� ���� �ۼ�
	//
	time_t now = time(NULL);

	char buf[4096];
	sprintf_s(buf, sizeof(buf),
		"#ifndef __GenerateRSAKey_%I64u__\n"
		"#define __GenerateRSAKey_%I64u__\n\n"
		"// created : %s (time_t = %I64u)\n"
		"#include <vector>\n\n", now, now, __TIMESTAMP__, now);

	std::string hdr = buf;		// ������� ���ۺκ�

	sprintf_s(buf, sizeof(buf), "\n#endif\n");
	std::string footer = buf;

	std::stringstream public_h;	// public key �����Լ� ����

	sprintf_s(buf, sizeof(buf), "inline void CreatePublicKey(std::vector<unsigned char>& key)\n{\n");
	public_h << buf;

	for (size_t i = 0; i < publicKeyBufLen; i++)
	{
		sprintf_s(buf, sizeof(buf), "	key.push_back(%u);	// %u\n", (unsigned char)publicKeyBuf[i], i);
		public_h << buf;
	}

	sprintf_s(buf, sizeof(buf), "}\n");
	public_h << buf;

	std::stringstream private_h;	// private key �����Լ� ����

	sprintf_s(buf, sizeof(buf), "inline void CreatePrivateKey(std::vector<unsigned char>& key)\n{\n");
	private_h << buf;

	for (size_t i = 0; i < privateKeyBufLen; i++)
	{
		sprintf_s(buf, sizeof(buf), "	key.push_back(%u);	// %u\n", (unsigned char)privateKeyBuf[i], i);
		private_h << buf;
	}

	sprintf_s(buf, sizeof(buf), "}\n");
	private_h << buf;

	//
	// ������� ����
	//
	std::ofstream f;
	f.open("ServerKey.Gen.h");
	if (!f.is_open())
	{
		printf("ServerKey.Gen.h file generate failed\n");
		return 1;
	}
	f << hdr;
	f << private_h.str();
	f << public_h.str();
	f << footer;
	f.close();

	f.open("PublicKey.Gen.h");
	if (!f.is_open())
	{
		printf("PublicKey.Gen.h file generate failed\n");
		return 1;
	}
	f << hdr;
	f << public_h.str();
	f << footer;
	f.close();

	return 0;
}
