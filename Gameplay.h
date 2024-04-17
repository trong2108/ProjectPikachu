void printGameTitle()
{
    unsigned char logo[] = R"(

                       ________  ___  ___  __    ________  ________  ___  ___  ___  ___
                      |\   __  \|\  \|\  \|\  \ |\   __  \|\   ____\|\  \|\  \|\  \|\  \
                      \ \  \|\  \ \  \ \  \/  /|\ \  \|\  \ \  \___|\ \  \\\  \ \  \\\  \
                       \ \   ____\ \  \ \   __\_ \ \   __  \ \  \    \ \   __  \ \  \\\  \
                        \ \  \___|\ \  \ \  \\ \  \ \  \ \  \ \  \____\ \  \ \  \ \  \\\  \
                         \ \__\    \ \__\ \__\\ \__\ \__\ \__\ \_______\ \__\ \__\ \_______\
                          \|__|     \|__|\|__| \|__|\|__|\|__|\|_______|\|__|\|__|\|_______|
	)";
	SetColor(0,6);
	cout << logo;
	SetColor(0,11);
	cout << R"(
            _____  _  _  ___   __  __    _  _____  ___  _  _  ___  _  _   ___    ___    _    __  __  ___
           |_   _|| || || __| |  \/  |  /_\|_   _|/ __|| || ||_ _|| \| | / __|  / __|  /_\  |  \/  || __|
             | |  | __ || _|  | |\/| | / _ \ | | | (__ | __ | | | | .` || (_ | | (_ | / _ \ | |\/| || _|
             |_|  |_||_||___| |_|  |_|/_/ \_\|_|  \___||_||_||___||_|\_| \___|  \___|/_/ \_\|_|  |_||___|
	)";
	SetColor(0,15);
}

void printLosingMessage()
{
    SetColor(0,12);
    cout << R"(
                                                                    ,--,
                                 ,----..                         ,---.'|       ,----..
                                /   /   \                        |   | :      /   /   \   .--.--.       ,---,.
                        ,---,  /   .     :          ,--,         :   : |     /   .     : /  /    '.   ,'  .' |
                       /_ ./| .   /   ;.  \       ,'_ /|         |   ' :    .   /   ;.  \  :  /`. / ,---.'   |
                 ,---, |  ' :.   ;   /  ` ;  .--. |  | :         ;   ; '   .   ;   /  ` ;  |  |--`  |   |   .'
                /___/ \.  : |;   |  ; \ ; |,'_ /| :  . |         '   | |__ ;   |  ; \ ; |  :  ;_    :   :  |-,
                 .  \  \ ,' '|   :  | ; | '|  ' | |  . .         |   | :.'||   :  | ; | '\  \    `. :   |  ;/|
                  \  ;  `  ,'.   |  ' ' ' :|  | ' |  | |         '   :    ;.   |  ' ' ' : `----.   \|   :   .'
                   \  \    ' '   ;  \; /  |:  | | :  ' ;         |   |  ./ '   ;  \; /  | __ \  \  ||   |  |-,
                    '  \   |  \   \  ',  / |  ; ' |  | '         ;   : ;    \   \  ',  / /  /`--'  /'   :  ;/|
                     \  ;  ;   ;   :    /  :  | : ;  ; |         |   ,/      ;   :    / '--'.     / |   |    \
                      :  \  \   \   \ .'   '  :  `--'   \        '---'        \   \ .'    `--'---'  |   :   .'
                       \  ' ;    `---`     :  ,      .-./                      `---`                |   | ,'
                        `--`                `--`----'                                               `----'

	)";
	SetColor(0,15);
}

void printWinningMessage()
{
    SetColor(0,10);
    cout << R"(

                                 ,----..                                                          ,--.
                                /   /   \                                   .---.   ,---,       ,--.'|
                        ,---,  /   .     :          ,--,                   /. ./|,`--.' |   ,--,:  : |
                       /_ ./| .   /   ;.  \       ,'_ /|               .--'.  ' ;|   :  :,`--.'`|  ' :
                 ,---, |  ' :.   ;   /  ` ;  .--. |  | :              /__./ \ : |:   |  '|   :  :  | |
                /___/ \.  : |;   |  ; \ ; |,'_ /| :  . |          .--'.  '   \' .|   :  |:   |   \ | :
                 .  \  \ ,' '|   :  | ; | '|  ' | |  . .         /___/ \ |    ' ''   '  ;|   : '  '; |
                  \  ;  `  ,'.   |  ' ' ' :|  | ' |  | |         ;   \  \;      :|   |  |'   ' ;.    ;
                   \  \    ' '   ;  \; /  |:  | | :  ' ;          \   ;  `      |'   :  ;|   | | \   |
                    '  \   |  \   \  ',  / |  ; ' |  | '           .   \    .\  ;|   |  ''   : |  ; .'
                     \  ;  ;   ;   :    /  :  | : ;  ; |            \   \   ' \ |'   :  ||   | '`--'
                      :  \  \   \   \ .'   '  :  `--'   \            :   '  |--" ;   |.' '   : |
                       \  ' ;    `---`     :  ,      .-./             \   \ ;    '---'   ;   |.'
                        `--`                `--`----'                  '---"             '---'

	)";
	SetColor(0,15);
}

void playSound(string fileName)
{
    fileName = "Sound/" + fileName;
    DWORD flags = SND_FILENAME | SND_ASYNC;
    PlaySound(fileName.c_str(), NULL, flags);
}

int gameLoop(string username, int highestPoint)
{
    Cell** Board = genBoard();
    int pokemonFreq[26] = {4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    int totalPokemon = ROW * COL;
    do
        initBoard(Board, pokemonFreq);
    while(!stillHaveLegitMove(Board));

    printBoard(Board);
    int life = 3;
    int point = 0;

    int chosenCellCount = 0;
    Cell_index chosenCell[2];
    Cell_index currentCell = {0, 0};
    printPurple(currentCell);

    printPlayerInfo(username, life, point, highestPoint);
    printTutorial();

    while(true)
    {
        int key = getKeyboard();

        if(key == 0)
        {
            clearConsole();
            deleteBoard(Board);
            cout << "\n\nPress Any Key to Go Back...";
            return point;
        }

        if(key >= 1 && key <= 4)
        {
            if(!(chosenCellCount == 1 && currentCell.x == chosenCell[0].x && currentCell.y == chosenCell[0].y))
                printBlack(currentCell);

            switch(key)
            {
                case 1: currentCell.moveLeft(Board); break;
                case 2: currentCell.moveUp(Board); break;
                case 3: currentCell.moveRight(Board); break;
                case 4: currentCell.moveDown(Board); break;
            }

            playSound("move.wav");

            if(!(chosenCellCount == 1 && currentCell.x == chosenCell[0].x && currentCell.y == chosenCell[0].y))
                printPurple(currentCell);

            continue;
        }

        if(key == 5)
        {
            if(point < 20)
                continue;
            else
            {
                point -= 20;
                updatePoint(point);
            }

            int x1, y1, x2, y2;
            findLegitMove(Board, x1, y1, x2, y2);
            printBlue({x1, y1});
            printBlue({x2, y2});
            playSound("help.wav");
            usleep(500000);

            printBlack({x1, y1});
            printBlack({x2, y2});
            printPurple(currentCell);

            if(chosenCellCount == 1 && ((chosenCell[0].x == currentCell.x && chosenCell[0].y == currentCell.y) || (chosenCell[0].x == x1 && chosenCell[0].y == y1)  || (chosenCell[0].x == x2 && chosenCell[0].y == y2)))
                printYellow(chosenCell[0]);
            continue;
        }

        if(key == 6)
        {
            if(point < 50)
                continue;
            else
                point -= 50;

            clearConsole();
            cout << "Init new board..........";
            playSound("reshuffle.wav");
            usleep(500000);

            do
                initBoard(Board, pokemonFreq);
            while(!stillHaveLegitMove(Board));

            clearConsole();
            printBoard(Board);
            printPlayerInfo(username, life, point, highestPoint);
            printTutorial();
            printPurple(currentCell);
            continue;
        }

        if(key == 7)
        {
            if(point < 30)
                continue;
            point -= 30;
            life++;
            updatePoint(point);
            updateLife(life);
            playSound("buy.wav");
            continue;
        }

        if(chosenCellCount == 0)
        {
            chosenCell[0] = currentCell;
            chosenCellCount++;
            printYellow(chosenCell[0]);
            playSound("place.wav");
            continue;
        }
        else if(chosenCellCount == 1 && currentCell.x == chosenCell[0].x && currentCell.y == chosenCell[0].y)
        {
            chosenCellCount--;
            printPurple(chosenCell[0]);
            playSound("place.wav");
            continue;
        }

        ////CONFIRM 2 CELL. START TO CHECK THE LOGIC

        chosenCell[1] = currentCell;
        chosenCellCount = 0;
        printYellow(chosenCell[1]);
        playSound("place.wav");
        usleep(500000);

        if(Board[chosenCell[0].x][chosenCell[0].y].pokemon == Board[chosenCell[1].x][chosenCell[1].y].pokemon && checkMatch(chosenCell[0], chosenCell[1], Board))
        {
            point += 10;
            updatePoint(point);

            printGreen(chosenCell[0]);
            printGreen(chosenCell[1]);
            playSound("right.wav");
            usleep(500000);

            Board[chosenCell[0].x][chosenCell[0].y].present = 0;
            Board[chosenCell[1].x][chosenCell[1].y].present = 0;
            pokemonFreq[Board[chosenCell[0].x][chosenCell[0].y].pokemon - 'A'] -= 2;
            totalPokemon -= 2;

            deleteCell(chosenCell[0]);
            deleteCell(chosenCell[1]);

            printBG(chosenCell[0]);
            printBG(chosenCell[1]);

            if(totalPokemon == 0)
            {
                usleep(2000000);
                clearConsole();
                printWinningMessage();
                playSound("win.wav");
                deleteBoard(Board);
                cout << "\n\nPress Any Key to Go Back...";
                usleep(5000000);
                return point;
            }

            if(currentCell.y < COL / 2)
                currentCell.moveRight(Board);
            else
                currentCell.moveLeft(Board);

            if(!stillHaveLegitMove(Board))
            {
                clearConsole();
                cout << "No legit move. Shuffle board...........\n";
                playSound("reshuffle.wav");
                usleep(500000);

                do
                    initBoard(Board, pokemonFreq);
                while(!stillHaveLegitMove(Board));

                clearConsole();
                printBoard(Board);
                printPlayerInfo(username, life, point, highestPoint);
                printTutorial();
            }

            printPurple(currentCell);
        }
        else
        {
            printRed(chosenCell[0]);
            printRed(chosenCell[1]);
            playSound("wrong.wav");
            usleep(500000);

            life--;
            if(life == 0)
            {
                clearConsole();
                printLosingMessage();
                playSound("lose.wav");
                deleteBoard(Board);
                cout << "\n\nPress Any Key to Go Back...";
                usleep(5000000);
                return point;
            }
            else
            {
                appear(0, 25);
                updateLife(life);

                printBlack(chosenCell[0]);
                printBlack(chosenCell[1]);
                printPurple(currentCell);
            }
        }
    }

    return 0;
}


