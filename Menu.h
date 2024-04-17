
void printButton(short x, short y, short background_color, short text_color)
{
    short width = 2;
    short length = 30;
    appear(x, y);
    SetColor(background_color, text_color);
    putchar(218);
    for(int i = 0; i < length; i++)
        putchar(196);
    putchar(191);
    for (int i = 1; i < width; i ++)
    {
        appear(x, y + i);
        putchar(179);
        appear(x + length + 1, y + i);
        putchar(179);
    }
    appear(x, y + width);
    putchar(192);
    for(int i = 0; i < length; i++)
        putchar(196);
    putchar(217);
}
void unchooseButton(string ButtonName)
{
    short x = 32;
    short y = 16;
    if(ButtonName == "LEADER BOARD")
        y += 4;
    else if(ButtonName == "EXIT")
        y += 8;
    printButton(x,y,0,15);
    SetColor(0,15);
    int namelength = ButtonName.length();
    appear(x + (32 - namelength)/2, y + 1);
    cout << ButtonName;
}
void chooseButton(string ButtonName)
{
    short x = 32;
    short y = 16;
    if(ButtonName == "LEADER BOARD")
        y += 4;
    else if(ButtonName == "EXIT")
        y += 8;
    printButton(x,y,15,0);
    int namelength = ButtonName.length();
    appear(x + 1, y + 1);
    SetColor(15,0);
    for(int i = 0; i < 30; i++)
        cout << " ";
    appear(x + (32 - namelength)/2, y + 1);
    SetColor(15,0);
    cout << ButtonName;
//    SetColor(0,15);
}
void printMenu()
{
    printGameTitle();
    unchooseButton("PLAY");
    unchooseButton("LEADER BOARD");
    unchooseButton("EXIT");
}
void deleteMenu()
{

}
