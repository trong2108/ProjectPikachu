//Game logo
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

//Losing message
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

//Winning message
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

//Play a .wav file
void playSound(string fileName)
{
    fileName = "Sound/" + fileName;
    DWORD flags = SND_FILENAME | SND_ASYNC;
    PlaySound(fileName.c_str(), NULL, flags);
}

//The main game
int gameLoop(string username, int highestPoint)
{
    //The 2D pointer array to save all the cell
    Cell** Board = genBoard();
    //The array to keep track of the appearance of each pokemon inside Board
    int pokemonFreq[26] = {4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    //The total number of pokemon
    int totalPokemon = ROW * COL;
    //Give every cell in the Board a random pokemon
    do
        initBoard(Board, pokemonFreq);
    while(!stillHaveLegitMove(Board));

    //Print the Board
    printBoard(Board);

    //String life and point
    int life = 3;
    int point = 300;

    //The number of cell have been chosen
    int chosenCellCount = 0;
    //2 element array to save all the chosen cell
    Cell_index chosenCell[2];
    //The current cell the cursor is on
    Cell_index currentCell = {0, 0};
    printPurple(currentCell);

    //Print the 2 informatin board
    printPlayerInfo(username, life, point, highestPoint);
    printTutorial();

    //The game loop start
    while(true)
    {
        int key = getKeyboard();

        if(key == 0) // ESC key
        {
            clearConsole();
            deleteBoard(Board);
            cout << "\n\nPress Any Key to Go Back...";
            return point;
        }

        if(key >= 1 && key <= 4) // Movement key
        {
            //Make the old cell back if it is not a chosen cell
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

            //Make the new cell purple if it is not a chosen cell
            if(!(chosenCellCount == 1 && currentCell.x == chosenCell[0].x && currentCell.y == chosenCell[0].y))
                printPurple(currentCell);

            continue;
        }

        if(key == 5) // Help key
        {
            //Do not let the user use the help if they do not have enough point
            if(point < 20)
                continue;
            else
            {
                point -= 20;
                updatePoint(point);
            }

            int x1, y1, x2, y2;
            findLegitMove(Board, x1, y1, x2, y2);
            //Make the two cell highlighted in blue for a breif moment
            printBlue({x1, y1});
            printBlue({x2, y2});
            playSound("help.wav");
            usleep(500000);

            //Return every cell to its original color
            printBlack({x1, y1});
            printBlack({x2, y2});
            printPurple(currentCell);
            if(chosenCellCount == 1)
                printYellow(chosenCell[0]);
            continue;
        }

        if(key == 6) // Reshuffle key
        {
            //Do not let the user use the help if they do not have enough point
            if(point < 50)
                continue;
            else
                point -= 50;

            clearConsole();
            cout << "Init new board..........";
            playSound("reshuffle.wav");
            usleep(500000);

            //Reshuffle board until we meet a legit one
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

        if(key == 7) // Buying life key
        {
            //Do not let the user use the help if they do not have enough point
            if(point < 30)
                continue;
            point -= 30;
            life++;
            updatePoint(point);
            updateLife(life);
            playSound("buy.wav");
            continue;
        }

        //At this point we are guarantee that the key is Space or Enter

        if(chosenCellCount == 0)  //Choose the fisrt cell
        {
            chosenCell[0] = currentCell;
            chosenCellCount++;
            //Make the chosen cell yellow
            printYellow(chosenCell[0]);
            playSound("place.wav");
            continue;
        }
        else if(chosenCellCount == 1 && currentCell.x == chosenCell[0].x && currentCell.y == chosenCell[0].y)  // Unchoose a cell
        {
            chosenCellCount--;
            //Make the cell purple again
            printPurple(chosenCell[0]);
            playSound("place.wav");
            continue;
        }

        ////CONFIRM 2 CELL. START TO CHECK THE LOGIC

        chosenCell[1] = currentCell;
        chosenCellCount = 0;
        //Make the second chosen cell yellow in a brief moment before checking the logic
        printYellow(chosenCell[1]);
        playSound("place.wav");
        usleep(500000);

        if(Board[chosenCell[0].x][chosenCell[0].y].pokemon == Board[chosenCell[1].x][chosenCell[1].y].pokemon && checkMatch(chosenCell[0], chosenCell[1], Board))  // Check the logic if the 2 is matched
        {
            //Update point
            point += 10;
            updatePoint(point);

            //Inform the two cell is matched
            printGreen(chosenCell[0]);
            printGreen(chosenCell[1]);
            playSound("right.wav");
            usleep(500000);

            //Update variable
            Board[chosenCell[0].x][chosenCell[0].y].present = 0;
            Board[chosenCell[1].x][chosenCell[1].y].present = 0;
            pokemonFreq[Board[chosenCell[0].x][chosenCell[0].y].pokemon - 'A'] -= 2;
            totalPokemon -= 2;

            //Make the two cells disappear
            deleteCell(chosenCell[0]);
            deleteCell(chosenCell[1]);

            //Print the background there
            printBG(chosenCell[0]);
            printBG(chosenCell[1]);

            //Check if the winning condition is met
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

            //Move the current cell away from the blank space
            currentCell.moveRight(Board);
            currentCell.moveLeft(Board);

            //If the board have no legit move left, shuffle it
            if(!stillHaveLegitMove(Board))
            {
                clearConsole();
                cout << "No legit move. Shuffle board...........\n";
                playSound("reshuffle.wav");
                usleep(500000);

                //Keep reshuffle the board until we meet a legit one
                do
                    initBoard(Board, pokemonFreq);
                while(!stillHaveLegitMove(Board));

                clearConsole();
                printBoard(Board);
                printPlayerInfo(username, life, point, highestPoint);
                printTutorial();
            }

            //Highlighted the current cell
            printPurple(currentCell);
        }
        else // The 2 cell is not matched
        {
            //Inform the user that the 2 cell is not matched
            printRed(chosenCell[0]);
            printRed(chosenCell[1]);
            playSound("wrong.wav");
            usleep(500000);

            life--;
            if(life == 0)  // Check if the losing condition is met
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
                //Update life
                appear(0, 25);
                updateLife(life);

                //Unchoose the 2 wrong cell and highlighted the current cell
                printBlack(chosenCell[0]);
                printBlack(chosenCell[1]);
                printPurple(currentCell);
            }
        }
    }

    return 0;
}


