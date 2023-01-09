#pragma once
#include <includes.h>

namespace utils
{
	void* find_pattern(void* addr, size_t size, const std::string& pattern);
	void* find_pattern(HMODULE module, const std::string& pattern);
	void* find_pattern(const std::string& module_name, const std::string& pattern);
}
