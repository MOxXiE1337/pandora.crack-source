#include <sdk/sdk.h>
#include <hooks/hooks.h>
#include <utils/memory.h>
#include <pandora/pandora.h>

namespace hooks
{
	void* o_rebase_interface;

	void* __stdcall fix_interface(void* address)
	{
		const auto& interface_info = pandora::interface_addresses[address];
		void* fixed_address = sdk::CreateInterface<void*>(interface_info.module_name, interface_info.name, true);

		if (fixed_address == nullptr)
		{
			CON_ERR("failed to rebase interface %s\n", interface_info.name);
			Sleep(300);
			exit(0);
		}

		return fixed_address;
	}
}