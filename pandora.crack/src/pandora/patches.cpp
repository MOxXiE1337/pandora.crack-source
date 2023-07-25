#include <pandora/pandora.h>

namespace Pandora
{
	void SetupPatches()
	{
		memset(ImageBase(0x278D70), 0x90, 8);
		memset(ImageBase(0x30C274), 0x90, 8);

		BYTE patch1[6] = { 0xE9, 0x7A, 0x02, 0x00, 0x00, 0x90 };
		BYTE patch2[6] = { 0xE9, 0x7A, 0x02, 0x00, 0x00, 0x90 };
		BYTE patch3[6] = { 0xE9, 0xB0, 0x02, 0x00, 0x00, 0x90 };
		BYTE patch4[6] = { 0xE9, 0x7C, 0x02, 0x00, 0x00, 0x90 };
		BYTE patch5[6] = { 0xE9, 0x8C, 0x00, 0x00, 0x00, 0x90 };
	
		memcpy(ImageBase(0x468FDF), patch1, 6);
		memcpy(ImageBase(0x4692CC), patch2, 6);
		memcpy(ImageBase(0x46A4C3), patch3, 6);
		memcpy(ImageBase(0x46B1DE), patch4, 6);
		memcpy(ImageBase(0x46A42B), patch5, 6);

		*(BYTE*)ImageBase(0x468F82) = 0xEB;
		*(BYTE*)ImageBase(0x46926F) = 0xEB;
		*(BYTE*)ImageBase(0x46B182) = 0xEB;
		*(BYTE*)ImageBase(0x278107) = 0x00;
		*(BYTE*)ImageBase(0x47C462) = 0x00;
		*(BYTE*)ImageBase(0x47C47B) = 0x00;

		// idk why "pandora update detected"
		// patch MessageBoxA call
		// memset((void*)0x40FB2500, 0x90, 28);
		// patch exit call 
		// memset((void*)0x40FB2767, 0x90, 10);
	}
}