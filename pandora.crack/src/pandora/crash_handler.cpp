#include <string>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <Psapi.h>
#include <TlHelp32.h>

extern HMODULE g_loader_module;

template <typename T>
std::string tohex(T arg)
{
	std::string result;
	std::stringstream stream;
	stream << std::hex << std::uppercase << arg;
	stream >> result;
	return "0x" + result;
}

struct module_info_t
{
	std::string name;
	void* begin;
	void* end;
};

std::string get_offset_to_module(void* address)
{
	static std::vector<module_info_t> modules;
	 
	if (modules.empty())
	{
		HANDLE snap_shot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, 0);
		MODULEENTRY32 mi;
		mi.dwSize = sizeof(MODULEENTRY32);
		BOOL ret = Module32First(snap_shot, &mi);
		while (ret)
		{
			modules.push_back({ mi.szModule,mi.modBaseAddr,mi.modBaseAddr + mi.modBaseSize });
			ret = Module32Next(snap_shot, &mi);
		}
		MODULEINFO module_info;
		GetModuleInformation(0, g_loader_module, &module_info, sizeof(MODULEINFO));
		modules.push_back({ "pandora.loader",(void*)g_loader_module,(BYTE*)g_loader_module + module_info.SizeOfImage });
		modules.push_back({ "pandora.crack",(void*)0x40B50000,(void*)0x4129C000 });
	}

	for (auto& i : modules)
	{
		if (address >= i.begin && address < i.end)
		{
			DWORD offset = (BYTE*)address - (BYTE*)i.begin;
			return i.name + " + " + tohex(offset);
		}
	}
	return tohex(address);
}


namespace pandora
{
	LONG NTAPI crash_handler(struct _EXCEPTION_POINTERS* exception_info)
	{
		if (exception_info->ExceptionRecord->ExceptionCode == 0xC0000005)
		{
			std::string msg = "address: ";
			msg += get_offset_to_module(exception_info->ExceptionRecord->ExceptionAddress) + "\ncode: ";
			msg += tohex(exception_info->ExceptionRecord->ExceptionCode) + "\nregisters:";
			msg += "\n    eax: ";
			msg += tohex(exception_info->ContextRecord->Eax);
			msg += "\n    ecx: ";
			msg += tohex(exception_info->ContextRecord->Ecx);
			msg += "\n    edx: ";
			msg += tohex(exception_info->ContextRecord->Edx);
			msg += "\n    ebx: ";
			msg += tohex(exception_info->ContextRecord->Ebx);
			msg += "\n    ebp: ";
			msg += tohex(exception_info->ContextRecord->Ebp);
			msg += "\n    esp: ";
			msg += tohex(exception_info->ContextRecord->Esp);
			msg += "\ncall stack:";
			void* ebp = (void*)exception_info->ContextRecord->Ebp;

			// for each stack
			while (ebp != nullptr)
			{
				void* ret_addr = *(void**)((BYTE*)ebp + 4);
				if (ret_addr == nullptr)
					break;
				msg += "\n    " + get_offset_to_module(ret_addr);
				ebp = *(void**)ebp;
			}

			msg += "\nplease take a screenshot and send it to https://discord.gg/WQJwZDm9Dz";

			MessageBox(FindWindow("Valve001", NULL), msg.c_str(), "pandora.crack crashed!", MB_ICONERROR);
			exit(exception_info->ExceptionRecord->ExceptionCode);
		}
		
		return EXCEPTION_CONTINUE_EXECUTION;
	}
}