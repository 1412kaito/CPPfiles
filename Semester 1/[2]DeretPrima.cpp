#include <iostream>
#include <conio.h>
using namespace std;

int main(){
    int satu, dua, tiga, empat, lima;
    cout << "Inputkan 5 bilangan bulat : ";
    cin >> satu >> dua >> tiga >> empat >> lima;

    int acc=0;
    char cekprima = 'P', cek = 'P';
    //mass - prime checking;
    for (int i = 2; i<satu; i++)
    {
        int cek1;
        cek1 = satu % i;
        if (cek1 == 0) {
            cekprima = 'B';
            i = satu;
        }
    }
    for (int i = 2; i<dua; i++)
    {
        int cek2;
        cek2 = dua % i;
        if (cek2 == 0) {
            cekprima = 'B';
            i = dua;
        }
    }
    for (int i = 2; i<tiga; i++)
    {
        int cek3;
        cek3 = tiga % i;
        if (cek3 == 0) {
            cekprima = 'B';
            i = tiga;
        }
    }
    for (int i = 2; i<empat; i++)
    {
        int cek4;
        cek4 = empat % i;
        if (cek4 == 0) {
            cekprima = 'B';
            i = empat;
        }
    }
    for (int i = 2; i<lima; i++)
    {
        int cek5;
        cek5 = lima % i;
        if (cek5 == 0) {
            cekprima = 'B';
            i = lima;
        }
    }

    int pembanding = satu + dua + tiga + empat + lima;

    if (cekprima == 'P'){
        int counter = 1;
        if (satu < dua && dua < tiga && tiga < empat && empat < lima)
        {
            while (counter <=5){
                for (int i=2; i<satu; i++){
                    if ((satu%i) == 0){
                        cek = 'B';
                        i = satu;
                    }
                }
                if (cek == 'P') {
                    counter += 1;
                    acc += satu;
                } else {}
            satu++;
            cek ='P';
            }
            if (pembanding == acc)
            {
                cout << "Ya";
            } else cout << "Tidak";
        }
        else if (satu > dua && dua > tiga && tiga > empat && empat > lima)
        {
            while (counter <=5){
                for (int i=2; i<lima; i++){
                    if ((lima%i) == 0){
                        cek = 'B';
                        i = lima;
                    }
                }
                if (cek == 'P') {
                    counter += 1;
                    acc += lima;
                } else {}
            lima++;
            cek ='P';
            }
            if (pembanding == acc)
            {
                cout << "Ya";
            } else cout << "Tidak";
        }
        else cout << "Tidak1";
    } else cout << "Tidak2";
    return 0;
}
