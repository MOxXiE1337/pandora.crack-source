#include <hooks/hooks.h>
#include <pandora/pandora.h>
#include <steam_api/steam_api.h>

namespace Hooks
{
	VOID FASTCALL ReplaceUserName(STD_STRING* strString, PVOID pEdx, CHAR cCharacter)
	{
		PVOID pReturnAddress = _ReturnAddress();
		
		if (pReturnAddress == Pandora::ImageBase(0x278D87) || pReturnAddress == Pandora::ImageBase(0x30C28B))
		{
			ISteamFriends* pISteamFriends = SteamAPI::GetISteamFriends();
			*strString = pISteamFriends->GetPersonName();
			return;
		}

		return strString->push_back(cCharacter);
	}
}
