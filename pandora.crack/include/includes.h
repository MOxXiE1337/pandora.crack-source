#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

#define STD_PAIR std::pair
#define STD_VECTOR std::vector
#define STD_UNORDERED_MAP std::unordered_map

#define STD_STRING std::string
#define STD_STRINGSTREAM std::stringstream


#include <intrin.h>
#include <Windows.h>
#include <Psapi.h>
#include <ShlObj.h>

#define STDCALL __stdcall
#define FASTCALL __fastcall

#include <sys/stat.h>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Urlmon.lib")

