#include <hooks/hooks.h>

namespace hooks
{
	decltype(&GetCurrentProcessId) o_get_current_process_id;

	DWORD __stdcall get_current_process_id()
	{
		return 3936;
	}
}