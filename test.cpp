#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#define ll long long

using namespace std;

void cetak(ll arr[], int n){
    for (int i=0; i<n; ++i){
    printf("%lld ", arr[i]);
  }
  cout << endl;
}

int digitke (int berapa, int angkanya){
    if (floor(log10(angkanya)) < berapa){
        return 0;
    }
    else{
        berapa++;
        return (angkanya / (int)(pow(10,(berapa-1))+0.01) % 10);
    }
}

int main(){
    int n, digit;
  cin >> n;
  ll arr[n];
  for (int i=0; i<n; ++i){
    cin >> arr[i];
  }
  int maks = arr[0];
    for (int i=1; i<n; ++i){
        if (maks < arr[i])
            maks = arr[i];
    }
  digit = 0;
  cetak (arr, n);
  while (maks){
        maks /= 10;
        ++digit;
    }

    vector <int> temp;
    for (int i=0; i<digit; ++i){
        temp.clear();
        for (int sek=0; sek<10; ++sek){
            for (int j=0; j<n; ++j){
                if ( digitke(i, arr[j]) == sek ){
                    temp.push_back(arr[j]);
                    cout << arr[j] << ' ';
                }
            }
        }
        for (int j=0; j<temp.size(); ++j){
            arr[j] = temp[j];
        }
        cout << endl;
    }
  return 0;
}
