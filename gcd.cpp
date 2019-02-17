#include <bits/stdc++.h>
#include <conio.h>

using std::cin;
using std::cout;
using std::endl;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int tescase;
    cin >> tescase;
    std::vector<int> ans;
    while(tescase--){
        int num1, num2;
        cin >> num1 >> num2;

        ans.push_back(gcd(num1, num2));
    }
    for(int i=0; i<ans.size(); ++i){
        cout << ans[i] << endl;
        if(i%1000==0)
            getch();
    }
}
