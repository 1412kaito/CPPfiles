#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int angka, panjang;

    cout << "Masukkan bilangan : ";
    cin >> angka;
    panjang = log10(angka) + 1;

    int depan, belakang;
    if ((panjang % 2) == 0){
        depan = angka / (int)(pow(10,(panjang/2))+0.1);
        belakang = angka % (int)(pow(10,(panjang/2))+0.1);
    }
    else {
        depan = angka / (int)(pow(10, (panjang/2 + 1))+0.1);
        belakang = angka % (int)(pow(10,(panjang / 2))+0.1);
    }
    string hasil;
    //cout << depan << endl << belakang << endl;
    //cout << panjang;
    int cek = panjang;
    cek /= 2;
    for (int i=1; i<=cek; i++){
        int dDepan, dBelakang;
        dDepan = panjang / 2;
        dBelakang = panjang / 2;
        //cout << dDepan << endl << dBelakang << endl;
        int evalDepan, evalBelakang;
        evalDepan = (depan / (int)(pow(10, (dDepan - i))+0.1)) % 10;
        evalBelakang = (belakang % (int)(pow(10,i)+0.1)) / (int)(pow(10, (i-1))+0.1);
        //cout << evalDepan << endl << evalBelakang << endl;
        if (evalDepan != evalBelakang) {
            i = (panjang+1)/2;
            hasil = "Bukan Palindrom";
        } else {
            hasil = "Palindrom";
        }
    }
    cout << hasil ;
    return 0;
}
