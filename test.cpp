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

int main() {
    printAsciiArt();
    return 0;
}

































