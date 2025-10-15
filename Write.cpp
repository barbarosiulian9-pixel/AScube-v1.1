#include "Write.h"
#include "Header.h"
#include "Memory.h"
#include "Base.h"
#include "Offsets.h"
#include "Global.h"

void BulletsWriteMem()
{
	int Bullets = 9999;
	WriteProcessMemory(pHandle, (LPVOID)bulletsAddress, &Bullets, sizeof(Bullets), NULL);
}

void BombsWriteMem()
{
	int Bombs = 9999;
	WriteProcessMemory(pHandle, (LPVOID)bombAddress, &Bombs, sizeof(Bombs), NULL);
}

void BulletsOff()
{
	int Bullets2 = 20;
	WriteProcessMemory(pHandle, (LPVOID)bulletsAddress, &Bullets2, sizeof(Bullets2), NULL);
}

void BombsOff()
{
	int Bombs2 = 0;
	WriteProcessMemory(pHandle, (LPVOID)bombAddress, &Bombs2, sizeof(Bombs2), NULL);
}