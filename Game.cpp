#pragma comment(lib, "winmm.lib")
#define WINVER 0x0500

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

using namespace std;

#include "Board.h"
#include "Matching.h"
#include "OpenWindow.h"
#include "User.h"
#include "KeyboardMove.h"
#include "Gameplay.h"

int main()
{
    gameLoop_new();

    return 0;
}
