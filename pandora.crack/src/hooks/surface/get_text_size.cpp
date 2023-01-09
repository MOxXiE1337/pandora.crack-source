#include <sdk/sdk.h>
#include <hooks/hooks.h>
#include <pandora/pandora.h>

namespace hooks
{
	void __fastcall get_text_size(void* ecx, void* edx, unsigned long font, const wchar_t* text, int& wide, int& tall)
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
			auto &pair = i->second;
			if (pair.first == text)
				return surface.get_func_address<decltype(&get_text_size)>(79)(ecx, edx, font, pair.second.c_str(), wide, tall);
		}

#endif // CN_VERSION
		
		return surface.get_func_address<decltype(&get_text_size)>(79)(ecx, edx, font, text, wide, tall);
	}
}