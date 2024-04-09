#pragma once

using namespace std;

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
LONG SetWindowLong(
   HWND hWnd,
   int nIndex,
   LONG dwNewLong
);
void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
BOOL DeleteMenu(
  HMENU hMenu,
  UINT  uPosition,
  UINT  uFlags
);
void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}
BOOL ShowScrollBar(
  HWND hWnd,
  int  wBar,
  BOOL bShow
);
void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}
BOOL WINAPI SetConsoleTextAttribute(
  _In_ HANDLE hConsoleOutput,
  _In_ WORD   wAttributes
);
void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
BOOL WINAPI SetConsoleCursorPosition(
  _In_ HANDLE hConsoleOutput,
  _In_ COORD  dwCursorPosition
);
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
    for (int i = 1; i <= 3; i++)
    {
        putchar(196);
        appear(x + i, y + 4);
        putchar(196);
        appear(x + i, y);
    }
    putchar(191);
    for (int i = 1; i <= 3; i++)
    {
        appear(x, y + i);
        putchar(179);
        appear(x + 4, y + 1);
        putchar(179);
    }
    appear(x, y + 4);
    putchar(192);
    appear(x + 4, y +4);
    putchar(217);
}
void printBoard(Cell Board[][COL])
{
    int x = 1;
    int y = 1;
    for (int i = 0; i < ROW; i++)
        for (int j = 0; i < COL; j++)
        {
            printBox(x, y);
            appear(x + 2, y + 2);
            cout << Board[i][j].pokemon;
            x += 7;
            y += 5;
        }
}

