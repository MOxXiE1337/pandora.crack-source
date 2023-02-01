#include <sdk/sdk.h>
#include <pandora/pandora.h>

#define INTERFACE_INFO(hash) interface_addresses[hash]

namespace pandora
{
	std::unordered_map<int, interface_info_t> interface_addresses;

	void setup_interfaces()
	{
		INTERFACE_INFO(0x5fde146) = { "vgui2", "VGUI_Panel009" };
		INTERFACE_INFO(0xd3fdab8b) = { "vguimatsurface", "VGUI_Surface031" };
		INTERFACE_INFO(0xc6842ceb) = { "client", "VClient018" };
		INTERFACE_INFO(0xd59e08bc) = { "engine", "VEngineVGui001" };
		INTERFACE_INFO(0xda84c74e) = { "client", "VClientEntityList003" };
		INTERFACE_INFO(0xa86465d3) = { "client", "GameMovement001" };
		INTERFACE_INFO(0x8c52abfc) = { "client", "VClientPrediction001" };
		INTERFACE_INFO(0xd930954) = { "engine", "VEngineClient014" };
		INTERFACE_INFO(0x32336da5) = { "vstdlib", "VEngineCvar007" };
		INTERFACE_INFO(0xb3bbb7a0) = { "engine", "GAMEEVENTSMANAGER002" };
		INTERFACE_INFO(0x94b38f98) = { "engine", "VEngineModel016" };
		INTERFACE_INFO(0x49968254) = { "materialsystem", "VMaterialSystem080" };
		INTERFACE_INFO(0xf4a1bfde) = { "vphysics", "VPhysicsSurfaceProps001" };
		INTERFACE_INFO(0x192d1404) = { "engine", "EngineTraceClient004" };
		INTERFACE_INFO(0x5ab298d2) = { "engine", "VModelInfoClient004" };
		INTERFACE_INFO(0x9b334bcf) = { "engine", "VDebugOverlay004" };
		INTERFACE_INFO(0xa29f0b66) = { "engine", "IEngineSoundClient003" };
		INTERFACE_INFO(0x24b3ba6c) = { "localize", "Localize_001" };
		INTERFACE_INFO(0xa1aeab7c) = { "studiorender", "VStudioRender026" };
		INTERFACE_INFO(0xcaf0b530) = { "engine", "VEngineRenderView014" };
		INTERFACE_INFO(0x9d6d78f) = { "engine", "VEngineClientStringTable001" };
		INTERFACE_INFO(0xe533) = { "client", "ClientLeafSystem002" };
		INTERFACE_INFO(0x9618a291) = { "datacache", "MDLCache004" };
		INTERFACE_INFO(0x4d31455f) = { "inputsystem", "InputSystemVersion001" };
		INTERFACE_INFO(0x24ea670b) = { "vphysics", "VPhysicsCollision007" };
		INTERFACE_INFO(0x5c33c149) = { "engine", "VEngineEffects001" };
	}
}