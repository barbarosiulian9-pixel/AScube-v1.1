#pragma once
#include "Header.h"
#include "Base.h"
#include "Memory.h"
#include "Global.h"

DWORD GetModuleBaseAddress(TCHAR* lpszModuleName, DWORD pID);
bool AttachToGame();