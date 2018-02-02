#include "stdafx.h"

DWORD WINAPI CreateKey(const char *subKey)
{
	HKEY hKey = NULL;
	DWORD dwOptions = REG_OPTION_NON_VOLATILE;
	DWORD dwDisposition;
	long result = RegCreateKeyEx(HKEY_LOCAL_MACHINE, subKey, 0, NULL,
		dwOptions, KEY_WRITE, NULL, &hKey, &dwDisposition);

	if (result != ERROR_SUCCESS)
	{
		return GetLastError();
	}
	else
	{
		if (dwDisposition == REG_OPENED_EXISTING_KEY)
		{
			return ERROR_SUCCESS;
		}
		else if (dwDisposition == REG_CREATED_NEW_KEY)
		{
			return ERROR_SUCCESS;
		}
	}
}

DWORD WINAPI CreateValueS(const char *regname, const char * N1, const char * N2)
{
	HKEY hkResult;
	int ret = RegOpenKey(HKEY_LOCAL_MACHINE, regname, &hkResult);
	ret = RegSetValueEx(hkResult, N1, 0, REG_SZ, (unsigned char *)N2, strlen(N2));
	return GetLastError();
}

DWORD WINAPI CreateValueD(const char *regname, const char * N1, DWORD N2)
{
	HKEY hkResult;
	int ret = RegOpenKey(HKEY_LOCAL_MACHINE, regname, &hkResult);
	ret = RegSetValueEx(hkResult, N1, 0, REG_DWORD, (const BYTE*)N2, 25);
	return GetLastError();
}
