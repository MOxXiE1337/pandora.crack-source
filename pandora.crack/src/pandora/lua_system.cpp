#include <sdk/sdk.h>
#include <pandora/pandora.h>
#include <json/ejson.h>

extern HMODULE g_loader_module;

void download_libs(const std::string& name)
{
	Json::Value json = pandora::lib_list[name];

	if (json.isMember("lib"))
	{
		Json::Value array = json["lib"];
		for (unsigned int i = 0; i < array.size(); i++)
		{
			Json::Value obj = array[i];
			std::string path = obj["path"].asString();
			std::string url = obj["url"].asString();
			remove(path.c_str());
			HRESULT result = URLDownloadToFileA(NULL, url.c_str(), path.c_str(), 0, NULL);
			if (result != S_OK)
			{
				CON_ERR("failed to download \"%s\"\n", path.c_str());
				continue;
			}
		}
	}
	if (json.isMember("clib"))
	{
		Json::Value array = json["clib"];
		for (unsigned int i = 0; i < array.size(); i++)
		{
			Json::Value obj = array[i];
			std::string path = obj["path"].asString();
			std::string url = obj["url"].asString();
			remove(path.c_str());
			HRESULT result = URLDownloadToFileA(NULL, url.c_str(), path.c_str(), 0, NULL);
			if (result != S_OK)
			{
				CON_ERR("failed to download \"%s\"\n", path.c_str());
				continue;
			}
		}
	}
}

namespace pandora
{
	Json::Value lib_list;

	void setup_lua_system()
	{
		Json::Value::Members members;

		_wmkdir(L"pandora/lib");
		_wmkdir(L"pandora/clib");

		// delete old lib_list
		remove("pandora/lib_list.json");

		// download newest lib_list
		HRESULT result = URLDownloadToFileA(NULL,
			"https://raw.githubusercontent.com/MOxXiE1337/pandora.crack/main/lib_list.json",
			"pandora/lib_list.json", 0, NULL);

		if (result != S_OK)
		{
			CON_ERR("failed to download library list!\n");
			goto QUIT;
		}

		bool succeeded;
		lib_list = Json::ReadJsonFile("Pandora/lib_list.json", succeeded);

		if (!succeeded)
		{
			CON_ERR("failed to load library list!\n");
			goto QUIT;
		}	

		members = lib_list.getMemberNames(); 
		for (Json::Value::Members::iterator iter = members.begin(); iter != members.end(); iter++)
		{
			std::string name = *iter;
			
			download_libs(name);
		}

		return;
	QUIT:
		FreeLibraryAndExitThread(g_loader_module, 0);
	}
}