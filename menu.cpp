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

        // ����� �������� END
        if (GetAsyncKeyState(VK_END) & 0x8000)
        {
            system("cls");
            break;
        }

        bool currRControl = (GetAsyncKeyState(VK_RCONTROL) & 0x8000) != 0;

        // �������� ���� ��� ������ Right Ctrl
        if (currRControl && !prevRControl)
        {
            bool inMenu = true;
            bool prevPageUp = false;
            bool prevPageDown = false;
            bool prevRControlInner = false;

            PrintMenu();

            // ��� ���������� Right Ctrl ����� ���, ��� ����������� �� ��������
            while ((GetAsyncKeyState(VK_RCONTROL) & 0x8000) != 0) { Sleep(10); }

            while (inMenu)
            {
                Sleep(30);

                // �������� ������ �� ���������
                if (GetAsyncKeyState(VK_END) & 0x8000)
                {
                    system("cls");
                    return;
                }

                bool currPageUp = (GetAsyncKeyState(VK_PRIOR) & 0x8000) != 0;
                bool currPageDown = (GetAsyncKeyState(VK_NEXT) & 0x8000) != 0;
                bool currRControlInner = (GetAsyncKeyState(VK_RCONTROL) & 0x8000) != 0;

                // Page Up � ����������� bullets
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
                        WriteByteBulletsOFF(); // <-- �������� ������� ����������
                    }

                    Sleep(150);
                }

                // Page Down � ����������� bombs
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
                        WriteByteBombsOFF(); // <-- �������� ������� ����������
                    }

                    Sleep(150);
                }

                // Right Ctrl � ��������� ���� ��� ������
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
