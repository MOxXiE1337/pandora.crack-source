#pragma once
#include <includes.h>

namespace Utils
{
	PVOID ScanSignature(PVOID pStartAddress, SIZE_T nSize, CONST STD_STRING& strSignature);
	PVOID ScanSignature(HMODULE hModule, CONST STD_STRING& strSignature);
	PVOID ScanSignature(CONST STD_STRING& strModuleName, CONST STD_STRING& strSignature);
}
