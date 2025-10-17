#include "Write.h"
#include "Header.h"
#include "Memory.h"
#include "Base.h"
#include "Offsets.h"
#include "Global.h"

void WriteByteBulletsON()
{
	std::vector<BYTE> BulletsNOPopcode = { 0x90,0x90};
	WriteProcessMemory(pHandle, (LPVOID)BulletsDec, BulletsNOPopcode.data(), BulletsNOPopcode.size(), NULL);
}

void WriteByteBulletsOFF()
{
	std::vector<BYTE> BulletsSourceopcode = { 0xFF,0x08 };
	WriteProcessMemory(pHandle, (LPVOID)BulletsDec, BulletsSourceopcode.data(), BulletsSourceopcode.size(), NULL);
}

void WriteByteBombsON()
{
	std::vector<BYTE> BombsNOPopcode = { 0x90,0x90 };
	WriteProcessMemory(pHandle, (LPVOID)BombsDec, BombsNOPopcode.data(), BombsNOPopcode.size(), NULL);
}

void WriteByteBombsOFF()
{
	std::vector<BYTE> BombsSourceopcode = { 0xFF,0x08};
	WriteProcessMemory(pHandle, (LPVOID)BombsDec, BombsSourceopcode.data(), BombsSourceopcode.size(), NULL);
}