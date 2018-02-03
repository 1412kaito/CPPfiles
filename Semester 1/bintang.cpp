#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int a1=1; a1<=n ; a1++){
        for (int a2=1; a2 <= n ; a2++){
            if (a1==1 || a1==n || a2==1 || a2==n){
            cout << "*";}
            else { cout << " ";}
        }   cout << endl;
    }
    return 0;
}

    *
   ***
  *****
 *******
*********
*       *
*       *
*       *
*********
