#include <iostream>

using namespace std;

int main(){
    int arr[10] = {15, 31, 23, 15, 75, 23, 41, 15, 31, 85};
    int baru[10], ctr=0;
    bool unik = true;

    for (int i=0; i<10; ++i){
        unik = true;
        for (int j=0; j<10; ++j){
            if (arr [i] == baru[j]){
                unik = false;
            }
        }
        if (unik){
            baru[ctr] = arr[i];
            ++ctr;
        }
    }

    for (int i=0; i<ctr; ++i){
        arr[i] = baru[i];
        cout << arr[i] << " ";
    }
    return 0;
}
