#include <includes.h>
#include <steam_api/steam_api.h>

typedef HANDLE(*SteamAPI_GetHSteamUserFn)();
typedef INT(*SteamInternal_FindOrCreateUserInterfaceFn)(HANDLE hUser, CONST CHAR* pInterfaceName);

ISteamFriends* SteamAPI::GetISteamFriends()
{
	static ISteamFriends* pISteamFriends = NULL;

	if (pISteamFriends == NULL)
	{
		HMODULE hSteamAPI = GetModuleHandle(TEXT("steam_api"));
		SteamAPI_GetHSteamUserFn SteamAPI_GetHSteamUser = (SteamAPI_GetHSteamUserFn)GetProcAddress(hSteamAPI, "SteamAPI_GetHSteamUser");
		SteamInternal_FindOrCreateUserInterfaceFn SteamInternal_FindOrCreateUserInterface = (SteamInternal_FindOrCreateUserInterfaceFn)GetProcAddress(hSteamAPI, "SteamInternal_FindOrCreateUserInterface");

		if (SteamAPI_GetHSteamUser == NULL)
			return NULL;

		if (SteamInternal_FindOrCreateUserInterface == NULL)
			return NULL;

		pISteamFriends = (ISteamFriends*)SteamInternal_FindOrCreateUserInterface(SteamAPI_GetHSteamUser(), "SteamFriends017");
	}

	return pISteamFriends;
}