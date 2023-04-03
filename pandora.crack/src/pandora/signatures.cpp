#include <pandora/pandora.h>

namespace Pandora
{
	STD_UNORDERED_MAP<ULONG, STD_STRING>& Signatures()
	{
		static STD_UNORDERED_MAP<ULONG, STD_STRING> signatures;
		return signatures;
	}

	VOID SetupSignatures()
	{
		Signatures()[0xc05c64c] = "client.dll => [ 55 8B EC 83 E4 F8 83 EC 70 56 57 8B F9 89 7C 24 14 ]";
		Signatures()[0xc62aa8b3] = "client.dll => [ 8B B7 4C 29 00 00 89 74 24 20 ] ";
		Signatures()[0xf051208a] = "client.dll => [ 8D 8F 20 9B 00 00 6A 01 ] ";
		Signatures()[0x3ddb7621] = "client.dll => [ 8A 87 E1 35 00 00 ] ";
		Signatures()[0xb59e105e] = "client.dll => [ 55 8B EC 83 EC 10 53 56 57 8B 7D 10 ] ";
		Signatures()[0x78cce6d5] = "client.dll => [ 8B 35 ?? ?? ?? ?? FF 10 0F B7 C0 B9 ?? ?? ?? ?? 50 FF 56 ?? 85 C0 ] ";
		Signatures()[0x13d4aced] = "client.dll => [ 8D 87 68 0A 00 00 50 E8 ] ";
		Signatures()[0x8cc9ff64] = "client.dll => [ 89 86 10 29 00 00 ] ";
		Signatures()[0x9a0aaf49] = "client.dll => [ 8D 8F 70 CF 00 00 ] ";
		Signatures()[0x63aa2ad9] = "client.dll => [ 80 3D ?? ?? ?? ?? ?? 74 16 A1 ?? ?? ?? ?? 48 C7 81 28 29 00 00 FF FF 7F FF ] ";
		Signatures()[0xb313bdd1] = "client.dll => [ 8B 35 ?? ?? ?? ?? 8D 4C 24 20 ] ";
		Signatures()[0xcc702117] = "client.dll => [ 55 8B EC 83 E4 F0 81 EC 58 01 00 00 33 D2 ] ";
		Signatures()[0xd78f23e8] = "client.dll => [ FF B7 10 29 00 00 ] ";
		Signatures()[0xe6eaabdb] = "client.dll => [ 8B 89 90 29 00 00 8D 0C D1 ] ";
		Signatures()[0x321907d2] = "client.dll => [ FF 15 ?? ?? ?? ?? 80 BE 74 02 00 00 00 0F 84 98 02 00 00 ] ";
		Signatures()[0xf3dac366] = "client.dll => [ 8B 8F 6C 26 00 00 89 4C 24 1C ] ";
		Signatures()[0x5586ce17] = "client.dll => [ 8B 8E 60 99 00 00 85 C9 ] ";
		Signatures()[0x10081c3b] = "client.dll => [ 80 BF 14 9B 00 00 00 0F 84 ] ";
		Signatures()[0x1d72700c] = "client.dll => [ 55 8B EC 83 E4 F8 F3 0F 10 42 30 ] ";
		Signatures()[0x3720a12b] = "client.dll => [ 89 86 C0 03 01 00 ] ";
		Signatures()[0x8cb22e69] = "client.dll => [ E8 ?? ?? ?? ?? 8B 47 60 83 B8 9C 29 00 00 00 ] ";
		Signatures()[0x99688ee0] = "client.dll => [ 8D 8F 50 1C 01 00 ] ";
		Signatures()[0x1b88ce21] = "client.dll => [ 55 8B EC 83 E4 F8 83 EC 2C 53 8B D9 56 57 8B 03 ] ";
		Signatures()[0xdbc96a68] = "engine.dll => [ 75 30 8B 87 30 4D 00 00 ] ";
		Signatures()[0xb7a8a31a] = "client.dll => [ 80 BF 14 9B 00 00 00 0F 84 ] ";
		Signatures()[0xec372476] = "client.dll => [ 55 8B EC 83 E4 F0 81 EC 98 05 00 00 8B 81 F8 0F 00 00 ] ";
		Signatures()[0x9732dac4] = "client.dll => [ 80 BF 2C 2A 00 00 00 ] ";
		Signatures()[0xcb0e7fef] = "client.dll => [ 83 BE E8 09 00 00 00 7F 67 ] ";
		Signatures()[0x978d6f27] = "client.dll => [ E8 ?? ?? ?? ?? F3 0F 10 45 18 8D 84 24 90 00 00 00 ] ";
		Signatures()[0x630ba5f7] = "client.dll => [ C6 86 70 33 00 00 01 ] ";
		Signatures()[0x9665b249] = "client.dll => [ 56 8B F1 0F 57 C0 C7 86 80 00 00 00 00 00 00 00 ] ";
		Signatures()[0x49626569] = "client.dll => [ 55 8B EC 81 EC 88 00 00 00 56 8B F1 ] ";
		Signatures()[0xe6d497f8] = "client.dll => [ E8 ?? ?? ?? ?? FF 75 08 8B 8E 10 29 00 00 ] ";
		Signatures()[0x31512ec] = "client.dll => [ 53 8B D9 F6 C3 03 74 0B FF 15 ?? ?? ?? ?? 84 C0 74 01 CC C7 83 F0 0F 00 00 00 00 00 00 ] ";
		Signatures()[0xfc48a4be] = "client.dll => [ E8 ?? ?? ?? ?? 83 7E 10 00 74 64 ] ";
		Signatures()[0xddcd38fa] = "client.dll => [ E8 ?? ?? ?? ?? 8B 87 10 29 00 00 ] ";
		Signatures()[0x7bc3a8e] = "client.dll => [ 56 8B F1 57 8D 8E 10 10 00 00 ] ";
		Signatures()[0x953c420c] = "client.dll => [ 55 8B EC 83 EC 08 8B 45 08 56 57 8B F9 8D 8F FC 0F 00 00 ] ";
		Signatures()[0x96060043] = "server.dll => [ 8B 15 ?? ?? ?? ?? 33 C9 83 7A 18 01 7C 22 8B 52 60 85 D2 74 1B 8B 42 10 D1 E8 A8 01 75 12 8B 4A 1C 85 C9 74 09 8B 01 FF 50 ?? 8B C8 EB 02 33 C9 85 C9 ] ";
		Signatures()[0xbfbcf44e] = "client.dll => [ 55 8B EC 83 EC 10 53 8B D9 89 55 F8 ] ";
		Signatures()[0x596984ff] = "client.dll => [ 55 8B EC 83 E4 F0 B8 38 11 00 00 ] ";
		Signatures()[0xd112472a] = "client.dll => [ 55 8B EC 83 E4 F8 81 EC 90 00 00 00 8B C1 ] ";
		Signatures()[0x3ecb2b71] = "engine.dll => [ 74 0F 80 BF 48 4D 00 00 00 ] ";
		Signatures()[0x4911cf54] = "client.dll => [ 8B 0D ?? ?? ?? ?? BA ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 C4 04 ] ";
		Signatures()[0xb8cc797c] = "client.dll => [ 55 8B EC 83 EC 14 53 56 57 FF 75 18 ] ";
		Signatures()[0xf870ddb4] = "client.dll => [ 8B 0D ?? ?? ?? ?? 8B 46 08 68 ] ";
		Signatures()[0xaf26a26c] = "client.dll => [ B9 ?? ?? ?? ?? F3 0F 11 04 24 FF 50 ?? FF D7 ] ";
		Signatures()[0xf743cc72] = "client.dll => [ 89 35 ?? ?? ?? ?? F3 0F 10 48 20 ] ";
		Signatures()[0xac0a871d] = "client.dll => [ 83 3D ?? ?? ?? ?? ?? 7E 1C ] ";
		Signatures()[0xe335ec62] = "client.dll => [ A1 ?? ?? ?? ?? F6 44 F0 04 01 ] ";
		Signatures()[0xaf09d530] = "client.dll => [ 0F 11 05 ?? ?? ?? ?? 83 C8 01 ] ";
		Signatures()[0x1e63778c] = "client.dll => [ A1 ?? ?? ?? ?? FF 10 A1 ?? ?? ?? ?? B9 ] ";
		Signatures()[0x15218c62] = "client.dll => [ 56 8D 51 3C BE 03 00 00 00 ] ";
		Signatures()[0x73dfc8e3] = "client.dll => [ A3 ?? ?? ?? ?? 57 8B CB ] ";
		Signatures()[0xa20084df] = "client.dll => [ 0F 11 05 ?? ?? ?? ?? 0F 10 87 60 05 00 00 ] ";
		Signatures()[0xc5391d89] = "engine.dll => [ 03 05 ?? ?? ?? ?? 83 CF 10 ] ";
		Signatures()[0x39f9e956] = "server.dll => [ 8D 87 FC 03 00 00 89 46 08 C7 46 0C 00 00 00 00 EB 06 ] ";
		Signatures()[0xa892eacf] = "client.dll => [ A2 ?? ?? ?? ?? 8B 45 E8 ] ";
		Signatures()[0x53028691] = "server.dll => [ 8B 8F A8 2C 00 00 85 C9 74 06 ] ";
		Signatures()[0x76231ea1] = "engine.dll => [ 8B 1D ?? ?? ?? ?? 85 C0 74 16 FF B6 0C 01 00 00 ] ";
		Signatures()[0x7ebd80c5] = "client.dll => [ 55 8B EC A1 ?? ?? ?? ?? 83 EC 10 56 8B F1 B9 ] ";
		Signatures()[0xd4e84b87] = "server.dll => [ FF 86 6C 12 00 00 ] ";
		Signatures()[0x115bb8b] = "client.dll => [ B9 ?? ?? ?? ?? E8 ?? ?? ?? ?? 8B 5D 08 85 C0 ] ";
		Signatures()[0x6bd5b6c] = "client.dll => [ 56 52 FF 50 ?? 89 44 24 14 ] ";
		Signatures()[0xb0df5d2b] = "client.dll => [ 3B 3D ?? ?? ?? ?? 75 4C ] ";
		Signatures()[0x1bc424b9] = "engine.dll => [ 55 8B EC 83 EC 08 56 8B F1 8B 4D 04 ] ";
		Signatures()[0x8675e72a] = "shaderapidx9.dll => [ A1 ?? ?? ?? ?? 50 8B 08 FF 51 ?? 85 C0 ] ";
		Signatures()[0xf836ab50] = "client.dll => [ 55 8B EC 83 EC 1C 8B 0D ?? ?? ?? ?? 53 ] ";
		Signatures()[0x670a12b6] = "client.dll => [ E8 ?? ?? ?? ?? FF 76 0C 8D 48 04 ] ";
		Signatures()[0x73baa13f] = "client.dll => [ 0F B7 05 ?? ?? ?? ?? 3D FF FF 00 00 74 3F ] ";
		Signatures()[0x499832fe] = "engine.dll => [ 85 C0 74 12 53 FF 75 0C 68 ] ";
		Signatures()[0x73341dc1] = "engine.dll => [ 55 8B EC 83 E4 F0 B8 38 01 10 00 ] ";
		Signatures()[0x17603a3] = "engine.dll => [ 55 8B EC 83 E4 C0 81 EC B4 00 00 00 53 56 57 8B 7D 08 8B D9 ] ";
		Signatures()[0x6142d525] = "client.dll => [ 6A 00 FF 50 ?? 8B 0D ?? ?? ?? ?? FF B7 AC 01 00 00 ] ";
		Signatures()[0x594a61b] = "client.dll => [ 84 C0 74 17 8B 87 44 0A 00 00 ] ";
		Signatures()[0x2c787d88] = "client.dll => [ E8 ?? ?? ?? ?? 5E 83 F8 FF ] ";
		Signatures()[0x54a13745] = "client.dll => [ E8 ?? ?? ?? ?? 8B F0 C6 44 24 0E 01 ] ";
		Signatures()[0x3e384190] = "client.dll => [ 0F 10 05 ?? ?? ?? ?? 8D 85 78 FE FF FF ] ";
		Signatures()[0x59f94af0] = "client.dll => [ FF D0 A1 ?? ?? ?? ?? B9 ] ";
		Signatures()[0x8add58a5] = "client.dll => [ 84 C0 75 38 8B 0D ?? ?? ?? ?? 8B 01 8B 80 48 01 00 00 ] ";
		Signatures()[0x38593d23] = "client.dll => [ 55 8B EC 56 8B F1 B9 14 00 00 00 ] ";
		Signatures()[0x7d1aae8a] = "client.dll => [ 84 C0 75 0D F6 87 28 0A 00 00 0A ] ";
		Signatures()[0x3dbe64f] = "client.dll => [ 55 8B EC 83 E4 F8 8B 4D 08 BA ?? ?? ?? ?? E8 ?? ?? ?? ?? 85 C0 75 12 ] ";
		Signatures()[0x305a6de2] = "client.dll => [ E8 ?? ?? ?? ?? F3 0F 10 4D F4 83 C4 08 ] ";
		Signatures()[0x12bbf342] = "client.dll => [ 55 8B EC 57 8B F9 8B 97 9C 29 00 00 ] ";
		Signatures()[0xe80b17ba] = "client.dll => [ 55 8B EC 83 EC 08 53 56 8B F1 57 89 75 F8 ] ";
		Signatures()[0xecfdb4d4] = "client.dll => [ 55 8B EC 56 57 8B F9 8B B7 E8 00 00 00 ] ";
		Signatures()[0xe23ab8c6] = "client.dll => [ FF 90 ?? ?? ?? ?? FF 35 ?? ?? ?? ?? 8B 4C 24 3C ] ";
		Signatures()[0x2bfe6e6a] = "client.dll => [ FF 90 ?? ?? ?? ?? 8B 86 FC 00 00 00 ] ";
		Signatures()[0xfae77068] = "client.dll => [ 8B 0D ?? ?? ?? ?? 85 C0 74 0A 8B 01 FF 50 ?? 83 C0 54 ] ";
		Signatures()[0xbb57d72e] = "client.dll => [ 84 C0 75 05 B0 01 ] ";
		Signatures()[0x1019e968] = "client.dll => [ FF 50 ?? 8B 4C 24 20 8B 54 24 1C ] ";
		Signatures()[0x311eba0b] = "client.dll => [ 0F 82 ?? ?? ?? ?? FF 50 ] ";
		Signatures()[0x9ffa7202] = "client.dll => [ FF B7 B0 01 00 00 8B 01 FF 90 ?? ?? ?? ?? 8B 4C 24 24 ] ";
		Signatures()[0x138a731c] = "engine.dll => [ 53 8A D9 8B 0D ?? ?? ?? ?? 56 57 8B B9 0C 10 00 00 ] ";
		Signatures()[0xf52f3daf] = "client.dll => [ 55 8B EC 83 E4 F8 83 EC 34 53 8B 5D 0C 89 4C 24 04 ] ";
		Signatures()[0xb52fc3ae] = "client.dll => [ 55 8B EC 51 33 C0 C7 45 FC FF FF FF FF 56 8B F1 81 26 00 00 00 FF C6 46 03 00 89 46 10 89 46 14 88 46 18 89 46 20 89 46 1C 89 46 24 89 46 04 89 46 08 89 46 0C FF 15 ?? ?? ?? ?? 6A 01 FF 75 08 8D 4D FC 8B 10 51 8B C8 FF 52 ?? 8B 0E 33 4D FC 81 E1 FF FF FF 00 31 0E 8B CE 6A 01 FF 75 0C 88 46 03 C1 F8 08 66 89 46 12 E8 ?? ?? ?? ?? 85 C0 74 0A FF 75 10 8B C8 E8 ?? ?? ?? ?? 8B C6 ] ";
		Signatures()[0x6ab01334] = "client.dll => [ C6 05 ?? ?? ?? ?? ?? 89 47 70 ] ";
		Signatures()[0x421f595f] = "client.dll => [ C6 05 ?? ?? ?? ?? ?? 88 81 ?? ?? ?? ?? F3 0F 10 4E 08 ] ";
		Signatures()[0x25e734a6] = "client.dll => [ FF 90 ?? ?? ?? ?? 83 3D ?? ?? ?? ?? ?? 7E 1C ] ";
		Signatures()[0x6957056] = "client.dll => [ C7 87 24 30 00 00 00 00 00 00 ] ";
		Signatures()[0x13bbf3d9] = "client.dll => [ FF 90 ?? ?? ?? ?? 8B 07 8B CF FF 90 ?? ?? ?? ?? 8B CF ] ";
		Signatures()[0x53b94e91] = "client.dll => [ 55 8B EC 83 E4 F8 51 53 56 57 8B F1 E8 ?? ?? ?? ?? 8B 7D 08 ] ";
		Signatures()[0x20277296] = "engine.dll => [ 56 57 8B F9 8D 4F 08 C7 07 ?? ?? ?? ?? E8 ?? ?? ?? ?? C7 07 ] ";
		Signatures()[0x4bde48a2] = "engine.dll => [ 55 8B EC 80 7D 0C 00 F3 0F 10 4D 08 ] ";
		Signatures()[0x50a6b538] = "client.dll => [ 55 8B EC 83 E4 F8 83 EC 64 53 56 57 8B F1 ] ";
		Signatures()[0xcecc2b87] = "engine.dll => [ 55 8B EC 81 EC 64 01 00 00 ] ";
		Signatures()[0x5bfe5118] = "client.dll => [ 55 8B EC 51 56 8B F1 85 F6 74 68 ] ";
		Signatures()[0xe5193f4c] = "engine.dll => [ 55 8B EC 81 EC 34 01 00 00 56 ] ";
		Signatures()[0xb8a03746] = "client.dll => [ 56 6A 01 68 ?? ?? ?? ?? 8B F1 ] ";
		Signatures()[0xb79c175a] = "client.dll => [ 55 8B EC 83 E4 F8 83 EC 18 56 57 8B F9 F3 0F 11 54 24 0C ] ";
		Signatures()[0xc9707da1] = "engine.dll => [ 53 56 57 8B DA 8B F9 FF 15 ] ";
		Signatures()[0x99feee76] = "client.dll => [ 55 8B EC 53 8B 5D 08 56 8B F1 83 FB FF ] ";
		Signatures()[0xefee5c50] = "client.dll => [ E8 ?? ?? ?? ?? 80 BE F8 13 00 00 00 ] ";
		Signatures()[0x7a1307b] = "engine.dll => [ E8 ?? ?? ?? ?? 84 C0 8B 45 08 ] ";
		Signatures()[0x2d81357e] = "client.dll => [ 55 8B EC 83 E4 F8 83 EC 0C 53 8B 5D 08 8B C3 ] ";
		Signatures()[0xd0ec62ed] = "client.dll => [ E8 ?? ?? ?? ?? 8B CF E8 ?? ?? ?? ?? 8B 06 ] ";
		Signatures()[0x757b85ad] = "client.dll => [ 55 8B EC 83 EC 10 53 56 57 8B F9 8B 87 E8 00 00 00 ] ";
		Signatures()[0x29507176] = "client.dll => [ 56 8B F1 57 8B BE 5C 34 00 00 ] ";
		Signatures()[0xe644aae4] = "client.dll => [ 55 8B EC 83 EC 0C 53 56 8B 71 58 ] ";
		Signatures()[0x8a0c5015] = "client.dll => [ 55 8B EC 53 8B 5D 08 56 57 8B F9 33 F6 39 77 28 ] ";
		Signatures()[0x25ae6768] = "client.dll => [ 53 8B DC 83 EC 08 83 E4 F8 83 C4 04 55 8B 6B 04 89 6C 24 04 8B EC 83 EC 18 56 57 8B 7B 08 ] ";
		Signatures()[0xd34fe914] = "client.dll => [ 55 8B EC 83 E4 F8 83 EC 70 6A 58 ] ";
		Signatures()[0x1b1e1674] = "client.dll => [ 55 8B EC 83 E4 F8 51 53 56 8B D9 ] ";
		Signatures()[0xeb5eae36] = "engine.dll => [ 55 8B EC 53 8B 5D 08 56 8B F1 85 DB 74 57 8B 4E 14 83 F9 10 72 04 8B 06 EB 02 8B C6 3B D8 72 45 83 F9 10 72 04 8B 16 EB 02 8B D6 8B 46 10 03 C2 3B C3 76 31 83 F9 10 72 16 FF 75 0C 8B 06 8B CE 2B D8 53 56 E8 ?? ?? ?? ?? 5E 5B 5D C2 08 00 FF 75 0C 8B C6 8B CE 2B D8 53 56 E8 ?? ?? ?? ?? 5E 5B 5D C2 08 00 57 ] ";
		Signatures()[0x5342b4b9] = "client.dll => [ 55 8B EC 8B 45 08 57 8B F9 8B 4F 04 85 C9 75 15 ] ";
		Signatures()[0xf70e7841] = "client.dll => [ 55 8B EC 83 EC 48 53 8B 5D 08 ] ";
		Signatures()[0xbb70a21] = "client.dll => [ E8 ?? ?? ?? ?? 8D 47 FC ] ";
		Signatures()[0x3a5c86c0] = "client.dll => [ 55 8B EC 83 EC 08 8B 15 ?? ?? ?? ?? 0F 57 C0 ] ";
		Signatures()[0xdfdf2d44] = "client.dll => [ E8 ?? ?? ?? ?? A1 ?? ?? ?? ?? F3 0F 10 45 F4 ] ";
		Signatures()[0xe46b563d] = "client.dll => [ 55 8B EC 83 E4 F0 83 EC 7C 56 52 ] ";
		Signatures()[0x5aa72a66] = "client.dll => [ FF 50 ?? 8B 06 8D 4D F4 51 8B CE FF 90 ?? ?? ?? ?? 8B 7D 08 ] ";
		Signatures()[0x6876f4c3] = "client.dll => [ 8D 8A 1C 02 00 00 ] ";
		Signatures()[0x723e15e4] = "client.dll => [ 74 43 8B 81 58 01 00 00 ] ";
		Signatures()[0x1b89c3bc] = "client.dll => [ A1 ?? ?? ?? ?? 56 8B F1 B9 ?? ?? ?? ?? FF 50 ?? 85 C0 0F 85 22 01 00 00 ] ";
		Signatures()[0xa876ae7d] = "client.dll => [ 56 8B F1 8B 8E 08 03 00 00 83 F9 FF 74 23 ] ";
		Signatures()[0x8004aed0] = "engine.dll => [ 8B 0D ?? ?? ?? ?? 8D 95 7C FD FF FF ] ";
		Signatures()[0xc5793d88] = "engine.dll => [ 55 8B EC 81 EC 58 0B 00 00 ] ";
		Signatures()[0x60c4477d] = "client.dll => [ 55 8B EC 83 E4 F0 83 EC 78 56 8B F1 57 8B 56 60 ] ";
		Signatures()[0xbce6e7c4] = "client.dll => [ 55 8B EC 51 56 8B F1 80 BE 14 9B 00 00 00 ] ";
		Signatures()[0xd0eeaf62] = "shaderapidx9.dll => [ 55 8B EC 83 E4 F8 81 EC BC 00 00 00 ] ";
		Signatures()[0x123e9d18] = "client.dll => [ 55 8B EC 80 7D 08 00 B8 00 20 00 00 ] ";
		Signatures()[0xcb538045] = "client.dll => [ 55 8B EC 81 EC 8C 00 00 00 57 8B F9 8B 87 54 0E 00 00 ] ";
		Signatures()[0x3251114e] = "client.dll => [ 55 8B EC 83 E4 F8 83 EC 0C 53 56 8B F1 57 83 BE 50 29 00 00 00 ] ";
		Signatures()[0xa41c71e3] = "client.dll => [ E8 ?? ?? ?? ?? 83 C4 10 EB 79 ] ";
		Signatures()[0x2575fe5f] = "client.dll => [ 55 8B EC 83 E4 F8 83 EC 34 53 56 8B 75 08 33 DB ] ";
		Signatures()[0x643339f] = "engine.dll => [ E8 ?? ?? ?? ?? 84 DB 0F 84 95 00 00 00 ] ";
		Signatures()[0x863cf8f4] = "client.dll => [ E8 ?? ?? ?? ?? 8B 87 44 0A 00 00 ] ";
		Signatures()[0xd2c3d726] = "client.dll => [ E8 ?? ?? ?? ?? 80 BE 14 9B 00 00 00 0F 84 ?? ?? ?? ?? 83 BE 60 99 00 00 00 0F 84 ?? ?? ?? ?? B8 FF FF 00 00 ] ";
		Signatures()[0x24f63b92] = "client.dll => [ E8 ?? ?? ?? ?? 5E 5D C2 10 00 32 C0 ] ";
		Signatures()[0x8a3b6999] = "client.dll => [ 55 8B EC 83 E4 F8 81 EC FC 00 00 00 53 56 ] ";
		Signatures()[0x4c344c58] = "engine.dll => [ E8 ?? ?? ?? ?? FF 76 60 ] ";
		Signatures()[0x86772ad2] = "engine.dll => [ 55 8B EC 83 E4 C0 81 EC 74 01 00 00 53 56 8B D9 ] ";
		Signatures()[0x2c7b2313] = "vstdlib.dll => [ 55 8B EC 8B 01 56 FF 75 08 FF 50 3C 8B F0 85 F6 74 1E ] ";
		Signatures()[0xf8bf90da] = "client.dll => [ 55 8B EC 51 A1 ?? ?? ?? ?? 53 56 8B D9 ] ";
		Signatures()[0x4b36571] = "client.dll => [ 55 8B EC 8B 45 10 F3 0F 10 81 B4 00 00 00 ] ";
	}
}