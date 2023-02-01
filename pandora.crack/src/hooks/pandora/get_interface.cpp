#include <sdk/sdk.h>
#include <hooks/hooks.h>
#include <utils/memory.h>
#include <pandora/pandora.h>

namespace hooks
{
	void* o_get_interface;

	void* __cdecl get_interface(int hash)
	{
		const auto& interface_info = pandora::interface_addresses[hash];
		void* fixed_address = sdk::CreateInterface<void*>(interface_info.module_name, interface_info.name, true);

		if (fixed_address == nullptr)
		{
			CON_ERR("failed to fix interface %s\n", interface_info.name);
			Sleep(300);
			exit(0);
		}

		return fixed_address;
	}
}