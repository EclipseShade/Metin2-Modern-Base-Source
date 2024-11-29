#include "stdafx.h"

int generateRSAKey();
int generateSERVERKEY(const char* path);

int _tmain(int argc, _TCHAR* argv[])
{
	//
	// RSA key�� �����ϰ� ServerKey.Gen.h, PublicKey.Gen.h ������ �����Ѵ�.
	//
	if (argc == 2 && strcmp(argv[1], "-k") == 0)
	{
		return generateRSAKey();
	}

	//
	// SIM file(��, ���弭�� �� ���Ӽ����� ip�� mac ������ �ִ� ����)�� �о
	// private key�� ��ȣȭ �Ͽ� SERVER KEY�� �����Ѵ�.
	// ��, SERVER KEY = base64(enc(SIM file, private key)) �� ��
	//
	if (argc == 3 && strcmp(argv[1], "-d") == 0)
	{
		return generateSERVERKEY(argv[2]);
	}

	//
	// help ���
	//
	printf("help:\n");
	printf("ServerKeyGenerator.exe -k               -- generate RSA key and PublicKey.Gen.h file.\n");
	printf("ServerKeyGenerator.exe -d [SIM file]    -- generate SERVER KEY with sim(server ip/mac) file.\n");

	return 0;
}

