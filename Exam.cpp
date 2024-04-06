#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//1a
bool pointRecover(int point[], int n)
{
    if(n < 3) return 0;

    int dis;

    if(n == 3)
        if(point[0] == -1) dis = point[2] - point[1];
        else if(point[1] == -1) dis = (point[2] - point[0]) / 2;
        else dis = point[1] - point[0];

    if(point[0] == -1 || point[1] == -1) dis = point[3] - point[2];
    else dis = point[1] - point[0];

    if(dis <= 0) return 0;

    for(int i = 1; i < n; i++)
        if(point[i] - point[i - 1] != dis && point[i - 1] != -1 && point[i] != -1)
            return 0;

    for(int i = 0; i < n; i++)
        if(point[i] == -1)
        {
            if(i == 0) point[0] = point[1] - dis;
            else if(i == n - 1) point[n - 1] = point[n - 2] + dis;
            else if(point[i - 1] + dis != point[i + 1] - dis) return 0;
            else point[i] = point[i - 1] + dis;

            return 1;
        }

    return 0;
}

bool check(int arr[], int Start, int End)
{
    if(End - Start + 1 < 3) return 0;
    for(int i = Start + 1; i < End; i++)
        if(2 * arr[i] != arr[i + 1] + arr[i - 1])
            return 0;
    return 1;
}

//1b
bool maxAscend(int point[], int n, int &Start, int &End)
{
    for(int len = n; len >= 3; len--)
        for(int i = n - len; i >= 0; i--)
            if(check(point, i, i + len -1))
            {
                Start = i;
                End = i + len - 1;
                return 1;
            }
    return 0;
}

int convert(char s[])
{
    int result = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        int value = s[i] - 'a';
        if(value < 10) result = result * 10 + value;
        else result = result * 100 + value;
    }
    return result;
}

int main()
{

    int point[] = {0, 10, 20, 40, 60, 100};
    int n = sizeof(point) / sizeof(int);

    int Start = 0, End = 0;

    cout << maxAscend(point, n, Start, End) << "\n";
    cout << Start << "\t" << End << "\n";

//    char s[100];
//    cin.getline(s, 100);
//    cout << convert(s);


    return 0;

}
