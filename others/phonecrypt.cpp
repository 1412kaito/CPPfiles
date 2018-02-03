#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int cipher[10];

int cekhuruf(char huruf, int &kali){
    if (huruf=='a'){
        kali = 1;
        return 2;
    }
    else if (huruf=='b'){
        kali = 2;
        return 2;
    }
    else if (huruf=='c'){
        kali = 3;
        return 2;
    }
    else if (huruf=='d'){
        kali = 1;
        return 3;
    }
    else if (huruf=='e'){
        kali = 2;
        return 3;
    }
    else if (huruf=='f'){
        kali = 3;
        return 3;
    }
    else if (huruf=='g'){
        kali = 1;
        return 4;
    }
    else if (huruf=='h'){
        kali = 2;
        return 4;
    }
    else if (huruf=='i'){
        kali = 3;
        return 4;
    }
    else if (huruf=='j'){
        kali = 1;
        return 5;
    }
    else if (huruf=='k'){
        kali = 2;
        return 5;
    }
    else if (huruf=='l'){
        kali = 3;
        return 5;
    }
    else if (huruf=='m'){
        kali = 1;
        return 6;
    }
    else if (huruf=='n'){
        kali = 2;
        return 6;
    }
    else if (huruf=='o'){
        kali = 3;
        return 6;
    }
    else if (huruf=='p'){
        kali = 1;
        return 7;
    }
    else if (huruf=='q'){
        kali = 2;
        return 7;
    }
    else if (huruf=='r'){
        kali = 3;
        return 7;
    }
    else if (huruf=='s'){
        kali = 4;
        return 7;
    }
    else if (huruf=='t'){
        kali = 1;
        return 8;
    }
    else if (huruf=='u'){
        kali = 2;
        return 8;
    }
    else if (huruf=='v'){
        kali = 3;
        return 8;
    }
    else if (huruf=='w'){
        kali = 1;
        return 9;
    }
    else if (huruf=='x'){
        kali = 2;
        return 9;
    }
    else if (huruf=='y'){
        kali = 3;
        return 9;
    }
    else if (huruf=='z'){
        kali = 4;
        return 9;
    }
}

int cari(int isi){
    for (int i=1; i<=9; ++i){
        if (isi == cipher[i]){
            return i;
        }
    }
}

int main(){

    string word, output;
    int times, what, previous;
    output = "";
    for (int i=1; i<=9; ++i){
        cin >> cipher[i];
    }

    cin >> word;
    previous = 0;
    for (int i=0; i<word.size(); ++i){
        what = cekhuruf(word[i], times);
        what = cari(what);
        if (previous == what){
            cout << "#";
        }
        for (int i=0; i<times; ++i){
            cout << what;
        }
        previous = what;
    }

    return 0;
}
