struct Player
{
    string username;
    int point;
};

bool findAccount(string username, int &highestPoint)
{
    ifstream fin("UserInfo.txt");
    if(!fin)
        return false;

    string temp;
    getline(fin, temp);

    while(!fin.eof())
    {
        getline(fin, temp, '/');
        if(temp == username)
        {
            getline(fin, temp);
            highestPoint = atoi(temp.c_str());
            fin.close();
            return true;
        }
        getline(fin, temp);
    }

    fin.close();
    highestPoint = 0;
    return false;
}

Player* readInfo(int &Size)
{
    ifstream fin("UserInfo.txt");
    if(!fin)
        return NULL;

    string temp;
    getline(fin, temp);
    Size = atoi(temp.c_str());
    Player* Players = new Player [Size];

    int pos = 0;
    while(!fin.eof())
    {
        getline(fin, Players[pos].username, '/');
        getline(fin, temp);
        Players[pos].point = atoi(temp.c_str());
        pos++;
    }

    fin.close();
    return Players;
}

void rewriteOldAccount(string username, int point)
{
    int Size;
    Player* Players = readInfo(Size);

    ofstream fout("UserInfo.txt");
    fout << Size << "\n";
    for(int i = 0; i < Size; i++)
    {
        if(Players[i].username == username)
            fout << username << "/" << max(point, Players[i].point);
        else
            fout << Players[i].username << "/" << Players[i].point;

        if(i != Size - 1)
            fout << "\n";
    }

    delete[] Players;
    fout.close();
}

void writeNewAccount(string username, int point)
{
    int Size;
    Player* Players = readInfo(Size);

    ofstream fout("UserInfo.txt");
    fout << Size + 1 << "\n";
    for(int i = 0; i < Size; i++)
        fout << Players[i].username << "/" << Players[i].point << "\n";

    fout << username << "/" << point;

    delete[] Players;
    fout.close();
}

void printChar(char c, int n)
{
    for(int i = 0; i < n; i++)
        cout << c;
}

int numLen(int n)
{
    if(n <= 0)
        return 1;
    else
        return log10(n) + 1;
}

void printLeaderBoard()
{
    int Size;
    Player* Players = readInfo(Size);

    for(int i = 0; i < Size - 1; i++)
        for(int j = i + 1; j < Size; j++)
            if(Players[i].point < Players[j].point)
            {
                Player temp = Players[i];
                Players[i] = Players[j];
                Players[j] = temp;
            }

    SetColor(0,3);
    cout << R"(
 __    ____    __    ____  ____  ____  ____  _____    __    ____  ____
(  )  ( ___)  /__\  (  _ \( ___)(  _ \(  _ \(  _  )  /__\  (  _ \(  _ \
 )(__  )__)  /(__)\  )(_) ))__)  )   / ) _ < )(_)(  /(__)\  )   / )(_) )
(____)(____)(__)(__)(____/(____)(_)\_)(____/(_____)(__)(__)(_)\_)(____/
               )";
    SetColor(0, 15);
    cout << "\n";
    for(int i = 0; i < Size - 1; i++)
    {
        printChar('_', 115);
        cout << endl << endl;
        cout << Players[i].username;
        printChar('.', 115 - Players[i].username.length() - (numLen(Players[i].point)));
        cout << Players[i].point;
        cout << endl << endl;

    }
    printChar('_', 115);
    cout << endl;

    delete[] Players;
}



