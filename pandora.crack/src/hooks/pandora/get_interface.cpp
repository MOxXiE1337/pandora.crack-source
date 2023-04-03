#include <hooks/hooks.h>
#include <pandora/pandora.h>

PVOID CreateInterface(CONST STD_STRING& strModuleName, CONST STD_STRING& strInterfaceName)
{
	typedef PVOID(*CreateInterfaceFn)(CONST CHAR* pInterfaceName, PINT pRetVal);
	
	INT nTempVal = 0;
	HMODULE hModule = LoadLibraryA(strModuleName.c_str());
	CreateInterfaceFn CreateInterfaceProc = (CreateInterfaceFn)GetProcAddress(hModule, "CreateInterface");

	return CreateInterfaceProc(strInterfaceName.c_str(), &nTempVal);
}

namespace Hooks
{
	PVOID CDECL GetInterface(ULONG nHash)
	{
		CONST STD_STRING& strInterface = Pandora::Interfaces()[nHash];
		SIZE_T nPos = strInterface.find(".");

		STD_STRING strModuleName = strInterface.substr(0, nPos);
		STD_STRING strIntefaceName = strInterface.substr(nPos + 1, -1);

		PVOID pFixedAddress = CreateInterface(strModuleName, strIntefaceName);

		if (!pFixedAddress)
		{
			MessageBox(Pandora::HWnd(), TEXT("FAILED TO FIX INTERFACE!"), TEXT(__FUNCTION__), MB_ICONERROR);
			exit(0);
		}

		return pFixedAddress;
	}
}