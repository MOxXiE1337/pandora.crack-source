#include <sdk/sdk.h>
#include <hooks/hooks.h>
#include <pandora/pandora.h>

namespace hooks
{
	void __fastcall draw_print_text(void* ecx, void* edx, const wchar_t* text, int len, int draw_type)
	{
		void* ret_addr;

		__asm 
		{
			mov eax, [ebp];
			mov eax, [eax];
			mov eax, [eax];
			mov eax, [eax];
			mov eax, [eax + 4];
			mov ret_addr, eax;
		}
	
#ifdef CN_VERSION

		for (auto i = pandora::sinicizations.find(ret_addr); i != pandora::sinicizations.end(); i++)
		{
			auto& pair = i->second;
			if (pair.first == text)
				return surface.get_func_address<decltype(&draw_print_text)>(28)(ecx, edx, pair.second.c_str(), pair.second.length(), draw_type);
		}

#endif // CN_VERSION

		return surface.get_func_address<decltype(&draw_print_text)>(28)(ecx, edx, text, len, draw_type);
	}
}