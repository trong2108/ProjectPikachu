#include "lib.h"
#include "Board.h"

printBoard()
--keyboard

//"Board.h"

#define ROW 10;
#define COL 13;

struct Cell
{
    char pokemon;
    bool isPresent;

    Cell()
    {
        isPresent = 1;
    }
};

Cell Board[ROW][COL];

0 - 'A'
1 - 'B'
...
25 - 'Z'

int charFreq[26] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

srand(time(NULL));
for(int i = 0; i < ROW; i++)
    for(int j = 0; j < COL; j++)
        while(true)
        {
            int temp = rand() % 26;
            if(charFreq[temp] == 0)
                continue;

            charFreq[temp]--;
            Board[i][j].pokemon = temp + 'A';
            break;
        }



int main()
{
    return 0;
}
