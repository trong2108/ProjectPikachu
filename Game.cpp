#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

#include "Board.h"
#include "Matching.h"
#include "ConsoleView.h"

#include "test.h"

int main()
{
    Cell Board[ROW][COL];
    int pokemonFreq[26] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    int totalPokemon = ROW * COL;
    initBoard(Board, pokemonFreq);

    setWindowSize(119,40);
    SetScreenBufferSize(118,20);
    DisableResizeWindow();
    DisableCtrButton(1,1,1);
    ShowScrollbar(0);
//    SetConsoleTitle(L"Pikachu Games");

    printBoard(Board);
    return 0;

//    printBoard(Board);

//    int life = 3;
//    cout << "Life left: " << life << endl;
//
//    while(life != 0)
//    {
//        int x1, x2, y1, y2;
//        cout << "First Cell: ";
//        cin >> x1 >> y1;
//        cout << "Second Cell: ";
//        cin >> x2 >> y2;
//        if(Board[x1][y1].present && Board[x2][y2].present && Board[x1][y1].pokemon == Board[x2][y2].pokemon && checkMatch({x1, y1}, {x2, y2}, Board))
//        {
//            clearConsole();
//
//            Board[x1][y1].present = 0;
//            Board[x2][y2].present = 0;
//            pokemonFreq[Board[x1][y1].pokemon - 'A'] -= 2;
//            totalPokemon -= 2;
//
//            printBoard(Board);
//
//            if(totalPokemon == 0)
//            {
//                cout << "YOU WIN!!!" << endl;
//                return 1;
//            }
//
//            if(!stillHaveLegitMove(Board))
//                initBoard(Board, pokemonFreq);
//
//            cout << "Life left: " << life << endl;
//        }
//        else
//        {
//            clearConsole();
//            life--;
//            printBoard(Board);
//            cout << "Life left: " << life << endl;
//        }
//    }
//
//    cout << "YOU LOSE!!!" << endl;

    return 0;
}
