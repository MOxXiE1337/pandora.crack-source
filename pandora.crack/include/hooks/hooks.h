#pragma once
#include <includes.h>
#include <utils/vmthook.h>

namespace hooks
{
	extern decltype(&::connect) o_connect;
	int __stdcall connect(SOCKET s, const sockaddr* addr, int len);

	extern decltype(&::send) o_send;
	int __stdcall send(SOCKET s, const char* buf, int len, int flags);

	extern decltype(&GetCurrentProcessId) o_get_current_process_id;
	DWORD __stdcall get_current_process_id();

	extern decltype(&SHOpenFolderAndSelectItems) o_sh_open_folder_and_select_items;
	HRESULT __stdcall sh_open_folder_and_select_items(LPCITEMIDLIST arg0, UINT arg1, LPCITEMIDLIST* arg2, DWORD arg3);

	extern void* o_find_pattern;
	void* __cdecl find_pattern(HMODULE module, const std::string& sig, int unk);

	extern void* o_get_address_from_server;
	void* __cdecl get_address_from_server(int hash);

	extern void* o_get_interface;
	void* __cdecl get_interface(int hash);

	extern void* o_username1;
	char fix_username1();

	extern void* o_username2;
	char fix_username2();

	extern utils::vmthook surface;
	bool __fastcall set_font_glyph_set(void* ecx, void* edx, unsigned long font, const char* windows_font_name, int tall, int weight, int blur, int scanlines, int flags, int range_min, int range_max);
	void __fastcall draw_print_text(void* ecx, void* edx, const wchar_t* text, int len, int draw_type);
	void __fastcall get_text_size(void* ecx, void* edx, unsigned long font, const wchar_t* text, int& wide, int& tall);
}
