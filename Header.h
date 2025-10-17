#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <tchar.h>
#include <vector>
#include <atomic>
#include <thread>
#include <chrono>
#include <mutex>
#include <string>
#include "Base.h"
#include "Memory.h"
#include "Offsets.h"
#include "Write.h"
#include "Global.h"
#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"
#include <d3d11.h>


#define GAMEWINDOW "AssaultCube"
#define offSetToBullets 0x00195404
#define offSetToBombs 0x0018AC00
#define BulletsDec 0x004C73EF
#define BombsDec 0x004C7E5D
#define NoRecoil 0x004C2EC3
#define GravityHack 0x4C2375
#define FastShoot 0x004C721C