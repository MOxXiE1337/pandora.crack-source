#pragma once
#define NOMINMAX

#include <Windows.h>
#include <cstdint>
#include <stdexcept>
#include <assert.h>

namespace utils
{
	class vmthook
	{
	public:
		vmthook();

		vmthook(PDWORD* ppdwClassBase);

		~vmthook();

		bool initialize(PDWORD* ppdwClassBase);
		bool initialize(PDWORD** pppdwClassBase);

		void clear_class_base();

		void unhook();

		void rehook();

		int get_func_count();

		template <typename Fn>
		Fn get_func_address(int Index)
		{
			if (Index >= 0 && Index <= (int)m_VTSize && m_OldVT != NULL)
				return reinterpret_cast<Fn>(m_OldVT[Index]);

			return NULL;
		}

		PDWORD get_old_vt();

		DWORD hook_function(DWORD dwNewFunc, unsigned int iIndex);

	private:
		DWORD get_vt_count(PDWORD pdwVMT);

		PDWORD* m_ClassBase;
		PDWORD	m_NewVT, m_OldVT;
		DWORD	m_VTSize;
	};

}

