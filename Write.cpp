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

void WriteByteNoRecON()
{
	std::vector<BYTE> NorecSource = { 0x90,0x90,0x90,0x90,0x90 };
	WriteProcessMemory(pHandle, (LPVOID)NoRecoil, NorecSource.data(), NorecSource.size(), NULL);
}

void WriteByteNoRecOFF()
{
	std::vector<BYTE> NorecNOP = { 0xF3,0x0F,0x11,0x56,0x38 };
	WriteProcessMemory(pHandle, (LPVOID)NoRecoil, NorecNOP.data(), NorecNOP.size(), NULL);
}

void WriteByteGravityJumpON()
{
	std::vector<BYTE> GravityJumpNOP = { 0x90,0x90,0x90};
	WriteProcessMemory(pHandle, (LPVOID)GravityHack, GravityJumpNOP.data(), GravityJumpNOP.size(), NULL);
}

void WriteByteGravityJumpOFF()
{
	std::vector<BYTE> GravityJumpsource = { 0x89,0x4E,0x48};
	WriteProcessMemory(pHandle, (LPVOID)GravityHack, GravityJumpsource.data(), GravityJumpsource.size(), NULL);
}

void WriteByteFastShootON()
{
	std::vector<BYTE> FastShootNOP = { 0x90,0x90};

	WriteProcessMemory(pHandle, (LPVOID)FastShoot, FastShootNOP.data(), FastShootNOP.size(), NULL);
}

void WriteByteFastShootOFF()
{
	std::vector<BYTE> FastShootSource = { 0x2B,0x0A };
	WriteProcessMemory(pHandle, (LPVOID)FastShoot, FastShootSource.data(), FastShootSource.size(), NULL);
}

