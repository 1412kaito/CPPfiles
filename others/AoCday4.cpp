#include <fstream>
#include <conio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<string> dalambaris;

bool lakukanpengecekan (){
    for (int i=0; i<dalambaris.size(); ++i){
        for (int j=0; j<i;++j){
            if (dalambaris[j]==dalambaris[i]){
                return true;
            }
        }
    }
    return false;
}

bool charwisechecking (int line){
    cout << "Masuk charwise checks, line ke : " << line << ' ';
    int hitung;
    int ctr;
    for (int i=0; i<dalambaris.size(); ++i){
        for (int j=i+1; j<dalambaris.size();++j){
            if (dalambaris[i].size() == dalambaris[j].size()){
                ctr = dalambaris[i].size();
                hitung = 0;
                for (int k=0; k<dalambaris[i].size(); ++k){
                    for (int second=0; second<dalambaris[j].size(); ++second){
                        if (dalambaris[i][k] == dalambaris[j][second]){
                            cout << dalambaris[i][k];
                            ++hitung;
                            break;
                        }
                    }
                }
                cout << hitung << ' ' << ctr << endl;
                if (hitung ==  ctr){
                    cout << "invalid" << endl;
                    return false;
                }
            }
        }
    }
    cout << "valid" << endl;
    return true;
}
int main(){
    ifstream file ("day4.txt");
    int counter = 0;
    int line =0;
    if (file.is_open()){
        string temp;
        while (!file.eof()){
            ++line;
            dalambaris.clear();
            getline(file, temp);
            while (temp.find(" ")!=-1){
                dalambaris.push_back(temp.substr(0, temp.find(" ")));
                temp = temp.substr(temp.find(" ")+1);
            }
            dalambaris.push_back(temp);
            if (!lakukanpengecekan()){
                if (charwisechecking(line)){
                    ++counter;
                }
                cout << line << ' ';
                for (int i=0; i<dalambaris.size(); ++i){
                    cout << dalambaris[i] << ' ';
                }
                cout << endl;
            }
            else {
                cout << "KEMBAR >> ";
                cout << line << ' ';
                for (int i=0; i<dalambaris.size(); ++i){
                    cout << dalambaris[i] << ' ';
                }
                cout << endl;
            }
        }
        cout << endl;
        file.close();
    }
    cout << counter;
}
