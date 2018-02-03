#include <iostream>

using namespace std;

int main()
{
    int bil1, bil2;

    cout << "Inputkan 2 buah bilangan bulat positif : " << endl;
    cin >> bil1;
    cin >> bil2;

    int acc =0, hasilmod =1;

    while (hasilmod !=0)
    {
        acc +=bil1;
        hasilmod = acc % bil2;
    }

    cout << "KPK : " << acc << endl;

    //cari faktor masing - masing angka;
    int mod1, mod2;
    int fpb = (bil2>bil1)?(bil2):(bil1);
    fpb = fpb+1;
    while (mod1!=0 || mod2!=0){
        fpb -= 1;
        mod1 = bil1 % fpb;
        mod2 = bil2 % fpb;
    }
    cout << "FPB : " << fpb;


    return 0;
}
