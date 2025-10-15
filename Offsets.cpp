#include "Header.h"
#include "Base.h"
#include "Offsets.h"
#include "Memory.h"
#include "Global.h"

void BulletsOffsets()
{
    std::vector<DWORD> BulletsOffsets = { 0x140 };
    for (int i = 0; i < BulletsOffsets.size() - 1; i++)
    {
        ReadProcessMemory(pHandle, (LPVOID)(bulletsAddress + BulletsOffsets.at(i)), &bulletsAddress, sizeof(bulletsAddress), NULL);
    }
    bulletsAddress += BulletsOffsets.at(BulletsOffsets.size() - 1);
}
void BombsOffsets()
{
    std::vector<DWORD> BombOffsets = { 0x144 };
    for (int i = 0; i < BombOffsets.size() - 1; i++)
    {
        ReadProcessMemory(pHandle, (LPVOID)(bombAddress + BombOffsets.at(i)), &bombAddress, sizeof(bombAddress), NULL);
    }
    bombAddress += BombOffsets.at(BombOffsets.size() - 1);
}