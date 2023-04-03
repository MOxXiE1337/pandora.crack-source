#include <hooks/hooks.h>
#include <utils/memory.h>
#include <pandora/pandora.h>

namespace Hooks
{
	PVOID CDECL GetAddressFromServer(ULONG nHash)
	{
		CONST STD_STRING& strAddressInfo = Pandora::Signatures()[nHash];
		STD_STRING strModuleName = strAddressInfo.substr(0, strAddressInfo.find(" => "));
		STD_STRING strSignature = strAddressInfo.substr(strAddressInfo.find("[") + 1, strAddressInfo.find("]"));

		PVOID pFixedAddress = Utils::ScanSignature(strModuleName, strSignature);

		if (!pFixedAddress)
		{
			MessageBox(Pandora::HWnd(), TEXT("FAILED TO FIX ONLINE SIGNATURE!"), TEXT(__FUNCTION__), MB_ICONERROR);
			exit(0);
		}

		return pFixedAddress;
	}
}