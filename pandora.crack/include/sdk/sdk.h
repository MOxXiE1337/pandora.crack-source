#pragma once
#include <includes.h>

#include "interfaces/ICvar.h"

#include "misc/interface.h"

namespace sdk
{
	template <typename T>
	static T CreateInterface(const std::string& module_name, const std::string& interface_name, bool exact = false) {
		T iface = nullptr;
		InterfaceReg* register_list;
		int part_match_len = interface_name.length();

		uintptr_t interface_fn = (uintptr_t)(GetProcAddress(GetModuleHandle(module_name.c_str()), "CreateInterface"));

		if (!interface_fn)
			return nullptr;

		uintptr_t jump_start = (uintptr_t)(interface_fn) + 4;
		uintptr_t jump_target = jump_start + *(uintptr_t*)(jump_start + 1) + 5;

		register_list = **(InterfaceReg***)(jump_target + 6);

		for (InterfaceReg* cur = register_list; cur; cur = cur->m_pNext) {
			if (exact == true) {
				if (interface_name == cur->m_pName)
					iface = (T)(cur->m_CreateFn());
			}
			else {
				if (!strncmp(cur->m_pName, interface_name.c_str(), part_match_len) && std::atoi(cur->m_pName + part_match_len) > 0)
					iface = (T)(cur->m_CreateFn());
			}
		}
		return iface;
	}

	template <typename T>
	static void ForEachInterfaces(const std::string& module_name, T func)
	{
		InterfaceReg* register_list;

		uintptr_t interface_fn = (uintptr_t)(GetProcAddress(GetModuleHandle(module_name.c_str()), "CreateInterface"));

		if (!interface_fn)
			return;

		uintptr_t jump_start = (uintptr_t)(interface_fn)+4;
		uintptr_t jump_target = jump_start + *(uintptr_t*)(jump_start + 1) + 5;
		register_list = **(InterfaceReg***)(jump_target + 6);

		for (InterfaceReg* cur = register_list; cur; cur = cur->m_pNext) 
		{
			func(cur->m_pName, cur->m_CreateFn());
		}
	}

	static ICvar* Cvar()
	{
		static ICvar* s_cvar = nullptr;
		if (s_cvar == nullptr)
			s_cvar = CreateInterface<ICvar*>("vstdlib.dll", "VEngineCvar");
		return s_cvar;
	}
}
