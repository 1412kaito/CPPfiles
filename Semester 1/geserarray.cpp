#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;
int n;
void cetak(int v[]);

int main(){

    cin >> n;
    int v[n], x[n];
    for (int i=0; i<n; ++i){
        cin >> v[i];
    }

    short geser, temp;

    cetak(v);
    do {
    cout << "\nInputan besar pergeseran array : ";
    cin >> geser;
    } while ((geser >= n && geser <=n  )|| geser==0);

    for(int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            if (j+geser < 0){
                if (j+geser+n == i){
                    x[i] = v[j];
                }
            }
            else if (j+geser >= n){
                if (j+geser-n == i){
                    x[i] = v[j];
                }
            }
            else if (j+geser == i){
                x[i] = v[j];
            }
        }
    }

    for(int i=0; i<n; ++i)
    {
        v[i] = x[i];
    }
    cetak(v);

    return 0;

}

void cetak(int v[]){
     for (int i=0; i<n; ++i){
        cout << v[i] << " ";
    }
}
