#pragma once
#include <includes.h>

namespace Hooks
{
	int __stdcall connect(SOCKET socket, const sockaddr* address, int length);
	int __stdcall send(SOCKET socket, const char* buffer, int length, int flags);

	DWORD WINAPI GetCurrentProcessId();

	PVOID CDECL ScanSignature(HMODULE hModule, CONST STD_STRING& strSignature, ULONG unk);
	PVOID CDECL GetAddressFromServer(ULONG nHash);

	PVOID CDECL GetInterface(ULONG nHash);

	VOID FASTCALL ReplaceUserName(STD_STRING* strString, PVOID pEdx, CHAR cCharacter);
}
