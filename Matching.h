struct Point
{
    int x;
    int y;
};

bool checkI(Point A, Point B, Cell** Board)
{
    if(A.x == B.x && (A.x == -1 || A.x == ROW))
        return true;

    if(A.y == B.y && (A.y == -1 || A.y == COL))
        return true;

    if(A.x == B.x)
    {
        int shared_x = A.x;
        int min_y = min(A.y, B.y);
        int max_y = max(A.y, B.y);
        for(int j = min_y + 1; j < max_y; j++)
            if(Board[shareD_x][j].present == 1)
                return false;
        return true;
    }

    if(A.y == B.y)
    {
        int shared_y = A.y;
        int min_x = min(A.x, B.x);
        int max_x = max(A.x, B.x);
        for(int i = min_x + 1; i < max_x; i++)
            if(Board[i][shared_y].present == 1)
                return false;
        return true;
    }

    return false;
}

bool checkL(Point A, Point B, Cell** Board)
{
    if(checkI(A, {A.x, B.y}, Board) && checkI(B, {A.x, B.y}, Board))
        return true;

    if(checkI(A, {B.x, A.y}, Board) && checkI(B, {B.x, A.y}, Board))
        return true;

    return false;
}

bool checkUZ(Point A, Point B, Cell** Board)
{
    for(int row = -1; row <= ROW; row++)
        if(checkI(A, {row, A.y}, Board) && checkI({row, A.y}, {row, B.y}, Board) && checkI({row, B.y}, B, Board))
                return true;

    for(int col = -1; col <= COL; col++)
        if(checkI(A, {A.x, col}, Board) && checkI({A.x, col}, {B.x, col}, Board) && checkI({B.x, col}, B, Board))
                return true;

     return false;
}

//bool checkZ(Point A, Point B, Cell** Board)
//{
//    Point max_x, min_x;
//    max_x = max(A.x, B.x);
//    min_x = min(A.x, B.x);
//
//    for(int row = min_x + 1; row < max_x; row++)
//        if(checkI(A, {row, A.y}, Board) && checkI({row, A.y}, {row, B.y}, Board) && checkI({row, B.y}, B, Board))
//            return 0;
//
//    Point max_y, min_y;
//    max_y = max(A.y, B.y);
//    min_y = min(A.y, B.y);
//
//    for(int col = )
//
//
//}
































































