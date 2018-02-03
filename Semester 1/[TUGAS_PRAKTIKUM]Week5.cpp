#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int main()
{
    short x, y, menu1, menu2;
    short mainmenu=0, ctrlampu=0, ctrsumber=0;
    int indeks[22][12];
    char board[22][12];
    for (int a=0; a<=21; ++a){
        for (int b=0; b<=11; ++b){
            board[a][b] = ' ';
            indeks[a][b] = 0;
        }
    }

    do{
        system("cls");

        for (int r=1; r<=22; ++r){
            cout << "#";
        }
        cout << endl;
        for (int d=1; d<=10; ++d){
            cout << "#";
            for (int r=1; r<=20; ++r){
                cout << board[r][d];
            }
            cout << "#\n";
        }
        for (int r=1; r<=22; ++r){
            cout << "#";
        }
        cout << endl;
        cout << "Info : kotak kiri atas koordinat (1,1)\n";

        cout << "Menu :\n";
        cout << "1. Letakkan Objek\n";
        cout << "2. Hapus Objek\n";
        cout << "3. Tembakkan laser!\n";
        cout << "4. Reset\n";
        cout << ">>> ";
        cin >> mainmenu;

        switch (mainmenu){
            case 1: {
                cout << "Pilihan Objek :\n";
                cout << "1. O (Penerima laser)\n";
                cout << "2. > (Sumber Laser)\n";
                cout << "3. / (Cermin)\n";
                cout << "4. \\ (Cermin)\n";
                cout << ">>> ";
                cin >> menu1;
                cout << "Inputkan koordinat dimana obyek akan diletakkan : \n";
                cout << "(x dan y, pisahkan menggunakan spasi)\n";
                cin >> x >> y;
                while (x>20 || y>10 || x<1 || y<1){
                    if (x>20||x<1) cout << "Indeks posisi X anda salah!\n";
                    if (y>10||y<1) cout << "Indeks posisi Y anda salah!\n";
                    cout << "Inputkan koordinat dimana obyek akan diletakkan : \n";
                    cout << "(x dan y, pisahkan menggunakan spasi)\n";
                    cin >> x >> y;
                }
                if (board[x][y] != ' '){
                    cout << "Petak telah terisi!";
                    getch();
                }
                else {
                    switch(menu1){
                    case 1:
                        board[x][y] = 'O';
                        break;
                    case 2:
                        board[x][y] = '>';
                        break;
                    case 3:
                        board[x][y] = '/';
                        break;
                    case 4:
                        board[x][y] = '\\';
                        break;
                    }
                }
            }
                break;

            case 2:{
                cout << "Inputkan koordinat dimana obyek akan dihapus : \n";
                cout << "(x dan y, pisahkan menggunakan spasi)\n";
                cin >> x >> y;
                while (x>20 || y>10 || x<1 || y<1){
                    if (x>20||x<1) cout << "Indeks posisi X anda salah!\n";
                    if (y>10||y<1) cout << "Indeks posisi Y anda salah!\n";
                    cout << "Inputkan koordinat dimana obyek akan dihapus : \n";
                    cout << "(x dan y, pisahkan menggunakan spasi)\n";
                    cin >> x >> y;
                }
                if (board[x][y] != ' ')
                    board[x][y] = ' ';
                else
                    cout << "Petak telah kosong!";
                getch();
            }
                break;

            case 3:{
                for (int d=1; d<=10; ++d){
                    for (int r=1; r<=20; ++r){
                        if (board[r][d] == 'O'){
                            ++ctrlampu;
                        }
                        if (board[r][d] == '>'){
                            ++ctrsumber;
                            indeks[r][d]=2;
                        }
                    }
                }
                if (ctrlampu != 0 && ctrsumber !=0){
                    int times = 200;
                    do {
                        // 2 kanan 3 bawah 1 atas 4 kiri
                        for (int d=1; d<=10; ++d){
                            for (int r=1; r<=20; ++r){
                                if (indeks[r-1][d]==2 && board[r-1][d]=='>'){
                                    if (board[r][d]==' '){
                                        board[r][d] = '*';
                                        indeks[r][d] = 2;
                                    }
                                    else if (board[r][d] == '\\')
                                        indeks[r][d] == 3;
                                    else if (board[r][d] == '/')
                                        indeks[r][d] == 1;
                                    if (board[r][d] == 'O')
                                        board[r][d] = '@';
                                }

                                for (int j=d; j>0; --j){
                                    if (indeks[r][j]==1){
                                        if (board[r][j-1]==' ') {
                                            board[r][j-1]= '*';
                                            indeks[r][j-1]=1;
                                        }
                                    if (board[r][j-1]=='O')
                                        board[r][j-1]= '@';
                                    if (board[r][j-1]=='\\')
                                        indeks[r][j-1]=4;
                                    if (board[r][j-1]=='/')
                                        indeks[r][j-1]=2;
                                    if (board[r][j-1]=='*') {
                                            indeks[r][j-1]=1;
                                            if (board[r][j-2]==' '){
                                                indeks[r][j-2]=1;
                                                board[r][j-2]='*';
                                            }
                                        }
                                    }
                                }

                                if (indeks[r-1][d]==2){
                                    if (board[r][d]==' ') {
                                        board[r][d]= '*';
                                        indeks[r][d] = 2;
                                    }
                                    if (board[r][d]=='O')
                                        board[r][d]= '@';
                                    if (board[r][d]=='\\')
                                        indeks[r][d]=3;
                                    if (board[r][d]=='/')
                                        indeks[r][d]=1;
                                    if (board[r][d]=='*') {
                                        indeks[r][d]=2;
                                        if (board[r+1][d]==' '){
                                            indeks[r+1][d]=2;
                                            board[r+1][d]='*';
                                        }
                                    }
                                }

                                if (indeks[r][d-1]==3){
                                    if (board[r][d]==' ') {
                                        board[r][d]= '*';
                                        indeks[r][d]=3;
                                    }
                                    if (board[r][d]=='O')
                                        board[r][d]= '@';
                                    if (board[r][d]=='\\')
                                        indeks[r][d]=2;
                                    if (board[r][d]=='/')
                                        indeks[r][d]=4;
                                    if (board[r][d]=='*') {
                                        indeks[r][d]=3;
                                        if (board[r][d+1]==' '){
                                            indeks[r][d+1]=3;
                                            board[r][d+1]='*';
                                        }
                                    }
                                }

                                for (int i=r; i>0; --i){
                                    if (indeks[i][d]==4){
                                        if(board[i-1][d]==' '){
                                            board[i-1][d]='*';
                                            indeks[i-1][d]=4;
                                        }
                                        if (board[i-1][d]=='O')
                                            board[i-1][d]= '@';
                                        if (board[i-1][d]=='\\')
                                            indeks[i-1][d]=1;
                                        if (board[i-1][d]=='/')
                                            indeks[i-1][d]=3;
                                        if (board[i-1][d]=='*') {
                                            indeks[i-1][d]=4;
                                            if (board[i-2][d]==' '){
                                                indeks[i-2][d]=4;
                                                board[i-2][d]='*';
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        --times;
                    } while (times>0);
                }
                else {
                    if (ctrsumber == 0)
                        cout << "Error! Tidak ada sumber laser pada papan\n";
                    if (ctrlampu == 0)
                        cout << "Error! Tidak ada penerima laser pada papan\n";
                    getch();
                }
                break;
            }
            case 4:
                //reset
                for (int a=0; a<=20; ++a){
                    for (int b=0; b<=10; ++b){
                        board[a][b] = ' ';
                        indeks[a][b] = 0;
                    }
                }
                break;
        }
    } while (true);
    return 0;
}
