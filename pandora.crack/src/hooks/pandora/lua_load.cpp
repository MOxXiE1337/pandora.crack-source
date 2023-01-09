#include <sdk/sdk.h>
#include <hooks/hooks.h>
#include <pandora/pandora.h>

typedef void  (*lua_pushinteger_fn)(void* L, int n);
typedef void (*lua_pushstring_fn)(void* L, const char* s);
typedef void (*lua_setfield_fn)(void* L, int idx, const char* k);

lua_pushinteger_fn lua_pushinteger = (lua_pushinteger_fn)0x410B1CF0;
lua_pushstring_fn lua_pushstring = (lua_pushstring_fn)0x410B1E00;
lua_setfield_fn lua_setfield = (lua_setfield_fn)0x410B2270;

namespace hooks
{
	void* o_lua_load;

	int lua_load(void* L, void* reader, void* dt, const char* chunkname)
	{
		// i dont wanna let you know these, for callbacksex or other uses
		lua_pushinteger(L, (int)L);
		lua_setfield(L, -10002, "ee55947e_7bb8_86c0_2f01_2168a1dd7847"); // lua state
		std::string path = chunkname;
		lua_pushstring(L, path.substr(path.find_last_of('\\') + 1).c_str());
		lua_setfield(L, -10002, "e9319306_721a_064e_43a0_68259aa188eb"); // lua name
		return decltype(&lua_load)(o_lua_load)(L, reader, dt, chunkname);
	}
}