#include <utils/memory.h>

namespace Utils
{
	PVOID ScanSignature(PVOID pStartAddress, SIZE_T nSize, CONST STD_STRING& strSignature)
	{
		PBYTE pScanStart, pScanEnd;
		STD_STRINGSTREAM stream{ strSignature };
		STD_STRING c;
		STD_VECTOR<STD_PAIR<BYTE, BOOL>> signature;

		if (!pStartAddress || !nSize || strSignature.empty())
			return NULL;

		while (stream >> c)
		{
			if (c[0] == '?')
				signature.push_back({ 0,TRUE });
			else if (isxdigit(c[0]) && isxdigit(c[1]))
				signature.push_back({ (BYTE)strtoul(c.c_str(), 0, 16), FALSE });
		}
		
		pScanStart = (PBYTE)pStartAddress;
		pScanEnd = pScanStart + nSize;

		PBYTE result = std::search(pScanStart, pScanEnd, signature.begin(), signature.end(),
			[](CONST BYTE b, CONST STD_PAIR<BYTE, BOOL>& p) {
				return b == p.first || p.second;
			});

		if (result == pScanEnd)
			return NULL;

		return result;
	}

	PVOID ScanSignature(HMODULE hModule, CONST STD_STRING& strSignature)
	{
		MODULEINFO module_info;
		GetModuleInformation(GetCurrentProcess(), hModule, &module_info, sizeof(MODULEINFO));
		return ScanSignature(module_info.lpBaseOfDll, module_info.SizeOfImage, strSignature);
	}

	PVOID ScanSignature(CONST STD_STRING& strModuleName, CONST STD_STRING& strSignature)
	{
		return ScanSignature(GetModuleHandleA(strModuleName.c_str()), strSignature);
	}
}
