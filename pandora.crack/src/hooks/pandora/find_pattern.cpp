#include <sdk/sdk.h>
#include <hooks/hooks.h>
#include <utils/memory.h>
#include <pandora/pandora.h>

extern HMODULE g_loader_module;

namespace hooks
{
	void* o_find_pattern;

	void* __cdecl find_pattern(HMODULE module, const std::string& pattern, int unk)
	{
		void* addr = utils::find_pattern(module, pattern);
		if (addr == nullptr)
		{
			CON_ERR("failed to find pattern %p->%s\n!", module, pattern.c_str());
			Sleep(300);
			exit(0);
		}
		return addr;
	}
}