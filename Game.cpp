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

int main()
{
//    COORD d = {0, 20};
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
//    cout << ".";
//
//    COORD c = {20, 0};
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
//    cout << ".";

    Cell Board[ROW][COL];
    int pokemonFreq[26] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    initBoard(Board, pokemonFreq);
    printBoard(Board);

    while(true)
    {
        int x1, x2, y1, y2;
        cout << "First Cell: ";
        cin >> x1 >> y1;
        cout << "Second Cell: ";
        cin >> x2 >> y2;
        if(Board[x1][y1].pokemon == Board[x2][y2].pokemon && checkMatch({x1, y1}, {x2, y2}, Board))
        {
            //system("clear");
            Board[x1][y1].present = 0;
            Board[x2][y2].present = 0;
            pokemonFreq[Board[x1][y1].pokemon - 'A'] -= 2;
            printBoard(Board);
        }
    }

    return 0;
}
