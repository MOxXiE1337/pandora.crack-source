#include <hooks/hooks.h>
#include <pandora/pandora.h>
#include <steam_api/steam_api.h>

decltype(&Hooks::lua_pushlstring) g_pOriginal_lua_pushlstring;

namespace Hooks
{
	void lua_pushlstring(void* L, const char* s, size_t l)
	{
		PVOID pReturnAddress = _ReturnAddress();

		if (pReturnAddress == Pandora::ImageBase(0x5EE80) && !strcmp(s, "legende1337")) // replace username
		{
			ISteamFriends* pISteamFriends = SteamAPI::GetISteamFriends();
	
			return g_pOriginal_lua_pushlstring(L, pISteamFriends->GetPersonName(), strlen(pISteamFriends->GetPersonName()));
		}

		return g_pOriginal_lua_pushlstring(L, s, l);
	}
}