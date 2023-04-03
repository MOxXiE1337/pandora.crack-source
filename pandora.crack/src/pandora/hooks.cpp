#include <hooks/hooks.h>
#include <pandora/pandora.h>
#include <minhook/minhook.h>

extern decltype(&::connect) g_pOriginalConnect;
extern decltype(&::send) g_pOriginalSend;
extern decltype(&::SHOpenFolderAndSelectItems) g_pOriginalSHOpenFolderAndSelectItems;

namespace Pandora
{
	void SetupHooks()
	{
		if (MH_Initialize())
		{
			MessageBox(HWnd(), TEXT("FAILED TO INITIALIZE MINHOOK!"), TEXT(__FUNCTION__), MB_ICONERROR);
			goto QUIT;
		}
		if (MH_CreateHook(&connect, Hooks::connect, (PVOID*)&g_pOriginalConnect))
		{
			MessageBox(HWnd(), TEXT("FAILED TO HOOK wsock32.connect!"), TEXT(__FUNCTION__), MB_ICONERROR);
			goto QUIT;
		}
		if (MH_CreateHook(&send, Hooks::send, (PVOID*)&g_pOriginalSend))
		{
			MessageBox(HWnd(), TEXT("FAILED TO HOOK wsock32.send!"), TEXT(__FUNCTION__), MB_ICONERROR);
			goto QUIT;
		}
		if (MH_CreateHook(&GetCurrentProcessId, Hooks::GetCurrentProcessId, NULL))
		{
			MessageBox(HWnd(), TEXT("FAILED TO HOOK kernel32.GetCurrentProcessId!"), TEXT(__FUNCTION__), MB_ICONERROR);
			goto QUIT;
		}
		if (MH_CreateHook(&SHOpenFolderAndSelectItems, Hooks::SHOpenFolderAndSelectItems, (void**)&g_pOriginalSHOpenFolderAndSelectItems))
		{
			MessageBox(HWnd(), TEXT("FAILED TO HOOK shell32.SHOpenFolderAndSelectItems!"), TEXT(__FUNCTION__), MB_ICONERROR);
			goto QUIT;
		}
		if (MH_CreateHook(ImageBase(0x4BB990), Hooks::ScanSignature, NULL))
		{
			MessageBox(HWnd(), TEXT("FAILED TO HOOK pandora.ScanSignature!"), TEXT(__FUNCTION__), MB_ICONERROR);
			goto QUIT;
		}
		if (MH_CreateHook(ImageBase(0x298EC0), Hooks::GetAddressFromServer, NULL))
		{
			MessageBox(HWnd(), TEXT("FAILED TO HOOK pandora.GetAddressFromServer!"), TEXT(__FUNCTION__), MB_ICONERROR);
			goto QUIT;
		}
		if (MH_CreateHook(ImageBase(0x4E3430), Hooks::GetInterface, NULL))
		{
			MessageBox(HWnd(), TEXT("FAILED TO HOOK pandora.GetInterface!"), TEXT(__FUNCTION__), MB_ICONERROR);
			goto QUIT;
		}
		if (MH_CreateHook(ImageBase(0x555A0), Hooks::ReplaceUserName, NULL))
		{
			MessageBox(HWnd(), TEXT("FAILED TO HOOK pandora.ReplaceUserName!"), TEXT(__FUNCTION__), MB_ICONERROR);
			goto QUIT;
		}
		if (MH_EnableHook(NULL))
		{
			MessageBox(HWnd(), TEXT("FAILED TO ENABLE HOOKS"), TEXT(__FUNCTION__), MB_ICONERROR);
			goto QUIT;
		}

		return;
	QUIT:
		FreeLibraryAndExitThread(LoaderModule(), 0);
	}
}