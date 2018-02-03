#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Masukkan nilai n : ";
    cin >> n;
    int counter=1, output=0;
    cout << output << " ";
    while (counter<n){

        output+=counter;
        cout << output << " ";
        counter+=1;}
    return 0;
}
