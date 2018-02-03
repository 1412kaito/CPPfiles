#include <iostream>

using namespace std;
int main()
{
    int N, M, temp, temp2, i;

    cout << "Inputkan nilai N : ";
    cin >> N;
    cout << "Inputkan nilai M: ";
    cin >> M;

    if (M > N)
    {
        temp = N;
        N = M;
        M = temp;
    }
    temp = 1;
    temp2 = 1;
    i = N+1;
    while (temp2!=0 || temp!=0)
    {
        i -= 1;
        temp = N % i;
        temp2= M % i;
    }
    cout << "FPB : " << i;

    return 0;
}
