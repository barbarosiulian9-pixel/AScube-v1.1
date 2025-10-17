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

#define GAMEWINDOW "AssaultCube"
#define offSetToBullets 0x00195404
#define offSetToBombs 0x0018AC00
#define BulletsDec 0x004C73EF
#define BombsDec 0x004C7E5D