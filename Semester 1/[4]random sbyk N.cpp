#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int n, bilrand;
    int temp;
    cout << "Inputkan N : ";
    cin >> n;

    int prime_counter;
    for (int i=1; i <= n; i++)
    {

        bilrand = rand()%n + 1;
        int cek;
        temp = 1;
        while (temp == 1)
        {
            bilrand = rand()%n + 1;
            for (int cekprime=2; cekprime < bilrand; cekprime++){
                cek = bilrand % cekprime;
                if (cek == 0)
                {
                    temp = 0;
                    cekprime = bilrand;
                }
            }
        }
        cout << bilrand << " ";
    }
    return 0;
}

