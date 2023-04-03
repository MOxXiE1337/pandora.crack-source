#include <pandora/pandora.h>

namespace Pandora
{
	VOID SetupRelocations()
	{
		PIMAGE_BASE_RELOCATION pLoc = (PIMAGE_BASE_RELOCATION)(SegmentData() + 0x725000);

		while ((pLoc->VirtualAddress + pLoc->SizeOfBlock) != 0)
		{
			WORD* pLocData = (WORD*)((DWORD)pLoc + sizeof(IMAGE_BASE_RELOCATION));
			SIZE_T nRelocNum = (pLoc->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);
			for (SIZE_T i = 0; i < nRelocNum; i++)
			{
				if ((DWORD)(pLocData[i] & 0xF000) == 0x00003000 || (DWORD)(pLocData[i] & 0xF000) == 0x0000A000)
				{
					DWORD* pAddress = (DWORD*)((PBYTE)ImageBase() + pLoc->VirtualAddress + (pLocData[i] & 0x0FFF));
					*pAddress += (DWORD)ImageBase() - 0x40B50000; 
				}
			}
			pLoc = (PIMAGE_BASE_RELOCATION)((DWORD)pLoc + pLoc->SizeOfBlock);
		}
	}
}