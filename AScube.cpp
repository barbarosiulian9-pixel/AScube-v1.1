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
		return 0;
	}
	Menu();
}