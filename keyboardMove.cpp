int getKeyboard()
{
    int input = _getch();
    while(input)
    {
        if(input == 224){
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
        else
            input = _getch();

    }
}
void moveLeft(short &x, short &y)
{
    if(x == 1)
        x += (COL - 1) * 6;
    else
        x -= 6;
    appear(x, y);
}
void moveUp(short &x, short &y)
{
    if(y == 0)
        y += (ROW - 1) * 3;
    else
        y -= 3;
    appear(x, y);
}
void moveRight(short &x, short &y)
{
    if(x == 1 + (COL - 1) * 6)
        x = 1;
    else
        x += 6;
    appear(x, y);

}
void moveDown(short &x, short &y)
{
    if(y == (ROW - 1) * 3)
        y = 0;
    else
        y += 3;
    appear(x, y);
}
void button(short x, short y)
{
    int select = 0;
    int input = getKeyboard();
    while(true)
    {
//        switch (input) // x + 6, y + 3
//        {// left, up, right, down
//            case 1: moveLeft(x, y);
//            case 2: moveUp(x, y);
//            case 3: moveRight(x, y);
//            case 4: moveDown(x, y);
//                input = getKeyboard();
//                break;
//            case 5: select++;
//        }
        if(input == 5)
        {
            select++;
            selectbox(x, y);
        }
        else if(input == 1)
        {
            moveLeft(x,y);
        }
        else if(input == 2)
        {
            moveUp(x,y);

        }
        else if(input == 3)
        {
            moveRight(x,y);

        }
        else if(input == 4)
        {
            moveDown(x,y);
        }
    }
}
void gamePlay()
{
    printBoard(Board, )
}
