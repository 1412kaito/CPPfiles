#include <iostream>
#include <string>

using namespace std;

int main(){
    string input, salah, replacement, hasil="";
    int p_salah, indeks;
    cout << "Inputkan kalimat yang akan diubah : " << endl;
    getline(cin, input);

    cout << "Inputkan kata yang akan diganti : "<< endl;
    getline(cin, salah);

    cout << "Inputkan kata yang akan menggantikan kata \""<< salah << "\" : " << endl;
    getline(cin, replacement);

    while (input.length() > salah.length()&& (input.find(salah)!=-1))
    {
        indeks = input.find(salah);
        hasil += input.substr(0,indeks);
        input = input.substr(indeks+salah.length());
        hasil += replacement;
        if (input.find(salah)==-1)
        hasil+=input;
    }

    cout << endl << "=========="  << endl ;
    cout << hasil << endl;

    return 0;
}
