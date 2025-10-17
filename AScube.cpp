#include "Header.h"
#include "menu.h"
#include "Base.h"
#include "Offsets.h"
#include "Memory.h"
#include "Write.h"
#include "Global.h"

int main()
{
	if (!AttachToGame())
	{
		std::cout << "Start the Game!";
	}
	Menu();
}