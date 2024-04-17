struct Player
{
    string username;
    int point;
};

bool findAccount(string username)
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
            fin.close();
            return true;
        }
        getline(fin, temp);
    }

    return false;
    fin.close();
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

bool rewriteOldAccount(string username, int point)
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

bool writeNewAccount(string username, int point)
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

    cout << "LEADERBOARD\n";
    for(int i = 0; i < Size - 1; i++)
    {
        printChar('-', 100);
        cout << endl;
        cout << Players[i].username;
        printChar('.', 100 - Players[i].username.length() - (log10(Players[i].point) + 1));
        cout << Players[i].point;
        cout << endl;

    }
    printChar('-', 100);
    cout << endl;

    delete[] Players;
}



