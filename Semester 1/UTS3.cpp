#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double suku = 1;
    double temp = 0;
    short n = 1;

    while (suku > 0.01)
    {
        suku = 1.0 / (sqrt(n*(n+1)));
        temp += suku;
        n++;
    }

    cout << "Hasil : " << temp;


    return 0;
}
