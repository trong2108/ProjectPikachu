struct Cell_index
{
    int x;
    int y;
};

bool checkI(Cell_index cell_A, Cell_index cell_B, Cell Board[][COL])
{
    if(cell_A.x == cell_B.x && (cell_A.x == -1 || cell_B.x == ROW))
        return true;

    if(cell_A.y == cell_B.y && (cell_A.y == -1 || cell_A.y == COL))
        return true;

    if(cell_A.x == cell_B.x)
    {
        int shared_x = cell_A.x;
        int min_y = min(cell_A.y, cell_B.y);
        int max_y = max(cell_A.y, cell_B.y);
        for(int j = min_y + 1; j < max_y; j++)
            if(Board[shared_x][j].present == 1)
                return false;
        return true;
    }

    if(cell_A.y == cell_B.y)
    {
        int shared_y = cell_A.y;
        int min_x = min(cell_A.x, cell_B.x);
        int max_x = max(cell_A.x, cell_B.x);
        for(int i = min_x + 1; i < max_x; i++)
            if(Board[i][shared_y].present == 1)
                return false;
        return true;
    }

    return false;
}

bool checkL(Cell_index cell_A, Cell_index cell_B, Cell Board[][COL])
{
    if(checkI(cell_A, {cell_A.x, cell_B.y}, Board) && checkI(cell_B, {cell_A.x, cell_B.y}, Board))
        return true;

    if(checkI(cell_A, {cell_B.x, cell_A.y}, Board) && checkI(cell_B, {cell_B.x, cell_A.y}, Board))
        return true;

    return false;
}

bool checkUZ(Cell_index cell_A, Cell_index cell_B, Cell Board[][COL])
{
    for(int row = -1; row <= ROW; row++)
        if(checkI(cell_A, {row, cell_A.y}, Board) && checkI({row, cell_A.y}, {row, cell_B.y}, Board) && checkI({row, cell_B.y}, cell_B, Board))
                return true;

    for(int col = -1; col <= COL; col++)
        if(checkI(cell_A, {cell_A.x, col}, Board) && checkI({cell_A.x, col}, {cell_B.x, col}, Board) && checkI({cell_B.x, col}, cell_B, Board))
                return true;

     return false;
}

bool checkMatch(Cell_index cell_A, Cell_index cell_B, Cell Board[][COL])
{
    return checkI(cell_A, cell_B, Board) || checkL(cell_A, cell_B, Board) || checkUZ(cell_A, cell_B, Board);
}
































































