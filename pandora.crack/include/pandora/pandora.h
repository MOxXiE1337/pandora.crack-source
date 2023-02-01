#pragma once
#include <includes.h>

#define CON_LOG(...)\
sdk::Cvar()->ConsolePrintf("["); \
sdk::Cvar()->ConsoleColorPrintf({123,104,238,255}, "pandora.crack");\
sdk::Cvar()->ConsolePrintf("] ");\
sdk::Cvar()->ConsolePrintf(__VA_ARGS__);

#define CON_ERR(...)\
sdk::Cvar()->ConsolePrintf("["); \
sdk::Cvar()->ConsoleColorPrintf({123,104,238,255}, "pandora.crack");\
sdk::Cvar()->ConsolePrintf("] ");\
sdk::Cvar()->ConsoleColorPrintf({255,0,0,255}, __VA_ARGS__);

namespace pandora
{
	struct module_info_t
	{
		void* begin;
		void* end;
		const char* name;
	};

	struct server_address_info_t
	{
		const char* module_name;
		const char* sig;
	};

	struct interface_info_t
	{
		const char* module_name;
		const char* name;
	};

	extern std::unordered_map<int, server_address_info_t> server_addresses;
	extern std::unordered_map<int, interface_info_t> interface_addresses;
	
	LONG NTAPI crash_handler(struct _EXCEPTION_POINTERS* exception_info);

	void init();
	void setup_interfaces();
	void setup_sigs();
	void setup_patches();
	void setup_hooks();
	void setup_imports();

#ifdef CN_VERSION
	extern std::unordered_multimap<void*, std::pair<std::wstring,std::wstring>> sinicizations;
	void setup_sinicizator();
#endif // CN_VERSION
	
	extern Json::Value lib_list;
	void setup_lua_system();
}
