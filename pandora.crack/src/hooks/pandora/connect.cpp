#include <sdk/sdk.h>
#include <hooks/hooks.h>
#include <pandora/pandora.h>

SOCKET g_pdr_socket;

namespace hooks
{
	decltype(&::connect) o_connect;

	int __stdcall connect(SOCKET s, const sockaddr* addr, int len)
	{
		void* ret_addr;

		__asm
		{
			mov eax, [ebp + 4];
			mov ret_addr, eax;
		}

		if (ret_addr >= (void*)0x40B50000 && ret_addr < (void*)0x4129C000)
		{
			g_pdr_socket = s;
			return true;
		}

		return o_connect(s, addr, len);
	}
}