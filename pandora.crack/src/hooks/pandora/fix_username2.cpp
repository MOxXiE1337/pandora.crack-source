#include <hooks/hooks.h>

namespace hooks
{
	void* o_username2;

	char fix_username2()
	{
		static size_t i = 0;
		static const char* name = "PinkKing   ";
		char character = name[i];
		i++;
		if (i >= strlen(name))
			i = 0;
		__asm
		{
			mov dl, character;
			mov esp, ebp;
			pop ebp;
			ret;
		}
	}
}