void setCursorPosition(short int x, short int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//void printBoard(Cell Board[][COL])
//{
//    cout << " \t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t0\t1\t2\n\n";
//    for(int i = 0; i < ROW; i++)
//    {
//        cout << i % 10 << "\t";
//        for(int j = 0; j < COL; j++)
//            if(Board[i][j].present)
//                cout << Board[i][j].pokemon << "\t";
//            else
//                cout << " \t";
//
//        cout << "\n\n";
//    }
//}

void clearConsole() {
    COORD topLeft = {0, 0};
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(consoleHandle, &screen);
    FillConsoleOutputCharacterA(consoleHandle, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(consoleHandle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(consoleHandle, topLeft);
}
