#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;

int minuman[3][4], pos;

void cetakpapan(int human); //mencetak papan informasi berisikan gelas para pemain

void rotasiGelas(int arah){ //rotasi gelas semua pemain
    int temp;
    if (arah == 1){
        for (int i=0; i<3; ++i){
            temp = minuman[i][0];
            minuman[i][0] = minuman[i][3];
            minuman[i][3] = minuman[i][2];
            minuman[i][2] = minuman[i][1];
            minuman[i][1] = temp;
        }
    }
    else if (arah == 2){
        for (int i=0; i<3; ++i){
            temp = minuman[i][0];
            minuman[i][0] = minuman[i][1];
            minuman[i][1] = minuman[i][2];
            minuman[i][2] = minuman[i][3];
            minuman[i][3] = temp;
        }
    }
    else
        cout << "Indeks arah yang Anda inputkan salah" << endl;
}

void tambahMinuman(int target, int indeksMinuman=0, int pelaku=pos){ //tambah wine, tambah racun, tambah antidote, tukar gelas
    if (indeksMinuman < 4)
        ++minuman[indeksMinuman-1][target-1];
    else if (indeksMinuman == 4){
        int temp;
        for (int i=0; i<3; ++i){
            temp = minuman[i][pelaku-1];
            minuman[i][pelaku-1] = minuman[i][target-1];
            minuman[i][target-1] = temp;
        }
    }
    else
    {
        rotasiGelas(target);
    }
}

void random_DUMB (int giliran){ //pemilihan aksi DUMB AI
    int menu, choice;
    for (int i=0; i<2; ++i){
        system("cls");
        cetakpapan(pos);
        cout << "Giliran Player " << giliran << " <Dumb AI>" << endl;
        cout << "1. Tambah wine" << endl;
        cout << "2. Tambah racun" << endl;
        cout << "3. Tambah antidote" << endl;
        cout << "4. Tukar gelas" << endl;
        cout << "5. Putar gelas" << endl;
        getch();
        menu = rand()%4+1;
        switch (menu){
            case 1  :
            {
                cout << "Player " << giliran << " <Dumb AI> akan menambahkan wine" << endl;
                cout << "Pada gelas player ke : ";
                choice = rand()%4+1;
                cout << choice;
                tambahMinuman(choice, menu, giliran);
           }   break;
            case 2  :
            {
                cout << "Player " << giliran << " <Dumb AI> akan menambahkan racun" << endl;
                cout << "Pada gelas player ke : ";
                choice = rand()%4+1;
                cout << choice;
                tambahMinuman(choice, menu, giliran);
            }   break;
            case 3  :
            {
                cout << "Player " << giliran << " <Dumb AI> akan menambahkan antidote" << endl;
                cout << "Pada gelas player ke : ";
                choice = rand()%4+1;
                cout << choice;
                tambahMinuman(choice, menu, giliran);
            }   break;
            case 4  :
            {
                cout << "Player " << giliran << " <Dumb AI> akan menukar gelas miliknya ";
                cout << "dengan gelas player ke : ";
                choice = rand()%4+1;
                cout << choice;
                tambahMinuman(choice, menu, giliran);
            }   break;
            case 5  :
            {
                cout << "Player " << giliran << " <Dumb AI> akan merotasi gelas semua player" << endl;
                cout << "Arah : " << endl;
                choice = rand()%2+1;
                if (choice == 1)
                    cout << "1. Searah jarum jam" << endl;
                else
                    cout << "2. Berlawanan arah jarum jam" << endl;
                tambahMinuman(choice, menu, giliran);
            }   break;
        }
        cout << endl;
        getch();
    }
}

bool pengecekanRacun_smart(int giliran, int putaranKe){
    if ((minuman[1][giliran] - minuman[2][giliran]==2 && putaranKe==0) || minuman[1][giliran] - minuman[2][giliran]==1)
        return true;
    else
        return false;
}

void random_SMART(int giliran){ //SMART AI
    int menu, choice;
    menu = 0;
    for (int i=0; i<2; ++i){
        system("cls");
        cetakpapan(pos);
        cout << "Giliran Player " << giliran << " <SMART AI>" << endl;
        cout << "1. Tambah wine" << endl;
        cout << "2. Tambah racun" << endl;
        cout << "3. Tambah antidote" << endl;
        cout << "4. Tukar gelas" << endl;
        cout << "5. Putar gelas" << endl;
        getch();
        int wineTerbanyak=1, indeks=giliran;
        for (int j=0; j<4; ++j){
            if (minuman[0][j] > wineTerbanyak){
                wineTerbanyak = minuman[0][j];
                indeks = j+1;
            }
        }
        if ( (indeks != giliran) && menu!=4){
            menu = 4;
            choice = indeks;
        }
        else if ( pengecekanRacun_smart(giliran, i) && menu!=3){
            menu = 3;
            choice = giliran;
        }
        else if ( (minuman[1][giliran]+1 > minuman[2][giliran]) && menu != 2){
            menu = 2;
            choice = (giliran-1+1)%4+1;
        }
        else {
            menu = rand()%4+1;
            if (menu == 5)
                choice=rand()%2+1;
            else if (menu != 4 && menu != 2)
                choice = rand()%4+1;
            else if (menu == 4){
                do{
                    choice=rand()%4+1;
                }while (choice == giliran+1 || choice == giliran);
            }
            else if (menu == 2){
                do{
                    choice=rand()%4+1;
                }while (choice == giliran);
            }
        }
        switch (menu){
            case 1  :
            {
                cout << "Player " << giliran << " <Smart AI> akan menambahkan wine" << endl;
                cout << "Pada gelas player ke : ";
                cout << choice;
                tambahMinuman(choice, menu, giliran);
           }   break;
            case 2  :
            {
                cout << "Player " << giliran << " <Smart AI> akan menambahkan racun" << endl;
                cout << "Pada gelas player ke : ";
                cout << choice;
                tambahMinuman(choice, menu, giliran);
            }   break;
            case 3  :
            {
                cout << "Player " << giliran << " <Smart AI> akan menambahkan antidote" << endl;
                cout << "Pada gelas player ke : ";
                cout << choice;
                tambahMinuman(choice, menu, giliran);
            }   break;
            case 4  :
            {
                cout << "Player " << giliran << " <Smart AI> akan menukar gelas miliknya ";
                cout << "dengan gelas player ke : ";
                cout << choice;
                tambahMinuman(choice, menu, giliran);
            }   break;
            case 5  :
            {
                cout << "Player " << giliran << " <Smart AI> akan merotasi gelas semua player" << endl;
                cout << "Arah : " << endl;
                if (choice == 1)
                    cout << "1. Searah jarum jam" << endl;
                else
                    cout << "2. Berlawanan arah jarum jam" << endl;
                tambahMinuman(choice, menu, giliran);
            }   break;
        }
        cout << endl;
        getch();
    }
}

void menuAksi(); // berisikan pilihan aksi yang dapat dilakukan oleh player

int main(){
    // inisialisasi minuman
    srand(time(0));
    short indeks_mostWine;
    int mostWine=1;
    int ctr=3, giliran;
    char status[4] = {'H', 'H', 'H', 'H'};
    int poin[4] = {0, 0, 0, 0};
    for (int i=1; i<3; ++i){
        for (int j=0; j<4; ++j){
            minuman[0][j] = 1;
            minuman[i][j] = 0;
        }
    }

    cout << "Pilih posisi anda (1/2/3/4) : ";
    cin >> pos;
    system("cls");

    do {
        cetakpapan(pos);
        giliran = 1;
        for (int i=1; i<=4; ++i){
            if (pos == giliran){
                menuAksi();
            }
            else if (giliran == (pos)%4+1 || giliran == (pos+2)%4+1){
                random_DUMB(giliran);
            }
            else {
                cout << "Player " << giliran << " <Smart AI>" << endl;
                random_SMART(giliran);
            }
            ++giliran;
        }
        system("cls");
        ctr--;
    } while (ctr != 0);

    cetakpapan(pos);

    //pengecekan

    for (int i=0; i<4; ++i){
        if (minuman[0][i] >= mostWine){
            mostWine = minuman[0][i];
            indeks_mostWine = i;
        }
        if (minuman[1][i] > minuman[2][i])
            status[i] = 'M';
    }
    for (int i=0; i<4; ++i){
        if (status[i]=='H'){
            ++poin[i];
            if (status[(i+1)%4]=='M')
                ++poin[i];
        }
        if (status[(i+1)%4]=='M')
            ++poin[i];
        }

    ++poin[indeks_mostWine];


    for (int i=0; i<4; ++i){
        cout << "Poin player " << i+1 << " : " << poin[i] << endl;
    }
    getch();
    return 0;
}

void cetakpapan(int human){ //mencetak papan informasi berisikan gelas para pemain
    string tutup = "+==============+";
    string status[4] = {"|     HUMAN    |", "|    DUMB AI   |", "|   SMART AI   |", "|    DUMB AI   |" };
    string player[4] = {"|   Player 1   |", "|   Player 2   |", "|   Player 3   |", "|   Player 4   |"};
    string gelas[3] = { "| Wine    : ", "| Racun   : ", "| Antidote: " };

    int now;
    cout << tutup << ' ' << tutup << endl;
    now = 1;
    cout << status[abs(human-now)] << ' ';
    now = 2;
    cout << status[abs(human-now)] << ' ' << endl;
    cout << player[0] << ' ' << player[1] << endl;

    for (int i=0; i<3; ++i){
        now=0;
        cout << gelas[i] ;
        if (minuman[now][i]<10)
            cout << "0" << minuman[i][now];
        else
            cout << minuman[i][now];
        cout << " |" << ' ';
        ++now;
        cout << gelas[i] ;
        if (minuman[now][i]<10)
            cout << "0" << minuman[i][now];
        else
            cout << minuman[i][now];
        cout << " |" << endl;
    }
    cout << tutup << ' ' << tutup << endl;

    cout << tutup << ' ' << tutup << endl;
    now = 4;
    cout << status[abs(human-now)] << ' ';
    now = 3;
    cout << status[abs(human-now)] << ' ' << endl;
    cout << player[3] << ' ' << player[2] << endl;
    for (int i=0; i<3; ++i){
        now=3;
        cout << gelas[i] ;
        if (minuman[now][i]<10)
            cout << "0" << minuman[i][now];
        else
            cout << minuman[i][now];
        cout << " |" << ' ';
        --now;
        cout << gelas[i] ;
        if (minuman[now][i]<10)
            cout << "0" << minuman[i][now];
        else
            cout << minuman[i][now];
        cout << " |" << endl;
    }
    cout << tutup << ' ' << tutup << endl;
}

void menuAksi(){ // berisikan pilihan aksi yang dapat dilakukan oleh player
    int menu, choice;
    for (int i=0; i<2; ++i){
        system("cls");
        cetakpapan(pos);
        cout << "Giliran player " << pos << endl;
        cout << "Menu" << endl;
        cout << "1. Tambah wine" << endl;
        cout << "2. Tambah racun" << endl;
        cout << "3. Tambah antidote" << endl;
        cout << "4. Tukar gelas" << endl;
        cout << "5. Putar gelas";
        cout << endl << "Pilihan >>";
        cin >> menu;
        switch (menu){
            case 1  :
            {
                cout << "Anda akan menambahkan wine" << endl;
                cout << "Pada gelas player ke : ";
                cin >> choice;
                tambahMinuman(choice, menu, pos);
           }   break;
            case 2  :
            {
                cout << "Anda akan menambahkan racun" << endl;
                cout << "Pada gelas player ke : ";
                cin >> choice;
                tambahMinuman(choice, menu, pos);
            }   break;
            case 3  :
            {
                cout << "Anda akan menambahkan antidote" << endl;
                cout << "Pada gelas player ke : ";
                cin >> choice;
                tambahMinuman(choice, menu, pos);
            }   break;
            case 4  :
            {
                cout << "Anda akan menukar gelas anda ";
                cout << "dengan gelas player ke : " << endl;
                cin >> choice;
                tambahMinuman(choice, menu, pos);
            }   break;
            case 5  :
            {
                cout << "Anda akan merotasi gelas semua player" << endl;
                cout << "Arah : " << endl;
                cout << "1. Searah jarum jam" << endl;
                cout << "2. Berlawanan arah jarum jam" << endl;
                cin >> choice;
                tambahMinuman(choice, menu, pos);
            }   break;
            default :
                cout << "Inputan Anda salah" << endl;
                break;
        }
    }
    system("cls");
    cetakpapan(pos);
}

