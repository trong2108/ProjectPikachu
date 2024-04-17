#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <conio.h>
#include <unistd.h>
#include <cmath>

#pragma comment(lib, "Winmm.lib")

using namespace std;

#include "Board.h"
#include "MatchingLogic.h"
#include "PrintingConsole.h"
#include "User.h"
#include "KeyboardMove.h"
#include "Gameplay.h"
#include "Menu.h"

int main()
{
    hideCursor();
    printGameTitle();
    printMenu();
    chooseButton("PLAY");
    string currentButton = "PLAY";

    while(true)
    {
        int key = getMenuKeyboard();
        if(key == 0)
        {
            clearConsole();
            return 0;
        }

        if(key == 1)
        {
            playSound("move.wav");
            unchooseButton(currentButton);
            if(currentButton == "PLAY")
                currentButton = "EXIT";
            else if(currentButton == "LEADER BOARD")
                currentButton = "PLAY";
            else if(currentButton == "EXIT")
                currentButton = "LEADER BOARD";
            chooseButton(currentButton);
            continue;
        }

        if(key == 2)
        {
            playSound("move.wav");
            unchooseButton(currentButton);
            if(currentButton == "PLAY")
                currentButton = "LEADER BOARD";
            else if(currentButton == "LEADER BOARD")
                currentButton = "EXIT";
            else if(currentButton == "EXIT")
                currentButton = "PLAY";
            chooseButton(currentButton);
            continue;
        }

        ///KEY = 3

        playSound("place.wav");

        if(currentButton == "PLAY")
        {
            clearConsole();
            printGameTitle();
            cout << "\n\n                                    Please Enter Your Username : ";
            string username;
            int hightestPoint;

            getline(cin, username);
            findAccount(username, hightestPoint);

            clearConsole();
            int newPoint = gameLoop(username, hightestPoint);

            if(findAccount(username, hightestPoint))
                rewriteOldAccount(username, newPoint);
            else
                writeNewAccount(username, newPoint);

            int key = _getch();
            if(key == 27)
            {
                clearConsole();
                return 0;
            }
            else
            {
                clearConsole();
                printGameTitle();
                printMenu();
                chooseButton("PLAY");
                currentButton = "PLAY";
            }
        }

        if(currentButton == "LEADER BOARD")
        {
            clearConsole();
            printLeaderBoard();
            cout << "\nPress Any Key to Go Back...";
            int key = _getch();
            if(key == 27)
            {
                clearConsole();
                return 0;
            }
            else
            {
                clearConsole();
                printGameTitle();
                printMenu();
                chooseButton("PLAY");
                currentButton = "PLAY";
            }
        }

        if(currentButton == "EXIT")
        {
            clearConsole();
            return 0;
        }
    }

    return 0;
}
