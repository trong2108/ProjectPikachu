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
	cout << logo;
	cout << R"(
  _____  _  _  ___   __  __    _  _____  ___  _  _  ___  _  _   ___    ___    _    __  __  ___
 |_   _|| || || __| |  \/  |  /_\|_   _|/ __|| || ||_ _|| \| | / __|  / __|  /_\  |  \/  || __|
   | |  | __ || _|  | |\/| | / _ \ | | | (__ | __ | | | | .` || (_ | | (_ | / _ \ | |\/| || _|
   |_|  |_||_||___| |_|  |_|/_/ \_\|_|  \___||_||_||___||_|\_| \___|  \___|/_/ \_\|_|  |_||___|
	)";
}

void printLosingMessage()
{
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
}

void printWinningMessage()
{
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
}

int gameLoop_new()
{
    Cell** Board = genBoard();
    int pokemonFreq[26] = {4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    int totalPokemon = ROW * COL;
    do
    {
        initBoard(Board, pokemonFreq);
    }
    while(!stillHaveLegitMove(Board));

    printBoard(Board);
    int life = 3;
    cout << "\n\nLife left: " << life << endl;

    int chosenCellCount = 0;
    Cell_index chosenCell[2];
    Cell_index currentCell = {0, 0};
    printPurple(Board, currentCell);

    while(true)
    {
        int key = getKeyboard();

        if(key != 5)
        {
            if(!(chosenCellCount == 1 && currentCell.x == chosenCell[0].x && currentCell.y == chosenCell[0].y))
                printBlack(Board, currentCell);

            switch(key)
            {
                case 1: currentCell.moveLeft(); break;
                case 2: currentCell.moveUp(); break;
                case 3: currentCell.moveRight(); break;
                case 4: currentCell.moveDown(); break;
            }

            if(!(chosenCellCount == 1 && currentCell.x == chosenCell[0].x && currentCell.y == chosenCell[0].y))
                printPurple(Board, currentCell);

            continue;
        }

        if(Board[currentCell.x][currentCell.y].present)
        {
            if(chosenCellCount == 0)
            {
                chosenCell[0] = currentCell;
                chosenCellCount++;
                printYellow(chosenCell[0]);
                continue;
            }
            else if(chosenCellCount == 1 && currentCell.x == chosenCell[0].x && currentCell.y == chosenCell[0].y)
            {
                chosenCellCount--;
                printPurple(Board, chosenCell[0]);
                continue;
            }

            chosenCell[1] = currentCell;
            chosenCellCount = 0;
            printYellow(chosenCell[1]);
            usleep(500000);

            if(Board[chosenCell[0].x][chosenCell[0].y].pokemon == Board[chosenCell[1].x][chosenCell[1].y].pokemon && checkMatch(chosenCell[0], chosenCell[1], Board))
            {
                printGreen(chosenCell[0]);
                printGreen(chosenCell[1]);
                usleep(500000);

                Board[chosenCell[0].x][chosenCell[0].y].present = 0;
                Board[chosenCell[1].x][chosenCell[1].y].present = 0;
                pokemonFreq[Board[chosenCell[0].x][chosenCell[0].y].pokemon - 'A'] -= 2;
                totalPokemon -= 2;

                deleteCell(chosenCell[0]);
                deleteCell(chosenCell[1]);

                if(totalPokemon == 0)
                {
                    clearConsole();
                    printWinningMessage();
                    deleteBoard(Board);
                    return 1;
                }

                if(!stillHaveLegitMove(Board))
                {
                    clearConsole();
                    cout << "No legit move. Shuffle board...........\n";
                    usleep(500000);

                    initBoard(Board, pokemonFreq);
                    while(!stillHaveLegitMove(Board))
                        initBoard(Board, pokemonFreq);
                }

                clearConsole();
                printBoard(Board);
                printPurple(Board, currentCell);
            }
            else
            {
                printRed(chosenCell[0]);
                printRed(chosenCell[1]);
                usleep(500000);

                life--;
                if(life == 0)
                {
                    clearConsole();
                    printLosingMessage();
                    deleteBoard(Board);
                    return 0;
                }
                else
                {
                    appear(0, 25);
                    cout << "Life left: " << life << endl;

                    cout << "Sugguested move: ";
                    int x1, y1, x2, y2;
                    findLegitMove(Board, x1, y1, x2, y2);
                    cout << x1 << " " <<  y1 << " " << x2 << " " << y2 << endl;

                    printBlack(Board, chosenCell[0]);
                    printBlack(Board, chosenCell[1]);
                    printPurple(Board, currentCell);
                }
            }
        }
    }
    return 0;
}



