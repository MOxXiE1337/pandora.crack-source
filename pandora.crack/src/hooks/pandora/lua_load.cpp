#include <hooks/hooks.h>
#include <pandora/pandora.h>

#define LUA_GLOBAL -10002 

decltype(&Hooks::lua_load) g_pOriginal_lua_load;

typedef void (*lua_pushinteger_fn)(void* L, int n);
typedef void (*lua_pushinteger_fn)(void* L, int n);
typedef void (*lua_pushstring_fn)(void* L, const char* s);
typedef void (*lua_setfield_fn)(void* L, int idx, const char* k);

namespace Hooks
{
	void* o_lua_load;

	int lua_load(void* L, void* reader, void* dt, const char* chunkname)
	{
		lua_pushinteger_fn lua_pushinteger = (lua_pushinteger_fn)Pandora::ImageBase(0x561CF0);
		lua_pushstring_fn lua_pushstring = (lua_pushstring_fn)Pandora::ImageBase(0x561E00);
		lua_setfield_fn lua_setfield = (lua_setfield_fn)Pandora::ImageBase(0x562270);
		lua_pushinteger_fn lua_push_integer = (lua_pushinteger_fn)Pandora::ImageBase(0x561CF0);

		std::string path = chunkname;
		lua_pushstring(L, path.substr(path.find_last_of('\\') + 1).c_str());
		lua_setfield(L, LUA_GLOBAL, "__FILE__"); // file name

		lua_pushinteger(L, (int)Pandora::ImageBase());
		lua_setfield(L, LUA_GLOBAL, "__IMAGEBASE__"); // imagebase

		lua_pushinteger(L, (int)Pandora::SegmentSize());
		lua_setfield(L, LUA_GLOBAL, "__IMAGESIZE__"); // imagesize

		return g_pOriginal_lua_load(L, reader, dt, chunkname);
	}
}