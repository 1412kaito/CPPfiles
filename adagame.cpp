#include <iostream>
#include <cstring>
#include <cmath>
//#include <conio.h>
using namespace std;

const int MAX = 10005;

int T;
int turns;
int digits[4];
string number;
string dp[101][10][10][10][10];

string solve(int step, string number)
{
    if (step > turns)
    {
        return number;
    }
    for (int i = 0; i < 4; i ++)
    {
        digits[i] = number[i] - '0';
    }
    string &result = dp[step][digits[0]][digits[1]][digits[2]][digits[3]];
    if (result != "-1")
    {
        return result;
    }
    if (step & 1)
    {
        result = "0000";
    }
    else
    {
        result = "9999";
    }
    for (int i = 0; i < 4; i ++)
    {
        string to = number;
        to[i] = (to[i] - '0' + 1) % 10 + '0';
        if (step & 1)
        {
            result = max(result, solve(step + 1, to));
        }
        else
        {
            result = min(result, solve(step + 1, to));
        }
    }
    //cout << "Step: " << step << " | Result: "<<result<<"\n";
    //getch();
    return result;
}

int main()
{
    cin >> T;
    while (T --)
    {
        for (int i = 1; i < 101; i ++)   // turns
        {
            for (int j = 0; j < 10; j ++)   // first digit
            {
                for (int k = 0; k < 10; k ++)   // second digit
                {
                    for (int q = 0; q < 10; q ++)   // third digit
                    {
                        for (int l = 0; l < 10; l ++)   // forth digit
                        {
                            dp[i][j][k][q][l] = "-1";
                        }
                    }
                }
            }
        }
        cin >> number >> turns;
        if (solve(1, number) > number)
        {
            cout << "Doni" << endl;
        }
        else
        {
            cout << "Dodi" << endl;
        }
    }

    return 0;
}
