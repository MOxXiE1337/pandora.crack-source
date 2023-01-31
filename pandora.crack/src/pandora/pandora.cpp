#include <sdk/sdk.h>
#include <pandora/pandora.h>

typedef BOOL(__stdcall* oep_fn)(HMODULE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);

extern HMODULE g_loader_module;
extern unsigned char g_seg_data[];

namespace pandora
{
	void init()
	{
		void* pdr_beg = (void*)0x40B50000;
		size_t pdr_size = 0x74C000;

		MEMORY_BASIC_INFORMATION mbi;

		CON_LOG("start loading pandora.crack...\n");
		if (!VirtualQuery(pdr_beg, &mbi, sizeof(MEMORY_BASIC_INFORMATION)))
		{
			CON_ERR("failed to query memory chunk!\n");
			goto QUIT;
		}
		if (mbi.RegionSize != pdr_size)
		{
			CON_ERR("failed to check memory chunk!\n");
			goto QUIT;
		}

		CON_LOG("initializing loader...\n");
		setup_interfaces();
		setup_sigs();
		CON_LOG("loader initialized.\n");

		CON_LOG("copying segment...\n");
		memcpy(pdr_beg, g_seg_data, pdr_size);
		CON_LOG("segment copied.\n");

		while (!GetModuleHandle("serverbrowser.dll")) 
			Sleep(100);

		CON_LOG("patching pandora...\n");
		setup_patches();
		CON_LOG("pandora patched.\n");

		CON_LOG("initializing hooks...\n");
		setup_hooks();
		CON_LOG("hooks initialized.\n");

		CON_LOG("fixing imports...\n");
		setup_imports();
		CON_LOG("imports fixed.\n");

#ifdef CN_VERSION
		CON_LOG("initializing sinicizator...\n");
		setup_sinicizator();
		CON_LOG("sinicizator initialized.\n");
#endif // CN_VERSION

		/*
		CON_LOG("initializing lua system...\n");
		setup_lua_system();
		CON_LOG("lua system initialized.\n");
		*/

		CON_LOG("invoking oep...\n");
		oep_fn(0x4103FFBF)((HMODULE)pdr_beg, DLL_PROCESS_ATTACH, 0);
		CON_LOG("oep invoked...\n");

		CON_LOG("all works done.\n");
		CON_LOG("owned by PinkKing#8199 & NiceL#0001 ( https://discord.gg/GHKuYjZrdM )\n");
	
		CON_LOG("private cheat provider - delusive.cc\n");

		return;
	QUIT:
		FreeLibraryAndExitThread(g_loader_module, 0);
		return;
	}
}