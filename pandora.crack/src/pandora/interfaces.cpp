
#include <pandora/pandora.h>


namespace Pandora
{
	STD_UNORDERED_MAP<ULONG, STD_STRING>& Interfaces()
	{
		static STD_UNORDERED_MAP<ULONG, STD_STRING> interfaces;
		return interfaces;
	}


	VOID SetupInterfaces()
	{
		Interfaces()[0x5fde146] = "vgui2.VGUI_Panel009";
		Interfaces()[0xd3fdab8b] = "vguimatsurface.VGUI_Surface031";
		Interfaces()[0xc6842ceb] = "client.VClient018";
		Interfaces()[0xd59e08bc] = "engine.VEngineVGui001";
		Interfaces()[0xda84c74e] = "client.VClientEntityList003";
		Interfaces()[0xa86465d3] = "client.GameMovement001";
		Interfaces()[0x8c52abfc] = "client.VClientPrediction001";
		Interfaces()[0xd930954] = "engine.VEngineClient014";
		Interfaces()[0x32336da5] = "vstdlib.VEngineCvar007";
		Interfaces()[0xb3bbb7a0] = "engine.GAMEEVENTSMANAGER002";
		Interfaces()[0x94b38f98] = "engine.VEngineModel016";
		Interfaces()[0x49968254] = "materialsystem.VMaterialSystem080";
		Interfaces()[0xf4a1bfde] = "vphysics.VPhysicsSurfaceProps001";
		Interfaces()[0x192d1404] = "engine.EngineTraceClient004";
		Interfaces()[0x5ab298d2] = "engine.VModelInfoClient004";
		Interfaces()[0x9b334bcf] = "engine.VDebugOverlay004";
		Interfaces()[0xa29f0b66] = "engine.IEngineSoundClient003";
		Interfaces()[0x24b3ba6c] = "localize.Localize_001";
		Interfaces()[0xa1aeab7c] = "studiorender.VStudioRender026";
		Interfaces()[0xcaf0b530] = "engine.VEngineRenderView014";
		Interfaces()[0x9d6d78f] = "engine.VEngineClientStringTable001";
		Interfaces()[0xe533] = "client.ClientLeafSystem002";
		Interfaces()[0x9618a291] = "datacache.MDLCache004";
		Interfaces()[0x4d31455f] = "inputsystem.InputSystemVersion001";
		Interfaces()[0x24ea670b] = "vphysics.VPhysicsCollision007";
		Interfaces()[0x5c33c149] = "engine.VEngineEffects001";
	}
}