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
    cout << atoi(temp.c_str()) << endl;

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

