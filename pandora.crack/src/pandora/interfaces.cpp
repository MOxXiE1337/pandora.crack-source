#include <sdk/sdk.h>
#include <pandora/pandora.h>

#define INTERFACE_INFO(address) interface_addresses[(void*)address]

namespace pandora
{
	std::unordered_map<void*, interface_info_t> interface_addresses;

	void setup_interfaces()
	{
		INTERFACE_INFO(0x61cf08c4) = { "vgui2", "VGUI_Panel009" };
		INTERFACE_INFO(0x628847d0) = { "vguimatsurface", "VGUI_Surface031" };
		INTERFACE_INFO(0x2e6b7b18) = { "client", "VClient018" };
		INTERFACE_INFO(0x5416d0f8) = { "engine", "VEngineVGui001" };
		INTERFACE_INFO(0x2e6dce74) = { "client", "VClientEntityList003" };
		INTERFACE_INFO(0x2eb17ed0) = { "client", "GameMovement001" };
		INTERFACE_INFO(0x2eb1ade8) = { "client", "VClientPrediction001" };
		INTERFACE_INFO(0x50e1d3e0) = { "engine", "VEngineClient014" };
		INTERFACE_INFO(0x714ad310) = { "vstdlib", "VEngineCvar007" };
		INTERFACE_INFO(0x5109c4c8) = { "engine", "GAMEEVENTSMANAGER002" };
		INTERFACE_INFO(0x51004720) = { "engine", "VEngineModel016" };
		INTERFACE_INFO(0x62aa2ac8) = { "materialsystem", "VMaterialSystem080" };
		INTERFACE_INFO(0x70ff6078) = { "vphysics", "VPhysicsSurfaceProps001" };
		INTERFACE_INFO(0x50e273fc) = { "engine", "EngineTraceClient004" };
		INTERFACE_INFO(0x50E2D558) = { "engine", "VModelInfoClient004" };
		INTERFACE_INFO(0x50e1fea8) = { "engine", "VDebugOverlay004" };
		INTERFACE_INFO(0x50dae654) = { "engine", "IEngineSoundClient003" };
		INTERFACE_INFO(0x62788a70) = { "localize", "Localize_001" };
		INTERFACE_INFO(0x5567fe98) = { "studiorender", "VStudioRender026" };
		INTERFACE_INFO(0x50e21d0c) = { "engine", "VEngineRenderView014" };
		INTERFACE_INFO(0x50e2ee88) = { "engine", "VEngineClientStringTable001" };
		INTERFACE_INFO(0x2e6ecfc0) = { "client", "ClientLeafSystem002" };
		INTERFACE_INFO(0x69f64f18) = { "datacache", "MDLCache004" };
		INTERFACE_INFO(0x71065388) = { "inputsystem", "InputSystemVersion001" };
		INTERFACE_INFO(0x70feaa5c) = { "vphysics", "VPhysicsCollision007" };
		INTERFACE_INFO(0x50e21cec) = { "engine", "VEngineEffects001" };
	}
}