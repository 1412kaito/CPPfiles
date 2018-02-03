#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(0));
    int panjang, lebar, posx, posy, kotak;
    int maks, kotakp, musuh1, musuh2, musuh3, musuh4, musuh5;
    int disX1, disX2, disX3, disX4, disX5, disY1, disY2, disY3, disY4, disY5;
    char moves;
    bool m1=1, m2=1, m3=1, m4=1, m5=1, kondisi = 1; //0 kalah 1 menang

    cout << "Masukkan panjang  : ";
    cin >> panjang;
    cout << "Masukkan lebar    : ";
    cin >> lebar;
    cout << "Masukkan x player : ";
    cin >> posx;
    cout << "Masukkan y player : ";
    cin >> posy;

    maks = panjang * lebar;
    kotakp = posx + (10*posy);

    musuh1 = rand()%(maks);
    do
    {
        musuh2 = rand()%(maks);
        musuh3 = rand()%(maks);
        musuh4 = rand()%(maks);
        musuh5 = rand()%(maks);
    } while ( (musuh1==musuh2) || (musuh1==musuh3) || (musuh1==musuh4) || (musuh1==musuh5) || (musuh2==musuh3)
            ||(musuh2==musuh4) || (musuh2==musuh5) || (musuh3==musuh5) || (musuh3==musuh4) || (musuh4==musuh5)
            ||(musuh1==kotakp) || (musuh2==kotakp) || (musuh3==kotakp) || (musuh4==kotakp) || (musuh5==kotakp) );



    while (kondisi!=0)
    {
        system("CLS");
        kotak = 0;
        for (int kolom=1; kolom<=panjang+2; kolom++) //atap
        {
            cout << "#";
        } cout << endl;
        for (int baris = 0; baris<lebar; baris ++) //arena
        {
            cout << "#";
            for (int kolom=0; kolom<panjang; kolom++)
            {
                if (kotakp == kotak)
                {
                    if (kotakp!= musuh1 && kotakp != musuh2 && kotakp!= musuh3 && kotakp != musuh4 && kotakp != musuh5) {}
                    else if (kotakp == musuh1 && m1 == 1) kondisi = 0;
                    else if (kotakp == musuh2 && m2 == 1) kondisi = 0;
                    else if (kotakp == musuh3 && m3 == 1) kondisi = 0;
                    else if (kotakp == musuh4 && m4 == 1) kondisi = 0;
                    else if (kotakp == musuh5 && m5 == 1) kondisi = 0;
                    cout << "P";
                }
                else if (kotak==musuh1 || kotak==musuh2 || kotak==musuh3 || kotak==musuh4 || kotak==musuh5)
                {
                    if (kotak==musuh1) {
                        if (musuh1 == musuh2 || musuh1 == musuh3 || musuh1 == musuh4 || musuh1 == musuh5 )
                            cout << "*";
                        else
                            cout << "@";
                    }
                    else if (kotak==musuh2) {
                        if (musuh2 == musuh3 || musuh2 == musuh4 || musuh2 == musuh4)
                            cout << "*";
                        else
                            cout << "@";
                    }
                    else if (kotak==musuh3) {
                        if (musuh3 == musuh4 || musuh3 == musuh5)
                            cout << "*";
                        else
                            cout << "@";
                    }
                    else if (kotak==musuh4){
                        if (musuh4 == musuh5)
                            cout << "*";
                        else
                            cout << "@";
                    }
                    else if (kotak==musuh5) cout << "@";
                }
                else cout << " ";
                kotak++;
            } cout << "#" << endl;
        }
        for (int kolom=1; kolom<=panjang+2; kolom++) //lantai?
        {
            cout << "#";
        } cout << endl;
        //jarak horisontal player dan musuh
        disX1 = (musuh1%panjang - kotakp%panjang) * m1;
        disX2 = (musuh2%panjang - kotakp%panjang) * m2;
        disX3 = (musuh3%panjang - kotakp%panjang) * m3;
        disX4 = (musuh4%panjang - kotakp%panjang) * m4;
        disX5 = (musuh5%panjang - kotakp%panjang) * m5;
        //jarak vertikal player dan musuh
        disY1 = (musuh1/panjang - kotakp/panjang) * m1;
        disY2 = (musuh2/panjang - kotakp/panjang) * m2;
        disY3 = (musuh3/panjang - kotakp/panjang) * m3;
        disY4 = (musuh4/panjang - kotakp/panjang) * m4;
        disY5 = (musuh5/panjang - kotakp/panjang) * m5;

        cout << "Input : ";
        moves = getch();
        if (moves == ' ')
        { //tele
            do{
                kotakp = rand()%(maks);
            } while ((musuh1==kotakp) || (musuh2==kotakp) || (musuh3==kotakp) ||
                     (musuh4==kotakp) || (musuh5==kotakp) );
        }
        else
        { //gerak player fix
            if (moves == 'q'){ //naik 1, kiri 1
                if (kotakp > panjang)
                    kotakp -= (panjang+1);
            }
            if (moves == 'w'){ //naik 1
                if (kotakp > panjang)
                    kotakp -= panjang;
            }
            if (moves == 'e'){ //naik 1, kanan 1
                if (kotakp > panjang)
                    kotakp -= (panjang-1);
            }
            if (moves == 'a'){ //kiri
                if (kotakp%panjang !=0)
                    kotakp -= 1;
            }
            if (moves == 's'){ //stay
                kotakp -= 0;
            }
            if (moves == 'd'){ //kanan
                if ((kotakp+1)%panjang !=0)
                    kotakp += 1;
            }
            if (moves == 'z'){ //bawah kiri
                if (kotakp < panjang*(lebar-1))
                    kotakp += (panjang-1);
            }
            if (moves == 'x'){ //bawah
                if (kotakp < panjang*(lebar-1))
                    kotakp += panjang;
            }
            if (moves == 'c'){ //bawah kanan
                if (kotakp < panjang*(lebar-1))
                    kotakp += (panjang+1);
            }

            //gerak musuh terhadap posisi player sebelum bergerak
            if (disX1 > 0) musuh1--;
            else if (disX1 < 0) musuh1++;
            if (disY1 > 0) musuh1-=panjang;
            else if (disY1<0) musuh1+=panjang;

            if (disX2 > 0) musuh2--;
            else if (disX2 < 0) musuh2++;
            if (disY2 > 0) musuh2-=panjang;
            else if (disY2<0) musuh2+=panjang;

            if (disX3 > 0) musuh3--;
            else if (disX3 < 0) musuh3++;
            if (disY3 > 0) musuh3-=panjang;
            else if (disY3<0) musuh3+=panjang;

            if (disX4 > 0) musuh4--;
            else if (disX4 < 0) musuh4++;
            if (disY4 > 0) musuh4-=panjang;
            else if (disY4<0) musuh4+=panjang;

            if (disX5 > 0) musuh5--;
            else if (disX5< 0) musuh5++;
            if (disY5 > 0) musuh5-=panjang;
            else if (disY5<0) musuh5+=panjang;

            if (musuh1 == musuh2){
                m1=0;
                m2=0;
            }
            if (musuh1 == musuh3){
                m1=0;
                m3=0;
            }
            if (musuh1 == musuh4){
                m1=0;
                m4=0;
            }
            if (musuh1 == musuh5){
                m1=0;
                m5=0;
            }
            if (musuh3 == musuh2){
                m3=0;
                m2=0;
            }
            if (musuh4 == musuh2){
                m4=0;
                m2=0;
            }
            if (musuh3 == musuh4){
                m3=0;
                m4=0;
            }
            if (musuh3 == musuh5){
                m3=0;
                m5=0;
            }
            if (musuh4 == musuh5){
                m4=0;
                m5=0;
            }
            if (musuh2 == musuh5){
                m5=0;
                m2=0;
            }
        }

        system("CLS");
    }

    cout << "Game OVER";

    return 0;
}
