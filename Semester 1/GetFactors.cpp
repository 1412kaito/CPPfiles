#include <vector>
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

void GetFactors(int x, int f[], int &n){
    int ctr = 0;
    for (int i=1; i<x; ++i){
        if (x%i == 0){
            f[ctr]=i;
            ++ctr;
        }
    }
    n = ctr;
}

double sum (int v[], int n){
    int acc;
    acc = v[0];
    for (int i=1; i<n; i++){
        acc = v[i] + acc;
    }
    return acc;
}

int main()
{
    int banyak_i, banyak_j;
    double sum_i, sum_j;
    int fak_i[1000], fak_j[1000];

    for (int i=1; i<100000; ++i){
        GetFactors(i, fak_i, banyak_i);
        sum_i = sum(fak_i, banyak_i);
        for (int j=1; j<100000; ++j){
            GetFactors(j, fak_j, banyak_j);
            sum_j = sum(fak_j, banyak_j);
            if (i==sum_j && j==sum_i){
                cout << i << " dan " << j << endl;
            }
        }
        cout << '.';
    }


    return 0;
}
