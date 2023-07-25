#pragma once

class ISteamFriends
{
public:
	virtual const char* GetPersonName() = 0;
};

namespace SteamAPI
{
	ISteamFriends* GetISteamFriends();
}
