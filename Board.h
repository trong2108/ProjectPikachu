struct Cell
{
    char pokemon;
    bool present;

    Cell()
    {
        present = 1;
    }
};

#define ROW 10
#define COL 13

Cell** genBoard()
{
    srand(time(NULL));
    int charFreq[26] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

    Cell** Board = new Cell* [ROW];
    for(int i = 0; i < ROW; i++)
    {
        Board[i] = new Cell [COL];
        for(int j = 0; j < COL; j++)
            while(true)
            {
                int temp = rand() % 26;
                if(charFreq[temp] == 0)
                    continue;

                Board[i][j].pokemon = temp + 'A';
                charFreq[temp]--;
                break;
            }
    }

    return Board;
}

void printBoard(Cell** Board)
{
    return;
}

void deleteBoard(Cell** Board)
{
    return;
}
