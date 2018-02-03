#include <bits/stdc++.h>
using namespace std;

bool kabisat(int oyeah){
    if (oyeah%400==0 || (oyeah%4==0 && oyeah%100!=0)) { return true; }
    else { return false; }
}

int main(){
    string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    int tahun, temp;
    short tanggal, bulan;
    string doomsday; short dday;
    short selisih;
    bool whil = true;
    do {
            cout << "Inputkan yyyy mm dd: (input 0 0 0 to exit)" << endl;
            cin >> tahun >> bulan >> tanggal;
        if (!(tahun==0 && bulan==0 && tanggal==0))
        {
            temp = tahun;
            temp /= 100;
            temp *= 100;
            switch (temp%400){
                case 0:
                    dday = 2;
                    break;
                case 100:
                    dday = 0;
                    break;
                case 200:
                    dday = 5;
                    break;
                case 300:
                    dday = 3;
                    break;
            }
            temp = tahun - temp;
            temp = (temp%12) + temp/12 + (temp%12/4);
            dday = (dday + temp) % 7;
            doomsday = days[dday];
            //cout << "Doomsday: " << doomsday << endl;

            if (kabisat(tahun)){
                if (bulan==1 || bulan==2){
                    if (bulan==1){ selisih=(tanggal-4); }
                    else { selisih=(tanggal-29); }
                }
            }
            else {
                if (bulan==1 || bulan==2){
                    if (bulan==1){ selisih=(tanggal-3); }
                    else { selisih=(tanggal-28); }
                }
            }
            switch (bulan){
                case 3: selisih=(tanggal-14); break;
                case 4: selisih=(tanggal-4); break;
                case 5: selisih=(tanggal-9); break;
                case 6: selisih=(tanggal-6); break;
                case 7: selisih=(tanggal-11); break;
                case 8: selisih=(tanggal-8); break;
                case 9: selisih=(tanggal-5); break;
                case 10: selisih=(tanggal-10); break;
                case 11: selisih=(tanggal-7); break;
                case 12: selisih=(tanggal-12); break;
            }
            selisih = selisih%7;
            selisih += dday;
            if (selisih<0) selisih +=7;

            cout << "I believe it was a lovely "<< days[selisih] << endl;
        }
        else { whil = false; }
    } while (whil);
    return 0;
}
