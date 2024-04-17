int getKeyboard()
{
    while(true)
    {
        int input = _getch();
        if(input == 224)
        {
            input = _getch();
            if(input == 75) // left arrow = 1
                return 1;
            else if(input == 72) // up arrow = 2
                return 2;
            else if(input == 77) //right arrow = 3
                return 3;
            else if(input == 80) // down arrow = 4
                return 4;
        }
        else if(input == 'a' || input == 'A') // left arrow = 1
                return 1;
        else if(input == 'w' || input == 'W') // up arrow = 2
                return 2;
        else if(input == 'd' || input == 'D') //right arrow = 3
                return 3;
        else if(input == 's' || input == 'S') // down arrow = 4
            return 4;
        else if(input == 'h' || input == 'H')
            return 5;
        else if(input == 'r' || input == 'R')
            return 6;
        else if(input == 'b' || input == 'B')
            return 7;
        else if (input == 13 || input == 32) // enter key and space key is to define the board player chooses
            return 0;
    }
}

void Cell_index::moveLeft(Cell** Board)
{
    while(true)
    {
        int org_y = y;
        do
            y = (y == 0) ? COL - 1 : y - 1;
        while(!Board[x][y].present && y != org_y);

        if(Board[x][y].present && y != org_y)
            return;
        else
            x = (x == 0) ? ROW - 1 : x - 1;
    }
}

void Cell_index::moveRight(Cell** Board)
{
    while(true)
    {
        int org_y = y;
        do
            y = (y == COL - 1) ? 0 : y + 1;
        while(!Board[x][y].present && y != org_y);

        if(Board[x][y].present && y != org_y)
            return;
        else
            x = (x == ROW - 1) ? 0 : x + 1;

    }
}

void Cell_index::moveUp(Cell** Board)
{
    while(true)
    {
        int org_x = x;
        do
            x = (x == 0) ? ROW - 1 : x - 1;
        while(!Board[x][y].present && x != org_x);

        if(Board[x][y].present && x != org_x)
            return;
        else
            y = (y == 0) ? COL - 1 : y - 1;

    }
}

void Cell_index::moveDown(Cell** Board)
{
    while(true)
    {
        int org_x = x;
        do
            x = (x == ROW - 1) ? 0 : x + 1;
        while(!Board[x][y].present && x != org_x);

        if(Board[x][y].present && x != org_x)
            return;
        else
            y = (y == COL - 1) ? 0 : y + 1;

    }
}

