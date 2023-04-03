#pragma once
#include <includes.h>

namespace Pandora
{
	HMODULE&   LoaderModule();

	HWND& HWnd();

	PVOID ImageBase(ULONG nOffset = 0, BOOL bSet = FALSE);

	PBYTE      SegmentData();
	SIZE_T     SegmentSize();

	STD_UNORDERED_MAP<ULONG, STD_STRING>& Interfaces();
	STD_UNORDERED_MAP<ULONG, STD_STRING>& Signatures();

	VOID       Init();
	VOID       SetupInterfaces();
	VOID       SetupSignatures();
	VOID       SetupPatches();
	VOID       SetupHooks();
	VOID       SetupRelocations();
	VOID       SetupImports();

	LONG NTAPI CrashHandler(struct _EXCEPTION_POINTERS* pExceptionInfo);
}
