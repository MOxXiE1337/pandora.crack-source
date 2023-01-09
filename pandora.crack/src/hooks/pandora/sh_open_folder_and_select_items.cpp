#include <sdk/sdk.h>
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

namespace hooks
{
	decltype(&SHOpenFolderAndSelectItems) o_sh_open_folder_and_select_items;

	HRESULT __stdcall sh_open_folder_and_select_items(LPCITEMIDLIST arg0, UINT arg1, LPCITEMIDLIST* arg2, DWORD arg3)
	{
		static CHAR exe_path[MAX_PATH];
		void* ret_addr;

		__asm
		{
			mov eax, [ebp + 4];
			mov ret_addr, eax;
		}

		GetModuleFileNameA(NULL, exe_path, MAX_PATH);
		std::string path(exe_path);
		std::string open_pdr = "explorer.exe " + path.replace(path.find("csgo.exe"), std::string::npos, "Pandora");
		std::string open_cfg = open_pdr + "\\cfg";
		std::string open_lua = open_pdr + "\\lua";
		
		if (ret_addr == (void*)0x40E99EA8) //config
		{
			ndos_system(open_cfg.c_str());
			return 0;
		}
		if (ret_addr == (void*)0x40D75D1E) //script
		{
			ndos_system(open_lua.c_str());
			return 0;
		}

		return o_sh_open_folder_and_select_items(arg0, arg1, arg2, arg3);
	}
}