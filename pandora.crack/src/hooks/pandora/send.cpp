#include <hooks/hooks.h>

extern SOCKET g_pdr_socket;

namespace hooks
{
	decltype(&::send) o_send;

	int __stdcall send(SOCKET s, const char* buf, int len, int flags)
	{
		if (s == g_pdr_socket)
		{
			return len;
		}

		return o_send(s, buf, len, flags);
	}
}