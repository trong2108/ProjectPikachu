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

int gameLoop()
{
    Cell** Board = genBoard();
    int pokemonFreq[26] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    int totalPokemon = ROW * COL;
    do
    {
        initBoard(Board, pokemonFreq);
    }
    while(!stillHaveLegitMove(Board));

    printBoard(Board, {0, 0});
    int life = 3;
    cout << "\n\nLife left: " << life << endl;

    int chosenCellCount = 0;
    Cell_index chosenCell[2];
    Cell_index currentCell = {0, 0};

    while(true)
    {
        int key = getKeyboard();

        //Movement key
        if(key != 5)
        {
            switch(key)
            {
                case 1: currentCell.moveLeft(); break;
                case 2: currentCell.moveUp(); break;
                case 3: currentCell.moveRight(); break;
                case 4: currentCell.moveDown(); break;
            }

            if(chosenCellCount == 0)
            {
                clearConsole();
                printBoard(Board, currentCell);
            }
            else if(chosenCellCount == 1)
            {
                clearConsole();
                printBoard(Board, currentCell, chosenCell[0]);
            }

            cout << "\n\nLife left: " << life << endl;
            continue;
        }

        //Confirm key
        if(Board[currentCell.x][currentCell.y].present)
        {
            if(chosenCellCount == 0)
            {
                chosenCell[0] = currentCell;
                chosenCellCount++;
                clearConsole();
                printBoard(Board, currentCell, chosenCell[0]);
                cout << "\n\nLife left: " << life << endl;
                continue;
            }
            else if(chosenCellCount == 1 && currentCell.x == chosenCell[0].x && currentCell.y == chosenCell[0].y)
                continue;

            chosenCell[1] = currentCell;
            chosenCellCount = 0;
            clearConsole();
            printBoard(Board, currentCell, chosenCell[0], chosenCell[1]);
            sleep(1);

            if(Board[chosenCell[0].x][chosenCell[0].y].pokemon == Board[chosenCell[1].x][chosenCell[1].y].pokemon && checkMatch(chosenCell[0], chosenCell[1], Board))
            {
                Board[chosenCell[0].x][chosenCell[0].y].present = 0;
                Board[chosenCell[1].x][chosenCell[1].y].present = 0;
                pokemonFreq[Board[chosenCell[0].x][chosenCell[0].y].pokemon - 'A'] -= 2;
                totalPokemon -= 2;

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
                    sleep(1);

                    initBoard(Board, pokemonFreq);
                    while(!stillHaveLegitMove(Board))
                        initBoard(Board, pokemonFreq);
                }

                clearConsole();
                printBoard(Board, currentCell);
                cout << "\n\nLife left: " << life << endl;
            }
            else
            {
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
                    clearConsole();
                    printBoard(Board, currentCell);
                    cout << "\n\nLife left: " << life << endl;

                    cout << "Sugguested move: ";
                    int x1, y1, x2, y2;
                    findLegitMove(Board, x1, y1, x2, y2);
                    cout << x1 << " " <<  y1 << " " << x2 << " " << y2 << endl;
                }
            }
        }
    }
    return 0;
}


