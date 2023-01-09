#include <sdk/sdk.h>
#include <hooks/hooks.h>
#include <utils/memory.h>
#include <pandora/pandora.h>

namespace hooks
{
	void* o_get_address_from_server;

	void* __cdecl get_address_from_server(int hash)
	{
		const auto& server_address_info = pandora::server_addresses[hash];
		void* fixed_address = utils::find_pattern(server_address_info.module_name, server_address_info.sig);

		if (fixed_address == nullptr)
		{
			CON_ERR("failed to fix server address (hash:%X)\n", hash);
			return nullptr;
		}
		return fixed_address;
	}
}