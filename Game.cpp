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

    //Print the menu and game title
    printGameTitle();
    printMenu();
    //Set the default current button is PLAY
    chooseButton("PLAY");
    string currentButton = "PLAY";

    while(true)
    {
        int key = getMenuKeyboard();
        if(key == 0) // ESC key
        {
            clearConsole();
            return 0;
        }

        if(key == 1) // Move up key
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

        if(key == 2) // Move down Key
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

        ///Confirm Key

        playSound("place.wav");

        //PLAY
        if(currentButton == "PLAY")
        {
            clearConsole();
            //Ask foe the username
            printGameTitle();
            cout << "\n\n                                    Please Enter Your Username : ";
            string username;
            getline(cin, username);

            //Find the highest point of that username. If that username is not exist, then highest point is 0
            int hightestPoint;
            findAccount(username, hightestPoint);

            //Run the game
            clearConsole();
            int newPoint = gameLoop(username, hightestPoint);

            //Save the point and the account if it is brand new
            if(findAccount(username, hightestPoint))
                rewriteOldAccount(username, newPoint);
            else
                writeNewAccount(username, newPoint);

            //Asked if the player want to go back to the menu or exit
            int key = _getch();
            if(key == 27) // ESC key = exit
            {
                clearConsole();
                return 0;
            }
            else // Go back to the menu
            {
                clearConsole();
                printGameTitle();
                printMenu();
                chooseButton("PLAY");
                currentButton = "PLAY";
            }
        }

        //LEADER BOARD
        if(currentButton == "LEADER BOARD")
        {
            clearConsole();
            printLeaderBoard();
            cout << "\nPress Any Key to Go Back...";

            //Asked if the player want to go back to the menu or exit
            int key = _getch();
            if(key == 27) // ESC key = exit
            {
                clearConsole();
                return 0;
            }
            else // go back to menu
            {
                clearConsole();
                printGameTitle();
                printMenu();
                chooseButton("PLAY");
                currentButton = "PLAY";
            }
        }

        //EXIT
        if(currentButton == "EXIT")
        {
            clearConsole();
            return 0;
        }
    }

    return 0;
}
