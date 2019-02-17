#include <bits/stdc++.h>

using namespace std;

unsigned long long int compute(int n) {
	if(n==0) return 0;
	unsigned long long int k = (n+1)/2;
	return k*k + compute(n/2);
}

int main(){
    int t;
    cin >> t;
    vector<unsigned long long int> answer;
    vector<unsigned long long int> sums;
    while (t--){
        int n;
        cin >> n;
        int hasil = n;
        while(hasil %2==0){
            hasil /=2;
        }
        answer.push_back(hasil);
        sums.push_back(compute(n));
    }
    for (int i=0; i<answer.size(); ++i){
        cout << answer[i] << " " << sums[i] << endl;
    }
	return 0;
}
