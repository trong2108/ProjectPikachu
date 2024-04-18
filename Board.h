struct Cell
{
    char pokemon; // The pokemon the cell hold
    bool present; // Whether or not the save is already cleared

    Cell()
    {
        present = 1; // At the start, every cell is not cleared
    }
};

#define ROW 8 // Size of the playing board
#define COL 8

//Create the board
Cell** genBoard()
{
    Cell** Board = new Cell* [ROW];
    for(int i = 0; i < ROW; i++)
        Board[i] = new Cell [COL];

    return Board;
}

//Give every cell a random pokemon based on a pokemonFreq array that contain the number of appearance of each pokemon.
//This code can also reshuffle a board based on the current state of the pokemonFreq array
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

//Deallocate the board
void deleteBoard(Cell** Board)
{
    for(int i = 0; i < COL; i++)
        delete[] Board[i];

    delete[] Board;
}







