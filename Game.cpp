#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <conio.h>
#include <unistd.h>
#include <cmath>

using namespace std;

#include "Board.h"
#include "MatchingLogic.h"
#include "PrintingConsole.h"
#include "User.h"
#include "KeyboardMove.h"
#include "Gameplay.h"

int main()
{
//    printGameTitle();
//
//    cout << "\n\n                                   Enter your username: ";
//    string username;
//    getline(cin, username);
//    clearConsole();
//    if(findAccount(username))
//        rewriteOldAccount(username, 500);
//    else
//        writeNewAccount(username, 500);

    gameLoop("PhanPhuTrong", 5000);

    return 0;
}
