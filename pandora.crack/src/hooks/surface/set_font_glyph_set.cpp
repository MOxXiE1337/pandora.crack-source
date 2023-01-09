#include <hooks/hooks.h>

namespace hooks
{
	bool __fastcall set_font_glyph_set(void* ecx, void* edx, unsigned long font, const char* windows_font_name, int tall, int weight, int blur, int scanlines, int flags, int range_min, int range_max)
	{
		static int counter = 0;
		void* ret_addr;

		__asm
		{
			mov eax, [ebp + 4];
			mov ret_addr, eax;
		}

#ifdef CN_VERSION

		if (ret_addr >= (void*)0x40B50000 && ret_addr < (void*)0x4129C000)
		{
			counter++;
			if (counter <= 9)
			{
				if (!strcmp(windows_font_name, "Verdana"))
				{
					return surface.get_func_address<decltype(&set_font_glyph_set)>(72)(ecx, edx, font, windows_font_name, 14, 13, blur, scanlines, flags, range_min, range_max);
				}
			}
		}

#endif // CN_VERSION

		return surface.get_func_address<decltype(&set_font_glyph_set)>(72)(ecx, edx, font, windows_font_name, tall, weight, blur, scanlines, flags, range_min, range_max);
	}
}