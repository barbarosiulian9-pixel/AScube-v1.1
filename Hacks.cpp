#include "Header.h"
#include "Hacks.h"
#include "Global.h"
#include "config.h"


//Infinite Bullets atach
void Bullets()
{
	if (config.Bullets)
	{
		WriteByteBulletsON();

	}
	else
	{
		WriteByteBulletsOFF();
	}
}

//Inifnite Bombs atach
void Bombs()
{
	if (config.Bombs)
	{
		WriteByteBombsON();

	}
	else
	{
		WriteByteBombsOFF();
	}
}

//Norec atach
void Norec()
{
	if (config.Norec)
	{
		WriteByteNoRecON();
	}
	else
	{
		WriteByteNoRecOFF();
	}
}

//Gravity Hack
void Gravity()
{
	if (config.Gravity)
	{
		WriteByteGravityJumpON();
	}
	else
	{
		WriteByteGravityJumpOFF();
	}
}

//Fast Shoot
void FastShootHack()
{
	if (config.fastshoot)
	{
		WriteByteFastShootON();
	}
	else
	{
		WriteByteFastShootOFF();
	}
}

void ReloadOFF()
{
	if (config.ReloadAnimation)
	{
		ReloadAnimationON();
	}
	else
	{
		ReloadAnimationOFF();
	}
}

void AutoGun()
{
	if (config.Autogun)
	{
		AutoGunON();
	}
	else
	{
		AutoGunOFF();
	}
}