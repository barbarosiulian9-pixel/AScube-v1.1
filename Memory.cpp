#include "Header.h"
#include "Memory.h"
#include "Base.h"
#include "Hacks.h"
#include "Global.h"

void BulletsReadMemory()
{
	DWORD BulletsAddress = NULL;
	ReadProcessMemory(pHandle, (LPVOID)(gameAddress + offSetToBullets), &BulletsAddress, sizeof(BulletsAddress), NULL);
	bulletsAddress = BulletsAddress;
}

void BombsReadMemory()
{
    DWORD BombsAddress = NULL;
    ReadProcessMemory(pHandle, (LPVOID)(gameAddress + offSetToBombs), &BombsAddress, sizeof(BombsAddress), NULL);
    bombAddress = BombsAddress;
}
