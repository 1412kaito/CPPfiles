#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int mainmenu;
    //untuk no1
    int panjang, lebar;
    int angka;
    //untuk no2
    int kotak, jumlahX, jumlahO, giliran;
    char isi1=' ', isi2=' ', isi3=' ', isi4=' ', isi5=' ';
    char isi6=' ', isi7=' ', isi8=' ', isi9=' ';
    string hasil;
    //untuk no3
    int bom1, bom2, bom3;
    int hitung;


    cout << "    Menu: " << endl;
    cout << "1.  Papan ular tangga" << endl;
    cout << "2.  Papan tic tac toe" << endl;
    cout << "3.  Papan minesweeper" << endl;
    cout << ">>> " ;
    cin >> mainmenu;

    switch (mainmenu)
    {
        case 1:
            {
                cout << "Panjang : " ;
                cin >> panjang;
                cout << "Lebar   : " ;
                cin >> lebar;
                angka = panjang * lebar;

                cout << endl;
                // bila ganjil, lakukan ini terlebih dahulu
                if (lebar%2 != 0) {
                    //border
                    for (int kanan = 0; kanan < panjang; kanan++) {
                        cout << "+---";
                    }
                    cout << "+" << endl;
                    //increase ganjil
                    for (int kanan = (angka - panjang + 1); kanan <= angka; kanan++) {
                        cout << "|";
                        if (kanan > 99) {
                            cout << kanan;
                        } else if (kanan > 9) {
                            cout << " " << kanan;
                        } else if (kanan > 0) {
                            cout << "  " << kanan;
                        }
                    }
                    cout << "|" << endl;
                    angka -= panjang;
                }
                for (int bawah = 1; bawah <= lebar/2; bawah++) {
                    for (int kanan = 0; kanan < panjang; kanan++) {
                        cout << "+---";
                    }
                    cout << "+" << endl;
                    //decrease genap
                    for (int kanan = angka; kanan > angka - panjang; kanan--) {
                        cout << "|";
                        if (kanan > 99) {
                            cout << kanan;
                        } else if (kanan > 9) {
                            cout << " " << kanan;
                        } else if (kanan > 0) {
                            cout << "  " << kanan;
                        }
                    }
                    cout << "|" << endl;
                    angka -= panjang;

                    for (int kanan = 0; kanan < panjang; kanan++) {
                        cout << "+---";
                    }
                    cout << "+" << endl;
                    //increase ganjil
                    for (int kanan = (angka - panjang + 1) ; kanan <= angka; kanan++) {
                        cout << "|";
                        if (kanan > 99) {
                            cout << kanan;
                        } else if (kanan > 9) {
                            cout << " " << kanan;
                        } else if (kanan > 0) {
                            cout << "  " << kanan;
                        }
                    }
                    cout << "|" << endl;
                    angka -= panjang;
                }

                for (int kanan = 0; kanan < panjang; kanan++) {
                        cout << "+---";
                    }
                    cout << "+" << endl;

            } break;
        case 2:
            {
                jumlahX = rand()%2+2;
                jumlahO = (jumlahX==2)?(3):jumlahX + rand()%2;
                giliran = 0;
                do {
                    kotak = rand()%8+1;
                    switch (kotak){
                        case 1:
                        {
                            if ((jumlahO!=0) && giliran!= 0 && isi1 ==' ') {
                                isi1 = 'O';
                                jumlahO--;
                                giliran--;
                            }
                            else if ((jumlahX!=0) && giliran%2 ==0 && isi1 ==' ') {
                                isi1 = 'X';
                                jumlahX--;
                                giliran--;
                            } else giliran++;
                        } break;
                        case 2:
                        {
                            if ((jumlahO!=0) && giliran%2 !=0 && isi2 ==' ') {
                                isi2 = 'O';
                                jumlahO--;
                                giliran--;
                            }
                            else if ((jumlahX!=0) && giliran%2 ==0 && isi2 ==' ') {
                                isi2 = 'X';
                                jumlahX--;
                                giliran--;
                            } else giliran++;
                        } break;
                        case 3:
                        {
                            if ((jumlahO!=0) && giliran%2 !=0 && isi3 ==' ') {
                                isi3 = 'O';
                                jumlahO--;
                                giliran--;
                            }
                            else if ((jumlahX!=0) && giliran%2 ==0 && isi3 ==' ') {
                                isi3 = 'X';
                                jumlahX--;
                                giliran--;
                            } else giliran++;
                         }   break;
                        case 4:
                        {
                            if ((jumlahO!=0) && giliran%2 !=0 && isi4 ==' ') {
                                isi4 = 'O';
                                jumlahO--;
                                giliran--;
                            }
                            else if ((jumlahX!=0) && giliran%2 ==0 && isi4 ==' ') {
                                isi4 = 'X';
                                jumlahX--;
                                giliran--;
                            } else giliran++;
                        } break;
                        case 5:
                        {
                            if ((jumlahO!=0) && giliran%2 !=0 && isi5 ==' ') {
                                isi5 = 'O';
                                jumlahO--;
                                giliran--;
                            }
                            else if ((jumlahX!=0) && giliran%2 ==0 && isi5 ==' ') {
                                isi5 = 'X';
                                jumlahX--;
                                giliran--;
                            } else giliran++;
                        } break;
                        case 6:
                        {
                            if ((jumlahO!=0) && giliran%2 !=0 && isi6 ==' ') {
                                isi6 = 'O';
                                jumlahO--;
                                giliran--;
                            }
                            else if ((jumlahX!=0) && giliran%2 == 0 && isi6 ==' ') {
                                isi6 = 'X';
                                jumlahX--;
                                giliran--;
                            } else giliran++;
                        } break;
                        case 7:
                        {
                            if ((jumlahO!=0) && giliran%2 !=0 && isi7 ==' ') {
                                isi7 = 'O';
                                jumlahO--;
                                giliran--;
                            }
                            else if ((jumlahX!=0) && giliran%2 ==0 && isi7 ==' ') {
                                isi7 = 'X';
                                jumlahX--;
                                giliran--;
                            } else giliran++;
                        } break;
                        case 8:
                        {
                            if ((jumlahO!=0) && giliran%2 !=0 && isi8 ==' ') {
                                isi8 = 'O';
                                jumlahO--;
                                giliran--;
                            }
                            else if ((jumlahX!=0) && giliran%2 ==0 && isi8 ==' ') {
                                isi8 = 'X';
                                jumlahX--;
                                giliran--;
                            } else giliran++;
                        } break;
                        case 9:
                        {
                            if ((jumlahO!=0) && giliran%2 !=0 && isi9 ==' ') {
                                isi9 = 'O';
                                jumlahO--;
                                giliran--;
                            }
                            else if ((jumlahX!=0) && giliran%2 ==0 && isi9 ==' ') {
                                isi9 = 'X';
                                jumlahX--;
                                giliran--;
                            } else giliran++;
                        } break;
                    }
                } while (jumlahO > 0 || jumlahX>0);
                kotak = 0;
                cout << endl;
                for (int bawah=1; bawah <=7; bawah++) {
                    if (bawah%2 != 0) {
                        for (int kanan = 1; kanan <= 3; kanan++){
                            cout << "+-";
                        } cout << "+" << endl;
                    } else {
                        for (int kanan = 1; kanan <= 3; kanan ++){
                            kotak++;
                            cout << "|";
                            switch (kotak) {
                                case 1: cout << isi1;
                                        break;
                                case 2: cout << isi2;
                                        break;
                                case 3: cout << isi3;
                                        break;
                                case 4: cout << isi4;
                                        break;
                                case 5: cout << isi5;
                                        break;
                                case 6: cout << isi6;
                                        break;
                                case 7: cout << isi7;
                                        break;
                                case 8: cout << isi8;
                                        break;
                                case 9: cout << isi9;
                                        break;
                            }
                        } cout << "|" << endl;
                    }
                }

                if (isi1=='X'){
                    if ((isi1==isi2 && isi1==isi3) || (isi1==isi4 && isi1==isi7) || (isi1==isi5 && isi1==isi9))
                        hasil = "X menang";
                }
                if (isi5=='X') {
                    if ((isi2==isi5 && isi5==isi8) || (isi5==isi7 && isi5==isi3) || (isi4==isi5 && isi5==isi6))
                        hasil = "X menang";
                }
                if (isi9=='X') {
                    if ((isi3==isi9 && isi6==isi9) || (isi7==isi9 && isi8==isi9))
                        hasil = "X menang";
                }
                if (isi1=='O'){
                    if ((isi1==isi2 && isi1==isi3) || (isi1==isi4 && isi1==isi7) || (isi1==isi5 && isi1==isi9))
                        hasil = "O menang";
                }
                if (isi5=='O') {
                    if ((isi2==isi5 && isi5==isi8) || (isi5==isi7 && isi5==isi3) || (isi4==isi5 && isi5==isi6))
                        hasil = "O menang";
                }
                if (isi9=='O'){
                    if ((isi3==isi9 && isi6==isi9) || (isi7==isi9 && isi8==isi9))
                        hasil = "O menang";
                }
                cout << hasil;
            } break;

        case 3:
            {
                kotak = 0; hitung = 0;
                cout << "Panjang : ";
                cin >> panjang;
                cout << "Lebar   : ";
                cin >> lebar;

                bom1 = rand()%(panjang*lebar-1)+1;
                do {
                    bom2 = rand()%(panjang*lebar-1)+1;
                    bom3 = rand()%(panjang*lebar-1)+1;
                } while (bom1 == bom2 || bom3 == bom1 || bom1 == bom3 || bom2 == bom3);

                cout << endl; //cetak border atas
                for (int kanan = 1; kanan <= panjang; kanan++) {
                    cout << "+-";
                } cout << "+" << endl;
                for (int bawah = 1; bawah <= lebar*2; bawah++) {
                    if (bawah%2 != 0) { //baris ganjil -> isi
                        for (int kanan = 1; kanan <= panjang; kanan++) {
                            kotak++;
                            cout << "|";
                            hitung=0;
                            if (kotak == bom1 || kotak == bom2 || kotak == bom3) cout << "*";
                            else {   //kotak terhadap bom1
                                if (bom1%panjang == 0){ //bom diujung kanan, maka kotak setelahnya ada di baris bawahnya
                                    if (kotak+1 == bom1 || kotak+panjang+1 == bom1 || kotak+panjang == bom1 ||
                                        kotak-panjang == bom1 || kotak-panjang+1 == bom1)
                                        hitung++;
                                }
                                else if (bom1%panjang == 1){ //bom diujung kiri, kotak sebelumnya ada di baris atasnya
                                    if (kotak-panjang == bom1 || kotak-panjang-1 == bom1 || kotak+panjang == bom1 ||
                                        kotak+panjang-1 == bom1 || kotak-1 == bom1)
                                        hitung++;
                                }
                                else if (kotak-1 == bom1 || kotak+1 == bom1 || kotak-panjang == bom1 ||
                                           kotak+panjang == bom1 || kotak-panjang+1 == bom1 || kotak-panjang-1 == bom1 ||
                                           kotak+panjang+1 == bom1 || kotak+panjang-1 == bom1)
                                    hitung++;
                                //kotak terhadap bom2
                                if (bom2%panjang == 0){
                                    if (kotak+1 == bom2 || kotak+panjang+1 == bom2 || kotak+panjang == bom2 ||
                                        kotak-panjang == bom2 || kotak-panjang+1 == bom2)
                                        hitung++;
                                }
                                else if (bom2%panjang == 1){
                                    if (kotak-panjang == bom2 || kotak-panjang-1 == bom2 || kotak+panjang == bom2 ||
                                        kotak+panjang-1 == bom2 || kotak-1 == bom2)
                                        hitung++;
                                }
                                else if (kotak-1 == bom2 || kotak+1 == bom2 || kotak-panjang == bom2 ||
                                           kotak+panjang == bom2 || kotak-panjang+1 == bom2 || kotak-panjang-1 == bom2 ||
                                           kotak+panjang+1 == bom2 || kotak+panjang-1 == bom2)
                                    hitung++;
                                //kotak terhadap bom3
                                if (bom3%panjang == 0){
                                    if (kotak+1 == bom3 || kotak+panjang+1 == bom3 || kotak+panjang == bom3 ||
                                        kotak-panjang == bom3 || kotak-panjang+1 == bom3)
                                        hitung++;
                                }
                                else if (bom3%panjang == 1){
                                    if (kotak-panjang == bom3 || kotak-panjang-1 == bom3 || kotak+panjang == bom3 ||
                                        kotak+panjang-1 == bom3 || kotak-1 == bom3)
                                        hitung++;
                                }
                                else if (kotak-1 == bom3 || kotak+1 == bom3 || kotak-panjang == bom3 ||
                                           kotak+panjang == bom3 || kotak-panjang+1 == bom3 || kotak-panjang-1 == bom3 ||
                                           kotak+panjang+1 == bom3 || kotak+panjang-1 == bom3)
                                    hitung++;

                                if (hitung != 0) cout << hitung;
                                else cout << ' ';
                            }
                        } cout << "|" << endl;
                    }
                    else {//baris genap -> border dalam + tutup border bawah
                        for (int kanan = 1; kanan <= panjang; kanan++) {
                            cout << "+-";
                        } cout << "+" << endl;
                    }
                }
            } break;
    }

    return 0;
}
