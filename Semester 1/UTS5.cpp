#include <iostream>

using namespace std;

int main ()
{
    int N, M, temp;

    cout << "Inputkan nilai N (bulat, positif): ";
    cin >> N;
    cout << "Inputkan nilai M (bulat, positif): ";
    cin >> M;

    if (N > M)
    {
        temp = N;
        N = M;
        M = temp;
    }
    while (M % N > 0)
    {
        temp = N;
        N = M;
        M = temp;
        N = N % M;
    }
    cout << "FPB : "<<N;

    return 0;
}
