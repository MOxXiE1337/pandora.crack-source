#include <hooks/hooks.h>
#include <pandora/pandora.h>

SOCKET g_hPandoraSocket;
decltype(&::connect) g_pOriginalConnect;

namespace Hooks
{
	int __stdcall connect(SOCKET socket, const sockaddr* address, int length)
	{
		PVOID pReturnAddress = _ReturnAddress();

		if (pReturnAddress >= Pandora::ImageBase() && pReturnAddress < Pandora::ImageBase(0x74C000))
		{
			g_hPandoraSocket = socket;
			return true;
		}

		return g_pOriginalConnect(socket, address, length);
	}
}