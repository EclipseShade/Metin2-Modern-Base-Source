#pragma once

#pragma comment(lib, "Iphlpapi.lib")

#include <Iphlpapi.h>
#include <string>

// adapter �߿� ã�� MAC address�� �ִ��� Ȯ���ϰ� ip����
// macAddress : AABBCCDDEEFF�� hex string �Ǵ� AA-BB-CC-DD-EE-FF (�빮��)
// ���ϰ� : �ش� adapter�� �Ҵ�� ip address
static std::string GetIpAddressWithMacAddress(const std::string& macAddress)
{
	// adapter ������ �ִ� 2�������� ��������
	IP_ADAPTER_INFO AdapterInfo[2];       // Allocate information 

	// for up to 2 NICs
	DWORD dwBufLen = sizeof(AdapterInfo);  // Save memory size of buffer

	DWORD dwStatus = GetAdaptersInfo(      // Call GetAdapterInfo
		AdapterInfo,                 // [out] buffer to receive data
		&dwBufLen);                  // [in] size of receive data buffer
	assert(dwStatus == ERROR_SUCCESS);  // Verify return value is 
	// valid, no buffer overflow

	PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo; // Contains pointer to
	// current adapter info
	do {
		// get mac address string
		char buf[64], buf1[64];
		sprintf_s(buf, sizeof(buf), "%02X%02X%02X%02X%02X%02X",
			pAdapterInfo->Address[0], pAdapterInfo->Address[1], pAdapterInfo->Address[2], pAdapterInfo->Address[3], pAdapterInfo->Address[4], pAdapterInfo->Address[5]);
		sprintf_s(buf1, sizeof(buf1), "%02X-%02X-%02X-%02X-%02X-%02X",
			pAdapterInfo->Address[0], pAdapterInfo->Address[1], pAdapterInfo->Address[2], pAdapterInfo->Address[3], pAdapterInfo->Address[4], pAdapterInfo->Address[5]);

		if (macAddress == buf || macAddress == buf1)
		{
			return pAdapterInfo->IpAddressList.IpAddress.String;
		}

		pAdapterInfo = pAdapterInfo->Next;    // Progress through 
		// linked list
	}
	while(pAdapterInfo);                    // Terminate if last adapter

	// not found
	return "";
}

// adapter �߿� ã�� ip address�� �ִ��� Ȯ���ϰ� mac����
// ���ϰ�(macAddress) : AABBCCDDEEFF�� hex string �Ǵ� AA-BB-CC-DD-EE-FF (�빮��)
static std::string GetMacAddressWithIpAddress(const char* ip)
{
	// adapter ������ �ִ� 10�������� ��������
	IP_ADAPTER_INFO AdapterInfo[10];       // Allocate information 

	// for up to 10 NICs
	DWORD dwBufLen = sizeof(AdapterInfo);  // Save memory size of buffer

	DWORD dwStatus = GetAdaptersInfo(      // Call GetAdapterInfo
		AdapterInfo,                 // [out] buffer to receive data
		&dwBufLen);                  // [in] size of receive data buffer
	assert(dwStatus == ERROR_SUCCESS);  // Verify return value is 
	// valid, no buffer overflow

	PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo; // Contains pointer to
	// current adapter info
	do {
		if (strcmp(pAdapterInfo->IpAddressList.IpAddress.String, ip) == 0)
		{
			// get mac address string
			char buf[64];
			sprintf_s(buf, sizeof(buf), "%02X-%02X-%02X-%02X-%02X-%02X",
				pAdapterInfo->Address[0], pAdapterInfo->Address[1], pAdapterInfo->Address[2], pAdapterInfo->Address[3], pAdapterInfo->Address[4], pAdapterInfo->Address[5]);

			return buf;
		}

		pAdapterInfo = pAdapterInfo->Next;    // Progress through 
		// linked list
	}
	while(pAdapterInfo);                    // Terminate if last adapter

	// not found
	return "";
}
