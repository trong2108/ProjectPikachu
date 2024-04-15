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
    Cell** Board = new Cell* [ROW];
    for(int i = 0; i < ROW; i++)
        Board[i] = new Cell [COL];

    return Board;
}

void initBoard(Cell** Board, int pokemonFreq[26])
{
    srand(time(NULL));

    int pokemonAppear[26] = {};

    for(int i = 0; i < ROW; i++)
        for(int j = 0; j < COL; j++)
            if(Board[i][j].present)
                while(true)
                {
                    int temp = rand() % 26;
                    if(pokemonAppear[temp] == pokemonFreq[temp])
                        continue;

                    Board[i][j].pokemon = temp + 'A';
                    pokemonAppear[temp]++;
                    break;
                }
}

void deleteBoard(Cell** Board)
{
    for(int i = 0; i < COL; i++)
        delete[] Board[i];

    delete[] Board;
}







