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
        else if (input == 13 || input == 32) // enter key and space key is to define the board player chooses
            return 5;
    }
}

void Cell_index::moveLeft()
{
    if(y == 0)
        y = COL - 1;
    else
        y--;
}

void Cell_index::moveRight()
{
    if(y == COL - 1)
        y = 0;
    else
        y++;
}

void Cell_index::moveUp()
{
    if(x == 0)
        x = ROW - 1;
    else
        x--;
}

void Cell_index::moveDown()
{
    if(x == ROW - 1)
        x = 0;
    else
        x++;
}

