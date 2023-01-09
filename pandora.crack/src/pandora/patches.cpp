#include <pandora/pandora.h>

namespace pandora
{
	void setup_patches()
	{
		memset((void*)0x410335EB, 0x90, 3);
		memset((void*)0x40DC8D70, 0x90, 8);
		memset((void*)0x40E5C274, 0x90, 8);

		BYTE patch1[6] = { 0xE9, 0x7A, 0x02, 0x00, 0x00, 0x90 };
		BYTE patch2[6] = { 0xE9, 0x7A, 0x02, 0x00, 0x00, 0x90 };
		BYTE patch3[6] = { 0xE9, 0xB0, 0x02, 0x00, 0x00, 0x90 };
		BYTE patch4[6] = { 0xE9, 0x7C, 0x02, 0x00, 0x00, 0x90 };
		BYTE patch5[6] = { 0xE9, 0x8C, 0x00, 0x00, 0x00, 0x90 };

		memcpy((void*)0x40FB8FDF, patch1, 6);
		memcpy((void*)0x40FB92CC, patch2, 6);
		memcpy((void*)0x40FBA4C3, patch3, 6);
		memcpy((void*)0x40FBB1DE, patch4, 6);
		memcpy((void*)0x40FBA42B, patch5, 6);

		*(BYTE*)0x40FB8F82 = 0xEB;
		*(BYTE*)0x40FB926F = 0xEB;
		*(BYTE*)0x40FBB182 = 0xEB;
		*(BYTE*)0x40DC8107 = 0x00;
		*(BYTE*)0x40FCC462 = 0x00;
		*(BYTE*)0x40FCC47B = 0x00;

		// idk why "pandora update detected"
		// patch MessageBoxA call
		memset((void*)0x40FB2500, 0x90, 28);
		// patch exit call 
		memset((void*)0x40FB2767, 0x90, 10);

		 
		// patch nt open file
		BYTE patch6[5] = { 0xB8,0x33,0x00,0x00,0x00 };
		void* nt_openfile = GetProcAddress(LoadLibrary("ntdll"), "NtOpenFile");
		DWORD old_protect;
		VirtualProtect(nt_openfile, 0x5, PAGE_EXECUTE_READWRITE, &old_protect);
		memcpy(nt_openfile, patch6, 5);
		VirtualProtect(nt_openfile, 0x5, old_protect, &old_protect);
	}
}