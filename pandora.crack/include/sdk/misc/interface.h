#pragma once

namespace sdk
{
	class InterfaceReg
	{
	private:
		using InstantiateInterfaceFn = void* (*)();
	public:
		InstantiateInterfaceFn m_CreateFn;
		const char* m_pName;
		InterfaceReg* m_pNext;
	};
}
