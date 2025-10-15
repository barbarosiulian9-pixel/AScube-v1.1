#include "Header.h"
#include "Memory.h"
#include "Offsets.h"
#include "Base.h"
#include "Global.h"

DWORD GetModuleBaseAddress(TCHAR* lpszModuleName, DWORD pID) {
    DWORD dwModuleBaseAddress = 0;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID);
    MODULEENTRY32 ModuleEntry32 = { 0 };
    ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

    if (Module32First(hSnapshot, &ModuleEntry32))
    {
        do {
            if (_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0)
            {
                dwModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
                break;
            }
        } while (Module32Next(hSnapshot, &ModuleEntry32));
    }
    CloseHandle(hSnapshot);
    return dwModuleBaseAddress;
}

bool AttachToGame()
{
    HWND hGameWindow = FindWindowA(NULL, GAMEWINDOW);
    if (hGameWindow == NULL)
    {
        std::cout << "Start the game first!" << std::endl;
        std::cin.get();
        return false;
    }

    DWORD pID = 0;
    GetWindowThreadProcessId(hGameWindow, &pID);

    pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
    if (pHandle == NULL)
    {
        std::cout << "Failed to open process!" << std::endl;
        return false;
    }

    TCHAR GameName[] = _T("ac_client.exe");

    gameAddress = GetModuleBaseAddress(GameName, pID);
    if (gameAddress == 0)
    {
        std::cout << "Failed to get base address!" << std::endl;
        return false;
    }

    std::cout << "Attached to game successfully!" << std::endl;
    std::cout << "PID: " << pID << std::endl;
    std::cout << "Base Address: 0x" << std::hex << gameAddress << std::endl;
    return true;
}