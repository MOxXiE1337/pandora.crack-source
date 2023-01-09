#include <utils/memory.h>

namespace utils
{
	void* find_pattern(void* addr, size_t size, const std::string& pattern)
	{
		BYTE* scan_start, * scan_end; 
		std::stringstream stream{ pattern };
		std::string c;
		std::vector<std::pair<BYTE, bool>> signature;

		if (!addr || !size || pattern.empty())
			return nullptr;

		while (stream >> c)
		{
			if (c[0] == '?')
				signature.push_back({ 0,true });
			else if (std::isxdigit(c[0]) && std::isxdigit(c[1]))
				signature.push_back({ (BYTE)std::strtoul(c.c_str(), 0, 16), false });
		}
		
		scan_start = (BYTE*)addr;
		scan_end = scan_start + size;

		BYTE* result = std::search(scan_start, scan_end, signature.begin(), signature.end(),
			[](const BYTE b, const std::pair<BYTE, bool>& p) {
				return b == p.first || p.second;
			});

		if (result == scan_end)
			return nullptr;

		return result;
	}

	void* find_pattern(HMODULE module, const std::string& pattern)
	{
		MODULEINFO module_info;
		GetModuleInformation(GetCurrentProcess(), module, &module_info, sizeof(MODULEINFO));
		return find_pattern(module_info.lpBaseOfDll, module_info.SizeOfImage, pattern);
	}

	void* find_pattern(const std::string& module_name, const std::string& pattern)
	{
		return find_pattern(GetModuleHandle(module_name.c_str()), pattern);
	}
}
