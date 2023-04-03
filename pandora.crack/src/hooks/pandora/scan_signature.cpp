#include <hooks/hooks.h>
#include <utils/memory.h>
#include <pandora/pandora.h>

namespace Hooks
{
	PVOID CDECL ScanSignature(HMODULE hModule, CONST STD_STRING& strSignature, ULONG unk)
	{
		PVOID pFixedAddress = Utils::ScanSignature(hModule, strSignature);

		if (!pFixedAddress)
		{
			MessageBox(Pandora::HWnd(), TEXT("FAILED TO FIX SIGNATURE!"), TEXT(__FUNCTION__), MB_ICONERROR);
			exit(0);
		}

		return pFixedAddress;
	}
}