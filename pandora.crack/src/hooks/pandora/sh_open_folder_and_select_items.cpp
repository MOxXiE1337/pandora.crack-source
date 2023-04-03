#include <hooks/hooks.h>
#include <pandora/pandora.h>

int ndos_system(const char* cmd)
{
	STARTUPINFOA si;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof STARTUPINFO;

	PROCESS_INFORMATION pi = { 0 };
	if (CreateProcessA(NULL, (LPSTR)cmd, NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS | CREATE_NO_WINDOW, NULL, NULL, &si, &pi))
	{

		WaitForSingleObject(pi.hProcess, INFINITE);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		return -1;
	}
	return 0;
}

decltype(&::SHOpenFolderAndSelectItems) g_pOriginalSHOpenFolderAndSelectItems;

namespace Hooks
{
	HRESULT WINAPI SHOpenFolderAndSelectItems(LPCITEMIDLIST pArg0, UINT nArg1, LPCITEMIDLIST* pArg2, DWORD dwArg3)
	{
		static CHAR pCurrentPath[MAX_PATH];
		PVOID pReturnAddress = _ReturnAddress();

		GetModuleFileNameA(NULL, pCurrentPath, MAX_PATH);
		STD_STRING strCurrentPath(pCurrentPath);
		STD_STRING strOpenCommand = "explorer.exe " + strCurrentPath.replace(strCurrentPath.find("csgo.exe"), -1, "Pandora");
		STD_STRING strOpenConfigPath = strOpenCommand + "\\cfg";
		STD_STRING strOpenScriptPath = strOpenCommand + "\\lua";
		
		if (pReturnAddress == Pandora::ImageBase(0x349EA8))
		{
			ndos_system(strOpenConfigPath.c_str());
			return 0;
		}
		if (pReturnAddress == Pandora::ImageBase(0x225D1E)) 
		{
			ndos_system(strOpenScriptPath.c_str());
			return 0;
		}

		return g_pOriginalSHOpenFolderAndSelectItems(pArg0, nArg1, pArg2, dwArg3);
	}
}