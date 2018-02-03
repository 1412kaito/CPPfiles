#include <iostream>
#include <vector>
using namespace std;

struct koords{
    int x;
    int y;
};
vector<koords> b;

bool samadenganb(int x, int y){
    for (int i=0; i<b.size(); ++i){
        if (b[i].x == x){
            if (b[i].y == y){
                return true;
            }
        }
    }
}

int main(){
    int inputan;
    koords B;
    B.x = 1;
    B.y = 0;

    koords temp_b;
    vector<int> commands;
    do {
        cin >> inputan;
        commands.push_back(inputan);
    } while (inputan !=0);

    for (int i=0; i<commands.size(); ++i){
        if (commands[i] == 4){
            commands[i] = 5;
            int j=i-1;
            if (commands[j] !=5){
                commands[j] = 5;
            }
            else {
                bool flag = true;
                while (flag && j>0){
                    --j;
                    if (commands[j]!=5){
                        commands[j]=5;
                        flag = false;
                    }
                }
            }
        }
    }

    for (int i=0; i<commands.size(); ++i){
        if (commands[i] == 1){
            if (B.x != 1){
                if (commands[i+1]==4){
                }
                else {
                    temp_b.x = B.x;
                    temp_b.y = B.y;
                    b.push_back(temp_b);
                    --B.x;
                }
            }
        }
        else if (commands[i] == 2){
            if (commands[i+1]==4){
            }
            else {
                temp_b.x = B.x;
                temp_b.y = B.y;
                ++B.y;
                b.push_back(temp_b);
            }
        }
        else if (commands[i] == 3){
            if (B.x != 7){
                if (commands[i+1]==4){
                }
                else {
                    temp_b.x = B.x;
                    temp_b.y = B.y;
                    ++B.x;
                    b.push_back(temp_b);
                }
            }
        }
    }

    for (int j=0; j<=B.y; ++j){
        cout << '#';
        for (int i=1; i<=7; ++i){
            if (B.y == j && B.x == i){
                cout << 'B';
            }
            else if (samadenganb(i,j)){
                cout << 'b';
            }
            else cout << ' ';
        }
        cout << "#";
        if (j!=B.y){
            cout << endl;
        }
    }
    return 0;
}

