#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

// besar matriks
const int s=2;
void tampilkan(int matriks1[][s], int matriks2[][s]){
    cout << "Matriks 1" << endl;
    for (int j=0; j<s; ++j){
        for (int i=0; i<s; ++i){
            cout << matriks1[i][j] << ' ';
        }
        cout << "\n";
    }

    cout << "Matriks 2" << endl;
    for (int j=0; j<s; ++j){
        for (int i=0; i<s; ++i){
            cout << matriks2[i][j] << ' ';
        }
        cout << "\n";
    }
}

void isiMatriks(int matriks1[][s], int matriks2[][s]){
    char pil;
    cout << "Random isi matrix (0-9)? (Y/N)";
    cin >> pil;

    if (pil=='Y' || pil=='y'){
        for (int j=0; j<s; ++j){
            for (int i=0; i<s; ++i){
                matriks1[i][j]= rand()%10;
            }
        }

        for (int j=0; j<s; ++j){
            for (int i=0; i<s; ++i){
                matriks2[i][j]= rand() % 10;
            }
        }
    }
    else if (pil=='n' || pil=='N') {
        for (int j=0; j<s; ++j){
            for (int i=0; i<s; ++i){
                cout << "Matriks 1 (" <<i<< ", " <<j<< " ) : ";
                cin >> matriks1[i][j];
            }
        }

        for (int j=0; j<s; ++j){
            for (int i=0; i<s; ++i){
                cout << "Matriks 2 (" <<i<< ", " <<j<< " ) : ";
                cin >> matriks2[i][j];
            }
        }
    }
    tampilkan(matriks1, matriks2);
}

void jumlahMatriks(int mat1[][s], int mat2[][s], int hasil[][s]);
void kurangMatriks(int mat1[][s], int mat2[][s], int hasil[][s]);
void transpose (int mat1[][s], int mat2[][s]);
void kali(int mat1[][s], int mat2[][s], int hasil[][s]);

int main(){
    srand(time(0));
    int inp = 0;
    int hasil[s][s];
    int m1[s][s], m2[s][s];
    do{
        system("cls");
        cout << "0. Exit" << endl;
        cout << "1. Input Matriks" << endl;
        cout << "2. Penjumlahan Matriks" << endl;
        cout << "3. Pengurangan Matriks" << endl;
        cout << "4. Perkalian Matriks" << endl;
        cout << "5. Transpose" << endl;
        cout << "6. Tampilkan Matriks 1 dan 2" << endl;
        cin >> inp;
        if (inp == 1){
            isiMatriks(m1, m2);
            getch();
        }
        else if (inp == 2){
            jumlahMatriks (m1, m2, hasil);
            getch();
        }
        else if (inp == 3){
            kurangMatriks (m1, m2, hasil);
            getch();
        }
        else if (inp == 4){
            kali(m1, m2, hasil);
            getch();
        }
        else if (inp ==5){
            transpose (m1, m2);
            getch();
        }
        else if (inp == 6){
            tampilkan(m1, m2);
            getch();
        }
    }while (inp!=0);
    return 0;
}

void kali(int mat1[][s], int mat2[][s], int hasil[][s]){
    tampilkan(mat1, mat2);
	for(int i = 0; i < s; ++i)
	{
		for(int j = 0; j < s; ++j)
		{
			hasil[i][j] = 0;
		}
	}
	for(int i = 0; i<s; ++i) //baris matriks 1
	{
		for(int j = 0; j<s; ++j) //kolom matriks 2
		{
			for(int k=0; k<s; ++k) //kolom matriks 1
			{
				hasil[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	for(int i = 0; i < s; ++i)
	{
		for(int j = 0; j < s; ++j)
		{
			cout << hasil[i][j] << ' ';
		}
		cout << endl;
	}
}

void jumlahMatriks(int mat1[][s], int mat2[][s], int hasil[][s]){
    tampilkan(mat1, mat2);
    for (int j=0; j<s; ++j){
        for (int i = 0; i<s; ++i){
            hasil[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    cout << "Hasil : " << endl;
    for (int j=0; j<s; ++j){
        for (int i = 0; i<s; ++i){
            cout << hasil[i][j] << ' ';
        }
        cout << endl;
    }
}

void kurangMatriks(int mat1[][s], int mat2[][s], int hasil[][s]){
    tampilkan(mat1, mat2);
    for (int j=0; j<s; ++j){
        for (int i = 0; i<s; ++i){
            hasil[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    cout << "Hasil : " << endl;
    for (int j=0; j<s; ++j){
        for (int i = 0; i<s; ++i){
            cout << hasil[i][j] << ' ';
        }
        cout << endl;
    }
}

void transpose (int mat1[][s], int mat2[][s]){
    cout << "Befre : \n";
    tampilkan(mat1, mat2);

    cout << "After : \n";
    for (int j=0; j<s; ++j){
        for (int i=j; i<s; ++i){
            int temp1, temp2;
            temp1 = mat1[i][j];
            mat1[i][j] = mat1[j][i];
            mat1[j][i] = temp1;
            temp2 = mat2[i][j];
            mat2[i][j] = mat2[j][i];
            mat2[j][i] = temp2;
        }
    }

    tampilkan(mat1, mat2);

}

