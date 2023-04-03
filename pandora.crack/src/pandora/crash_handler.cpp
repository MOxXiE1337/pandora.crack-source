#include <pandora/pandora.h>

namespace Pandora
{
	LONG NTAPI CrashHandler(struct _EXCEPTION_POINTERS* pExceptionInfo)
	{
		return 0;
	}
}