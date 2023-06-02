#include <pandora/pandora.h>

typedef BOOL(__stdcall* DllEntryFn)(HMODULE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);

namespace Pandora
{
	HMODULE& LoaderModule()
	{
		static HMODULE hLoaderModule = NULL;
		return hLoaderModule;
	}

	HWND& HWnd()
	{
		static HWND hWnd = NULL;
		return hWnd;
	}
	
	PVOID ImageBase(ULONG nOffset, BOOL bSet)
	{
		static PVOID pImageBase = NULL;

		if (bSet == TRUE)
		{
			pImageBase = (PVOID)nOffset;
		}

		return (PBYTE)pImageBase + nOffset;
	}

	VOID Init()
	{
		while (!GetModuleHandle(TEXT("serverbrowser.dll")))
			Sleep(100);
		
		ImageBase((ULONG)VirtualAlloc(NULL, SegmentSize(), MEM_COMMIT, PAGE_EXECUTE_READWRITE), TRUE);

		if (ImageBase() == NULL)
		{
			MessageBox(HWnd(), TEXT("FAILED TO ALLOCATE MEMORY!"), TEXT(__FUNCTION__), MB_ICONERROR);
		}

		memcpy(ImageBase(), SegmentData(), SegmentSize());
		
		SetupInterfaces();
		SetupSignatures();
		SetupPatches();
		SetupHooks();
		SetupRelocations();
		SetupImports();

		DllEntryFn(ImageBase(0x4EFFBF))((HMODULE)ImageBase(), DLL_PROCESS_ATTACH, 0);

		return;
	QUIT:
		FreeLibraryAndExitThread(LoaderModule(), 0);
		return;
	}
}
