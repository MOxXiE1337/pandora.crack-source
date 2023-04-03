#include <includes.h>

#include <pandora/pandora.h>

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  
    DWORD fdwReason,         
    LPVOID lpvReserved) 
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        AddVectoredExceptionHandler(0, Pandora::CrashHandler);
        Pandora::LoaderModule() = hinstDLL;
        DisableThreadLibraryCalls(hinstDLL);
        HANDLE hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Pandora::Init, 0, 0, 0);
        if (hThread)
            CloseHandle(hThread);
        break;
    }
    return TRUE; 
}