#include <iostream>

// Define the size of the ASCII art
const int ROWS = 24;
const int COLS = 48;

// Define the ASCII art as a constant array of strings
const std::string asciiArt[ROWS] = {
    R"(xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx)",
    R"(x      _  _     ___   __  __   _   _    ___      x)",
    R"(x     | || |   / __| |  \/  | | | | |  / __|     x)",
    R"(x     | __ |  | (__  | |\/| | | |_| |  \__ \     x)",
    R"(x     |_||_|   \___| |_|__|_|  \___/   |___/     x)",
    R"(x    _|"""""|_|"""""|_|"""""|_|"""""|_|"""""|    x)",
    R"(x    "`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'    x)",
    R"(x     _(  )_( )_                     \_/         x)",
    R"(x    (_   _    _)          T~      --(_)--       x)",
    R"(x      (_) (__)            |         /"\         x)",
    R"(x                 T~~     |'| T~~                x)",
    R"(x             T~~ |    T~ WWWW|                  x)",
    R"(x             |  /"\   |  |  |/\T~~              x)",
    R"(x            /"\ WWW  /"\ |' |WW|                x)",
    R"(x           WWWWW/\| /   \|'/\|/"\               x)",
    R"(x           |   /__\/]WWW[\/__\WWWW              x)",
    R"(x           |"  WWWW'|I_I|'WWWW'  |              x)",
    R"(x           |   |' |/  -  \|' |'  |              x)",
    R"(x           |'  |  |LI=H=LI|' |   |              x)",
    R"(x           |   |' | |[_]| |  |'  |              x)",
    R"(x           |   |  |_|###|_|  |   |              x)",
    R"(x           '---'--'-/___\-'--'---'              x)",
    R"(x                   /     \                      x)",
    R"(xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx)"
};

// Function to print the ASCII art
void printAsciiArt() {
//    for (int i = 0; i < ROWS; ++i) {
//        std::cout << asciiArt[i] << "\n";
//    }
    std::cout << asciiArt[0][0];
}
void printBG(Cell_index Cell_A, short x = COORD_X, short y = COORD_Y)
{
const string asciiArt[24] = {
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
    R"(xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx)"
};

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 6; j++)
        {
            appear(6 * Cell_A.y + x + j, 3 * Cell_A.x + y + i);
            cout << asciiArt[ 3 * Cell_A.x + i][6 * Cell_A.y + j];
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
                printBG({i,j}, x, y);
            }
            x += 6;
        }
        x = temp;
        y += 3;

    }
    cout << endl;
}
int main() {
    printAsciiArt();
    return 0;
}

































