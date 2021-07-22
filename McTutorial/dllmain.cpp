#include <windows.h>
#include <iostream>

#include "main/main.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    FILE* pFile = nullptr;
    AllocConsole();
    freopen_s(&pFile, "CONOUT$", "w", stdout);
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        if (m.attach())
            m.run();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

