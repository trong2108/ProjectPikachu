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

void initBoard(Cell Board[][COL], int pokemonFreq[26])
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

void printBoard(Cell Board[][COL])
{
    cout << " \t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t0\t1\t2\n\n";
    for(int i = 0; i < ROW; i++)
    {
        cout << i % 10 << "\t";
        for(int j = 0; j < COL; j++)
            if(Board[i][j].present)
                cout << Board[i][j].pokemon << "\t";
            else
                cout << " \t";

        cout << "\n\n";
    }
}

void deleteBoard(Cell** Board)
{
    for(int i = 0; i < COL; i++)
        delete[] Board[i];

    delete[] Board;
}

bool stillHaveLegitMove(Cell** Board);








