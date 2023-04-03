#include <hooks/hooks.h>

extern SOCKET g_hPandoraSocket;
decltype(&::send) g_pOriginalSend;

namespace Hooks
{
	int __stdcall send(SOCKET socket, const char* buffer, int length, int flags)
	{
		if (socket == g_hPandoraSocket)
		{
			return length;
		}

		return g_pOriginalSend(socket, buffer, length, flags);
	}
}