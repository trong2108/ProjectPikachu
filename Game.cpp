#pragma comment(lib, "winmm.lib")
#define WINVER 0x0500

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

using namespace std;

#include "Board.h"
#include "Matching.h"
#include "openWindow.h"
#include "User.h"
#include "KeyboardMove.h"
#include "Gameplay.h"

int main()
{


//    Cell** Board = genBoard();
//    int pokemonFreq[26] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
//    int totalPokemon = ROW * COL;
//    initBoard(Board, pokemonFreq);
//
//    printBoard(Board);
//
//    int life = 3;
//    cout << "\n\nLife left: " << life << endl;
//
//    while(life != 0)
//    {
//        int x1, x2, y1, y2;
//        cout << "First Cell: ";
//        cin >> x1 >> y1;
//        cout << "Second Cell: ";
//        cin >> x2 >> y2;
//
//        if(x1 == x2 && y1 == y2)
//            continue;
//
//        if(!Board[x1][y1].present || !Board[x2][y2].present)
//            continue;
//
//        if(Board[x1][y1].pokemon == Board[x2][y2].pokemon && checkMatch({x1, y1}, {x2, y2}, Board))
//        {
//            clearConsole();
//
//            Board[x1][y1].present = 0;
//            Board[x2][y2].present = 0;
//            pokemonFreq[Board[x1][y1].pokemon - 'A'] -= 2;
//            totalPokemon -= 2;
//
//            if(totalPokemon == 0)
//            {
//                printWinningMessage();
//                return 1;
//            }
//
//            if(!stillHaveLegitMove(Board))
//            {
//                cout << "No legit move. Shuffle board\n";
//                sleep(1);
//
//                initBoard(Board, pokemonFreq);
//                while(!stillHaveLegitMove(Board))
//                    initBoard(Board, pokemonFreq);
//
//                printBoard(Board);
//                cout << "\n\nLife left: " << life << endl;
//            }
//
//
//            printBoard(Board);
//            cout << "\n\nLife left: " << life << endl;
//        }
//        else
//        {
//            clearConsole();
//
//            life--;
//            printBoard(Board);
//            cout << "\n\nLife left: " << life << endl;
//
//            cout << "Sugguested move: ";
//
//            findLegitMove(Board, x1, y1, x2, y2);
//            cout << x1 << " " <<  y1 << " " << x2 << " " << y2 << endl;
//        }
//    }
//

//    clearConsole();
//    printLosingMessage();
//    deleteBoard(Board);





//    Cell** Board = genBoard();
//    int pokemonFreq[26] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
//    int totalPokemon = ROW * COL;
//    initBoard(Board, pokemonFreq);
//
//    Cell_index currentCell = {0, 0};
//    printBoard(Board, currentCell);
//    sleep(2);
//
//    currentCell.moveDown();
//    clearConsole();
//    printBoard(Board, currentCell);
//
//    delete[] Board;

    gameLoop();

    return 0;
}
