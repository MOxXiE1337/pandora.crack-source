#pragma once
#include <includes.h>

namespace Hooks
{
	DWORD WINAPI GetCurrentProcessId();

	PVOID CDECL ScanSignature(HMODULE hModule, CONST STD_STRING& strSignature, ULONG unk);
	PVOID CDECL GetAddressFromServer(ULONG nHash);

	PVOID CDECL GetInterface(ULONG nHash);

	VOID FASTCALL ReplaceUserName(STD_STRING* strString, PVOID pEdx, CHAR cCharacter);

	HRESULT WINAPI SHOpenFolderAndSelectItems(LPCITEMIDLIST pArg0, UINT nArg1, LPCITEMIDLIST* pArg2, DWORD dwArg3);

	int lua_load(void* L, void* reader, void* dt, const char* chunkname);
	void lua_pushlstring(void* L, const char* s, size_t l);
}
