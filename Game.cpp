#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <conio.h>

using namespace std;

#include "Board.h"
#include "Matching.h"
#include "ConsoleView.h"
#include "openWindow.h"

int main()
{
    Cell Board[ROW][COL];
    int pokemonFreq[26] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    int totalPokemon = ROW * COL;
    initBoard(Board, pokemonFreq);

    printBoard(Board);

    int life = 3;
    cout << "\n\nLife left: " << life << endl;

    while(life != 0)
    {
        int x1, x2, y1, y2;
        cout << "First Cell: ";
        cin >> x1 >> y1;
        cout << "Second Cell: ";
        cin >> x2 >> y2;

        if(x1 == x2 && y1 == y2)
            continue;

        if(!Board[x1][y1].present || !Board[x2][y2].present)
            continue;

        if(Board[x1][y1].pokemon == Board[x2][y2].pokemon && checkMatch({x1, y1}, {x2, y2}, Board))
        {
            Board[x1][y1].present = 0;
            Board[x2][y2].present = 0;
            pokemonFreq[Board[x1][y1].pokemon - 'A'] -= 2;
            totalPokemon -= 2;

            printBoard(Board);

            if(totalPokemon == 0)
            {
                cout << "YOU WIN!!!" << endl;
                return 1;
            }

            while(!stillHaveLegitMove(Board))
                initBoard(Board, pokemonFreq);

            cout << "\n\nLife left: " << life << endl;
        }
        else
        {
            life--;
            printBoard(Board);
            cout << "\n\nLife left: " << life << endl;
        }
    }

    cout << "YOU LOSE!!!" << endl;

    return 0;
}
