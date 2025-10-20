#include "Header.h"
#include "config.h"

bool isMenuClickable = true;

void HandleKeyboardInput(HWND window) {
	if (GetAsyncKeyState(VK_F2) & 1)
	{
		isMenuClickable = !isMenuClickable;
		if (isMenuClickable == false)
		{
			SetWindowLongPtr(window, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED);
		}
		else {
			SetWindowLongPtr(window, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_LAYERED);
		}
	}
}

void RenderMenu() {
	ImGui::Begin("External Forever");
	if (ImGui::BeginTabBar(""))
	{
		if(ImGui::BeginTabItem("Weapon"))
		{ 
			if (ImGui::Checkbox("Infinite Ammo", &config.Bullets))
			{
				Bullets();
			}
			if (ImGui::Checkbox("Infinite Bombs", &config.Bombs))
			{
				Bombs();
			}

			if (ImGui::Checkbox("No recoil", &config.Norec))
			{
				Norec();
			}

			if (ImGui::Checkbox("Gravity Hack", &config.Gravity))
			{
				Gravity();
			}

			if (ImGui::Checkbox("Fast Shoot", &config.fastshoot))
			{
				FastShootHack();
			}

			if(ImGui::Checkbox("Auto Gun", &config.Autogun))
			{
				AutoGun();
			}
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Visuals"))
		{
			if (ImGui::Checkbox("No Reload Animation", &config.ReloadAnimation))
			{
				ReloadOFF();
			}
			ImGui::EndTabItem();
		}
	}
	ImGui::EndTabBar();
	ImGui::End();
}