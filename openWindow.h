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

void setWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT gamePikachu;
    gamePikachu.Top = 0;
    gamePikachu.Left = 0;
    gamePikachu.Right = width;
    gamePikachu.Bottom = height;

    SetConsoleWindowInfo(hStdout, 1, &gamePikachu);
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD NewSize;
    NewSize.X = width;
    NewSize.Y = height;

    SetConsoleScreenBufferSize(hStdout, NewSize);
}

LONG SetWindowLong
(
   HWND hWnd,
   int nIndex,
   LONG dwNewLong
);

void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

BOOL DeleteMenu
(
  HMENU hMenu,
  UINT  uPosition,
  UINT  uFlags
);

void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (Close == 1)
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);

    if (Min == 1)
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);

    if (Max == 1)
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
}

BOOL ShowScrollBar
(
  HWND hWnd,
  int  wBar,
  BOOL bShow
);

void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
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
        appear(x + 4, y + 1 +i);
        putchar(179);
    }
    appear(x, y + 2);
    putchar(192);
    for(int i = 0; i < 3; i++)
        putchar(196);
    putchar(217);
}
void selectbox(short x, short y, short background_color, short text_color)
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
void printBoard(Cell** Board)
{
    short x = 0;
    short y = 0;
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
            x += 6;
        }
        x = temp;;
        y += 3;

    }
    cout << endl;
}
void printPurple(Cell_index Cell_A)
{
    short x = 0;
    short y = 0;
    selectbox(y + Cell_A.y * 6, x + Cell_A.x * 3, 5, 15);
}
void printBlack(Cell_index Cell_A)
{
    short x = 0;
    short y = 0;
    selectbox(y + Cell_A.y * 6, x + Cell_A.x * 3, 0, 15);
}
void printYellow(Cell_index Cell_B)
{
    short x = 0;
    short y = 0;
    selectbox(y + Cell_A.y * 6, x + Cell_A.x * 3, 6, 15);

}
void printRed(Cell_index Cell_B, Cell_index Cell_C)
{
    short x = 0;
    short y = 0;
    selectbox(y + Cell_C.y * 6, x + Cell_C.x * 3, 4, 15);
    selectbox(y + Cell_B.y * 6, x + Cell_B.x * 3, 4, 15);

}
void printGree(Cell_index Cell_B, Cell_index Cell_C)
{
    short x = 0;
    short y = 0;
    selectbox(y + Cell_C.y * 6, x + Cell_C.x * 3, 2, 15);
    selectbox(y + Cell_B.y * 6, x + Cell_B.x * 3, 2, 15);
}
