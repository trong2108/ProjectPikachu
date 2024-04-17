#define COORD_X 3
#define COORD_Y 2

void clearConsole() {
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; // Hide the cursor
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

void appear(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}

void printBox(short x, short y)
{
    appear(x, y);
    putchar(218);
    for(int i = 0; i < 3; i++)
        putchar(196);
    putchar(191);
    for (int i = 0; i < 1; i ++)
    {
        appear(x, y + 1 +i);
        putchar(179);
        appear(x + 4, y + 1 + i);
        putchar(179);
    }
    appear(x, y + 2);
    putchar(192);
    for(int i = 0; i < 3; i++)
        putchar(196);
    putchar(217);
}

void printBG(Cell_index Cell_A, short x = COORD_X, short y = COORD_Y)
{
    const string BackGround[24] = {
    R"(xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx)",
    R"(x     _  _     ___   __  __   _   _    ___    x)",
    R"(x    | || |   / __| |  \/  | | | | |  / __|   x)",
    R"(x    | __ |  | (__  | |\/| | | |_| |  \__ \   x)",
    R"(x    |_||_|   \___| |_|__|_|  \___/   |___/   x)",
    R"(x   _|"""""|_|"""""|_|"""""|_|"""""|_|"""""|  x)",
    R"(x   "`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'  x)",
    R"(x    _(  )_( )_                     \_/       x)",
    R"(x   (_   _    _)          T~      --(_)--     x)",
    R"(x     (_) (__)            |         /"\       x)",
    R"(x                T~~     |'| T~~              x)",
    R"(x            T~~ |    T~ WWWW|                x)",
    R"(x            |  /"\   |  |  |/\T~~            x)",
    R"(x           /"\ WWW  /"\ |' |WW|              x)",
    R"(x          WWWWW/\| /   \|'/\|/"\             x)",
    R"(x          |   /__\/]WWW[\/__\WWWW            x)",
    R"(x          |"  WWWW'|I_I|'WWWW'  |            x)",
    R"(x          |   |' |/  -  \|' |'  |            x)",
    R"(x          |'  |  |LI=H=LI|' |   |            x)",
    R"(x          |   |' | |[_]| |  |'  |            x)",
    R"(x          |   |  |_|###|_|  |   |            x)",
    R"(x          '---'--'-/___\-'--'---'            x)",
    R"(x                  /     \                    x)",
    R"(xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx)"
};

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 6; j++)
        {
            appear(6 * Cell_A.y + x + j, 3 * Cell_A.x + y + i);
            cout << BackGround[ 3 * Cell_A.x + i][6 * Cell_A.y + j];
        }

}
void printBoard(Cell** Board, short x = COORD_X, short y = COORD_Y)
{
    int temp = x;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (Board[i][j].present == 1)
            {
                printBox(x, y);
                appear(x + 2, y + 1);
                putchar(Board[i][j].pokemon);
            }
            else
            {
                printBG({i,j});
            }
            x += 6;
        }
        x = temp;
        y += 3;

    }
    cout << endl;
}

void deleteCell(Cell_index Cell_A, short x = COORD_X, short y = COORD_Y)
{
    short posY = y + Cell_A.x * 3;
    short posX = x + Cell_A.y * 6;
    for(int i = 0; i < 3; i++)
    {
        appear(posX, posY + i);
        cout << "     ";
    }

    SetColor(0,15);
}

void printColor(short x, short y, short background_color, short text_color)
{
    appear(x, y);
    SetColor(background_color, text_color);
    putchar(218);
    for(int i = 0; i < 3; i++)
        putchar(196);
    putchar(191);
    for (int i = 1; i < 2; i ++)
    {
        appear(x, y + i);
        putchar(179);
        appear(x + 4, y + i);
        putchar(179);
    }
    appear(x, y + 2);
    putchar(192);
    for(int i = 0; i < 3; i++)
        putchar(196);
    putchar(217);
    SetColor(0,15);
}

void printPurple(Cell_index Cell_A, short x = COORD_X, short y = COORD_Y)
{
    printColor(x + Cell_A.y * 6, y + Cell_A.x * 3, 5, 15);
}

void printBlack(Cell_index Cell_A, short x = COORD_X, short y = COORD_Y)
{
    printColor(x + Cell_A.y * 6, y + Cell_A.x * 3, 0, 15);
}

void printYellow(Cell_index Cell_A, short x = COORD_X, short y = COORD_Y)
{
    printColor(x + Cell_A.y * 6, y + Cell_A.x * 3, 6, 15);
}

void printRed(Cell_index Cell_A, short x = COORD_X, short y = COORD_Y)
{
    printColor(x + Cell_A.y * 6, y + Cell_A.x * 3, 4, 15);
}

void printBlue(Cell_index Cell_A, short x = COORD_X, short y = COORD_Y)
{
    printColor(x + Cell_A.y * 6, y + Cell_A.x * 3, 9, 15);
}

void printGreen(Cell_index Cell_A, short x = COORD_X, short y = COORD_Y)
{
    printColor(x + Cell_A.y * 6, y + Cell_A.x * 3, 2, 15);
}

void printPlayerInfo(string name, int life, int point, int hightestPoint)
{
    int length = 55;
    short x = 4;
    short y = 3;
    short width = 7;
    short coordinateX = x + 8*6 + 5;
    short coordinateY = y;
    appear(coordinateX, coordinateY);
    SetColor(0, 3);
    putchar(218);
    for(int i = 0; i < length; i++)
        putchar(196);
    putchar(191);
    for (int i = 1; i < width; i ++)
    {
        appear(coordinateX, coordinateY + i);
        putchar(179);
        appear(coordinateX + length + 1, coordinateY + i);
        putchar(179);
    }
    appear(coordinateX, coordinateY + width);
    putchar(192);
    for(int i = 0; i < length; i++)
        putchar(196);
    putchar(217);
    int line = 1;
    appear(coordinateX + 5 + 15, coordinateY + line++);
    SetColor(0, 15);
    cout << "PLAYER INFORMATION:";
    appear(coordinateX + 1, coordinateY + line++);
    SetColor(15, 4);
    for (int i = 0; i <length; i ++)
        cout <<"-";
    SetColor(0, 6);
    appear(coordinateX + 3, coordinateY + line++);
    cout << "Player : ";
    SetColor(0, 13); cout << name;

    SetColor(0, 6);
    appear(coordinateX + 3, coordinateY + line++);
    cout << "Life left : ";
    SetColor(0,3); cout << life;

    SetColor(0, 6);
    appear(coordinateX + 3, coordinateY + line++);
    cout << "Point : ";
    SetColor(0, 2); cout << point;

    SetColor(0, 6);
    appear(coordinateX + 3, coordinateY + line++);
    cout << "Highest point : ";
    SetColor(0, 4); cout << hightestPoint;

    SetColor(0,15);
}

void updateLife(int life)
{
    short x = 4;
    short y = 3;
    short coordinateX = x + 8 * 6 + 5;
    short coordinateY = y;
    appear(coordinateX + 3 + 12, coordinateY + 4);
    SetColor(0, 3);
    if(life == 1)
        SetColor(0, 4);
    cout << life << "     ";
}

void updatePoint(int point)
{
    short x = 4;
    short y = 3;
    short coordinateX = x + 8*6 + 5;
    short coordinateY = y;
    appear(coordinateX + 3 + 8, coordinateY + 5);
    SetColor(0, 2);
    cout << point << "     ";
}

void printTutorial()
{
    int length = 55;
    short x = 4;
    short y = 4;
    short coordinateX = x + 8*6 + 5;
    short coordinateY = y + 10;
    short width = 10;
    appear(coordinateX, coordinateY);
    SetColor(0, 3);
    putchar(218);
    for(int i = 0; i < length; i++)
        putchar(196);
    putchar(191);
    for (int i = 1; i < width; i ++)
    {
        appear(coordinateX, coordinateY + i);
        putchar(179);
        appear(coordinateX + length + 1, coordinateY + i);
        putchar(179);
    }
    appear(coordinateX, coordinateY + width);
    putchar(192);
    for(int i = 0; i < length; i++)
        putchar(196);
    putchar(217);

    int line = 1;
    appear(coordinateX + 27, coordinateY + line++);
    SetColor(15,2);
    cout << "GG!";
    appear(coordinateX + 1, coordinateY + line++);
    SetColor(15,4);
    for (int i = 0; i <length; i ++)
        cout <<"-";
    SetColor(0, 6);

    appear(coordinateX + 20, coordinateY + line++);
    cout << "PIKACHU TUTORIAL:";
    SetColor(0, 15);
    appear(coordinateX + 3, coordinateY + line++);
    cout << "Use WASD/Arrow Key to Move";
    appear(coordinateX + 3, coordinateY + line++);
    cout << "Press Enter/Space to Choose or Unchoose";
    appear(coordinateX + 3, coordinateY + line++);
    cout << "Press 'H' Key for Move Suggestion (-20 Points)";
    appear(coordinateX + 3, coordinateY + line++);
    cout << "Press 'R' Key to Reshuffle Game Board (-50 Points)";
    appear(coordinateX + 3, coordinateY + line++);
    cout << "Press 'B' to Buy Life (-30 Points)";
    appear(coordinateX + 3, coordinateY + line++);
    cout << "Press ESC to Exit ";

    SetColor(0,15);
}






