struct Cell_index
{
    int x;
    int y;

    void moveLeft();
    void moveUp();
    void moveRight();
    void moveDown();
};

bool checkI(Cell_index cell_A, Cell_index cell_B, Cell** Board)
{
    if(cell_A.x == cell_B.x && (cell_A.x == -1 || cell_A.x == ROW))
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

bool checkL(Cell_index cell_A, Cell_index cell_B, Cell** Board)
{
    if(!Board[cell_A.x][cell_B.y].present && checkI(cell_A, {cell_A.x, cell_B.y}, Board) && checkI(cell_B, {cell_A.x, cell_B.y}, Board))
        return true;

    if(!Board[cell_B.x][cell_A.y].present && checkI(cell_A, {cell_B.x, cell_A.y}, Board) && checkI(cell_B, {cell_B.x, cell_A.y}, Board))
        return true;

    return false;
}

bool checkUZ(Cell_index cell_A, Cell_index cell_B, Cell** Board)
{
    if(checkI(cell_A, {-1, cell_A.y}, Board) && checkI(cell_B, {-1, cell_B.y}, Board))
        return true;
    if(checkI(cell_A, {ROW, cell_A.y}, Board) && checkI(cell_B, {ROW, cell_B.y}, Board))
        return true;
    if(checkI(cell_A, {cell_A.x, -1}, Board) && checkI(cell_B, {cell_B.x, -1}, Board))
        return true;
    if(checkI(cell_A, {cell_A.x, COL}, Board) && checkI(cell_B, {cell_B.x, COL}, Board))
        return true;

    for(int row = 0; row < ROW; row++)
        if(!Board[row][cell_A.y].present && !Board[row][cell_B.y].present && checkI(cell_A, {row, cell_A.y}, Board) && checkI({row, cell_A.y}, {row, cell_B.y}, Board) && checkI({row, cell_B.y}, cell_B, Board))
                return true;

    for(int col = 0; col < COL; col++)
        if(!Board[cell_A.x][col].present && !Board[cell_B.x][col].present && checkI(cell_A, {cell_A.x, col}, Board) && checkI({cell_A.x, col}, {cell_B.x, col}, Board) && checkI({cell_B.x, col}, cell_B, Board))
                return true;

     return false;
}

bool checkMatch(Cell_index cell_A, Cell_index cell_B, Cell** Board)
{
    return checkI(cell_A, cell_B, Board) || checkL(cell_A, cell_B, Board) || checkUZ(cell_A, cell_B, Board);
}

bool stillHaveLegitMove(Cell** Board)
{
    for(int i = 0; i < ROW; i++)
        for(int j = 0; j < COL; j++)
            for(int x = i; x < ROW; x++)
                for(int y = (x == i) ? j : 0; y < COL; y++)
                    if(checkMatch({i, j}, {x, y}, Board) && (x != i || y != j) && Board[i][j].pokemon == Board[x][y].pokemon && Board[i][j].present && Board[x][y].present)
                        return true;

    return false;
}

void findLegitMove(Cell** Board, int &x1, int &y1, int &x2, int &y2)
{
    for(int i = 0; i < ROW; i++)
        for(int j = 0; j < COL; j++)
            for(int x = i; x < ROW; x++)
                for(int y = (x == i) ? j : 0; y < COL; y++)
                    if(checkMatch({i, j}, {x, y}, Board) && (x != i || y != j) && Board[i][j].pokemon == Board[x][y].pokemon && Board[i][j].present && Board[x][y].present)
                    {
                        x1 = i;
                        y1 = j;
                        x2 = x;
                        y2 = y;
                        return;
                    }
}































































