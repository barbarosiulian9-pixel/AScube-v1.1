#pragma once

class Config
{
public:
	bool Bullets = false;
	bool Bombs = false;
	bool Norec = false;
	bool Gravity = false;
	bool fastshoot = false;
	bool ReloadAnimation = false;
	bool Autogun = false;
private:

};

extern Config config;