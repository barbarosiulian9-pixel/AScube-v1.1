#include "Header.h"
#include <windows.h>
#include <iostream>

bool bulletsOn = false;
bool bombsOn = false;

void PrintMenu()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");

    std::cout << "<-----(Hack by External Forever)----->" << std::endl << std::endl;

    std::cout << "Infinite Bullets  [";
    SetConsoleTextAttribute(hConsole, bulletsOn ? FOREGROUND_GREEN | FOREGROUND_INTENSITY : FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << (bulletsOn ? "ON" : "OFF");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << "]     Page Up" << std::endl;

    std::cout << "Infinite Bombs    [";
    SetConsoleTextAttribute(hConsole, bombsOn ? FOREGROUND_GREEN | FOREGROUND_INTENSITY : FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << (bombsOn ? "ON" : "OFF");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << "]     Page Down" << std::endl;

    std::cout << std::endl << "<------------------------------------>" << std::endl;
}

void Menu()
{
    bool prevRControl = false;

    while (true)
    {
        Sleep(30);

        // ¬ыход клавишей END
        if (GetAsyncKeyState(VK_END) & 0x8000)
        {
            system("cls");
            break;
        }

        bool currRControl = (GetAsyncKeyState(VK_RCONTROL) & 0x8000) != 0;

        // открытие меню при фронте Right Ctrl
        if (currRControl && !prevRControl)
        {
            bool inMenu = true;
            bool prevPageUp = false;
            bool prevPageDown = false;
            bool prevRControlInner = false;

            PrintMenu();

            // ждЄм отпускани€ Right Ctrl перед тем, как реагировать на закрытие
            while ((GetAsyncKeyState(VK_RCONTROL) & 0x8000) != 0) { Sleep(10); }

            while (inMenu)
            {
                Sleep(30);

                // ѕроверка выхода из программы
                if (GetAsyncKeyState(VK_END) & 0x8000)
                {
                    system("cls");
                    return;
                }

                bool currPageUp = (GetAsyncKeyState(VK_PRIOR) & 0x8000) != 0;
                bool currPageDown = (GetAsyncKeyState(VK_NEXT) & 0x8000) != 0;
                bool currRControlInner = (GetAsyncKeyState(VK_RCONTROL) & 0x8000) != 0;

                // Page Up Ч переключаем bullets
                if (currPageUp && !prevPageUp)
                {
                    bulletsOn = !bulletsOn;
                    PrintMenu();

                    if (bulletsOn)
                    {
                        WriteByteBulletsON();
                    }
                    else
                    {
                        WriteByteBulletsOFF(); // <-- вызываем функцию отключени€
                    }

                    Sleep(150);
                }

                // Page Down Ч переключаем bombs
                if (currPageDown && !prevPageDown)
                {
                    bombsOn = !bombsOn;
                    PrintMenu();

                    if (bombsOn)
                    {
                        
                        WriteByteBombsON();
                    }
                    else
                    {
                        WriteByteBombsOFF(); // <-- вызываем функцию отключени€
                    }

                    Sleep(150);
                }

                // Right Ctrl Ч закрываем меню при фронте
                if (currRControlInner && !prevRControlInner)
                {
                    inMenu = false;
                    system("cls");
                    break;
                }

                prevPageUp = currPageUp;
                prevPageDown = currPageDown;
                prevRControlInner = currRControlInner;
            }
        }

        prevRControl = currRControl;
    }
}
