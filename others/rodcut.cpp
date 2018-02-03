#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct pairs{
    int meter;
    int harga;
};

bool pecahan(double panjang){
    if (floor(panjang) != panjang)
        return true;
    else
        return false;
}

int main(){
    double panjang;
    cin >> panjang;
    vector<pairs> rods;
    vector<double> price;
    pairs temp;
    double temps;
    while (panjang < 0 || pecahan(panjang)){
        cout << "Input salah, input benar: \n";
        cin >> panjang;
    }
    for (int i=0; i<panjang; ++i){
        temp.meter = i+1;
        cin >> temp.harga;
        rods.push_back(temp);
        temps = (float)temp.harga / (float)temp.meter;
        price.push_back(temps);
    }
    //price per meter

    int rodlength = panjang;
    int output = 0;
    while (rodlength > 0){
        double maks = 0;
        int idx;;
        for (int i=0; i<rodlength; ++i){
            if (price[i]>maks){
                maks = price[i];
                idx = i;
            }
        }
        output += rods[idx].harga;
        rodlength -= idx+1;
    }
    cout << output;
    return 0;
}
