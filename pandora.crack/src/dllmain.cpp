#include <includes.h>

#include <pandora/pandora.h>

HMODULE g_loader_module = nullptr;

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  
    DWORD fdwReason,         
    LPVOID lpvReserved) 
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        AddVectoredExceptionHandler(0, pandora::crash_handler);
        g_loader_module = hinstDLL;
        DisableThreadLibraryCalls(hinstDLL);
        HANDLE thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)pandora::init, 0, 0, 0);
        if (thread)
            CloseHandle(thread);
        break;
    }
    return TRUE; }