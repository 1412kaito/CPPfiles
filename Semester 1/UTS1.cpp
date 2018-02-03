#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int N;
    do
    {
        system("CLS");
        cout << "Inputkan nilai N : ";
        cin >> N;
    } while (N<1 || N%1111==0 || N>9999);
    int acc=1, maks, minim;
    short d1, d2, d3, d4, temp;
    cout << N;
    do
    {
        acc += 1;
        d1 = N / 1000 % 10;
        d2 = N / 100 % 10;
        d3 = N / 10 % 10;
        d4 = N % 10;

        if (d1 > d2){
            temp = d1;
            d1 = d2;
            d2 = temp;
        }
        if (d1 > d3){
            temp = d1;
            d1 = d3;
            d3 = temp;
        }
        if (d1 > d4){
            temp = d1;
            d1 = d4;
            d4 = temp;
        }
        if (d2 > d3){
            temp = d2;
            d2 = d3;
            d3 = temp;
        }
        if (d2 > d4){
            temp = d2;
            d2 = d4;
            d4 = temp;
        }
        if (d3 > d4){
            temp = d3;
            d3 = d4;
            d4 = temp;
        }

        maks = d4*1000+d3*100+d2*10+d1;
        minim = d1*1000+d2*100+d3*10+d4;
        N = maks - minim;
        cout << "->" << N ;
    }while (N > 6174);
        cout << endl << acc;


    return 0;
}
