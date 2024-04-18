//Get a single key from the key board (w, a, s, d, space, enter, arrow, h, r, b)
int getKeyboard()
{
    while(true)
    {
        int input = _getch();
        if(input == 27) // ESC
            return 0;
        else if(input == 224)
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
        else if(input == 'h' || input == 'H') // help
            return 5;
        else if(input == 'r' || input == 'R') // reshuffle
            return 6;
        else if(input == 'b' || input == 'B') // buy
            return 7;
        else if (input == 13 || input == 32) // enter key and space key is to define the board player chooses
            return 8;
    }
}

//Move a cell to the left until it meet another cell
void Cell_index::moveLeft(Cell** Board)
{
    int org_y = y;
    do
        y--;
    while(y != -1 && !Board[x][y].present);

    if(y != -1)
        return;

    y = org_y - 1;
    while(y != -1)
    {
        for(int i = 1; x + i < ROW || x - i >= 0; i++)
        {
            if(x - i >= 0 && Board[x - i][y].present)
            {
                x = x - i;
                return;
            }
            if(x + i < ROW && Board[x + i][y].present)
            {
                x = x + i;
                return;
            }
        }
        y--;
    }

    y = org_y;
}

//Move a cell to the right until it meet another cell
void Cell_index::moveRight(Cell** Board)
{
    int org_y = y;
    do
        y++;
    while(y != COL && !Board[x][y].present);

    if(y != COL)
        return;

    y = org_y + 1;
    while(y != COL)
    {
        for(int i = 1; x + i < ROW || x - i >= 0; i++)
        {
            if(x + i < ROW && Board[x + i][y].present)
            {
                x = x + i;
                return;
            }
            if(x - i >= 0 && Board[x - i][y].present)
            {
                x = x - i;
                return;
            }
        }
        y++;
    }

    y = org_y;
}

//Move a cell up until it meet another cell
void Cell_index::moveUp(Cell** Board)
{
    int org_x = x;
    do
        x--;
    while(x != -1 && !Board[x][y].present);

    if(x != -1)
        return;

    x = org_x - 1;
    while(x != -1)
    {
        for(int i = 1; y + i < COL || y - i >= 0; i++)
        {
            if(y - i >= 0 && Board[x][y - i].present)
            {
                y = y - i;
                return;
            }
            if(y + i < COL && Board[x][y + i].present)
            {
                y = y + i;
                return;
            }
        }
        x--;
    }

    x = org_x;
}

//Move a cell down until it meet another cell
void Cell_index::moveDown(Cell** Board)
{
    int org_x = x;
    do
        x++;
    while(x != ROW && !Board[x][y].present);

    if(x != ROW)
        return;

    x = org_x + 1;
    while(x != ROW)
    {
        for(int i = 1; y + i < COL || y - i >= 0; i++)
        {
            if(y + i < COL && Board[x][y + i].present)
            {
                y = y + i;
                return;
            }
            if(y - i >= 0 && Board[x][y - i].present)
            {
                y = y - i;
                return;
            }
        }
        x++;
    }

    x = org_x;
}

