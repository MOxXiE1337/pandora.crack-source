#include <sdk/sdk.h>
#include <hooks/hooks.h>
#include <pandora/pandora.h>
#include <minhook/minhook.h>

extern HMODULE g_loader_module;

namespace hooks
{
	utils::vmthook surface;
}

__declspec(naked) void hooks_rebase_interface()
{
	__asm
	{
		pushad;
		push ebp;
		push eax;
		call hooks::fix_interface;
		pop ebp;
		mov [ebp - 0x40], eax;
		popad;
		push hooks::o_rebase_interface;
		ret;
	}
}

__declspec(naked) void hooks_username1()
{
	__asm
	{
		call hooks::fix_username1;
		push hooks::o_username1;
		ret;
	}
}

__declspec(naked) void hooks_username2()
{
	__asm
	{
		call hooks::fix_username2;
		push hooks::o_username2;
		ret;
	}
}

bool is_file_exist(const char* file_name)
{
	struct stat buffer;
	return (stat(file_name, &buffer) == 0);
}

namespace pandora
{
	void setup_hooks()
	{
		if (MH_Initialize())
		{
			CON_ERR("failed to init minhook!\n");
			goto QUIT;
		}
		if (MH_CreateHook(&connect, hooks::connect, (void**)&hooks::o_connect))
		{
			CON_ERR("failed to hook connect!\n");
			goto QUIT;
		}
		if (MH_CreateHook(&send, hooks::send, (void**)&hooks::o_send))
		{
			CON_ERR("failed to hook send!\n");
			goto QUIT;
		}
		if (MH_CreateHook(&GetCurrentProcessId, hooks::get_current_process_id, (void**)&hooks::o_get_current_process_id))
		{
			CON_ERR("failed to hook get_current_process_id\n");
			goto QUIT;
		}
		if (MH_CreateHook(&SHOpenFolderAndSelectItems, hooks::sh_open_folder_and_select_items, (void**)&hooks::o_sh_open_folder_and_select_items))
		{
			CON_ERR("failed to hook sh_open_folder_and_select_items\n");
			goto QUIT;
		}
		if (MH_CreateHook((void*)0x4100B990, hooks::find_pattern, &hooks::o_find_pattern))
		{
			CON_ERR("failed to hook find_pattern!\n");
			goto QUIT;
		}
		if (MH_CreateHook((void*)0x40DE8EC0, hooks::get_address_from_server, &hooks::o_get_address_from_server))
		{
			CON_ERR("failed to hook get_address_from_server!\n");
			goto QUIT;
		}
		if (MH_CreateHook((void*)0x410335EB, hooks_rebase_interface, &hooks::o_rebase_interface))
		{
			CON_ERR("failed to hook rebase_interface!\n");
			goto QUIT;
		}
		if (MH_CreateHook((void*)0x40DC8D70, hooks_username1, &hooks::o_username1))
		{
			CON_ERR("failed to hook username1!\n");
			goto QUIT;
		}
		if (MH_CreateHook((void*)0x40E5C274, hooks_username2, &hooks::o_username2))
		{
			CON_ERR("failed to hook username2!\n");
			goto QUIT;
		}
		if (MH_CreateHook((void*)0x410B6600, hooks::lua_load, &hooks::o_lua_load))
		{
			CON_ERR("failed to hook lua_load!\n");
			goto QUIT;
		}
		if (MH_EnableHook(NULL))
		{
			CON_ERR("failed to enable hooks!\n");
			goto QUIT;
		}

#ifdef CN_VERSION
		void* surface = sdk::CreateInterface<void*>("vguimatsurface.dll", "VGUI_Surface");
		hooks::surface.initialize((PDWORD*)surface);
		hooks::surface.hook_function((DWORD)hooks::set_font_glyph_set, 72);
		hooks::surface.hook_function((DWORD)hooks::draw_print_text, 28);
		hooks::surface.hook_function((DWORD)hooks::get_text_size, 79);
#endif // CN_VERSION

		return;
	QUIT:
		FreeLibraryAndExitThread(g_loader_module, 0);
	}
}