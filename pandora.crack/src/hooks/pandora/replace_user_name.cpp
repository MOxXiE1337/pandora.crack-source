#include <hooks/hooks.h>
#include <pandora/pandora.h>

namespace Hooks
{
	VOID FASTCALL ReplaceUserName(STD_STRING* strString, PVOID pEdx, CHAR cCharacter)
	{
		PVOID pReturnAddress = _ReturnAddress();
		
		if (pReturnAddress == Pandora::ImageBase(0x278D87))
		{
			*strString = "https://discord.gg/GHKuYjZrdM";
			return;
		}
		if (pReturnAddress == Pandora::ImageBase(0x30C28B))
		{
			*strString = "PinkKing";
			return;
		}

		return strString->push_back(cCharacter);
	}
}
