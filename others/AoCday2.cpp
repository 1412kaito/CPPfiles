#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    ifstream file ("namafile.txt");
    string temp;
    vector<int> baris16;
    baris16.push_back(0);
    if (file.is_open()){
        int temp;
        while (file >> temp){
            baris16.push_back(temp);
        }
        file.close();
    }

    vector <int> hasil;
    for (int i=0; i< 16; ++i){
        int _tempmaks, _tempmin;
        _tempmaks = 0; _tempmin = 2000000;
        for (int j=1+(i*16); j<=16+(16*i); ++j){
            for (int k=j+1; k<=16+(16*i); ++k){
                if (baris16[j]>baris16[k]){
                    if (baris16[j]%baris16[k]==0){
                        cout << baris16[j] << " " << baris16[k];
                        hasil.push_back(baris16[j]/baris16[k]);
                    }
                }
                else if (baris16[k]>=baris16[j]){
                    if (baris16[k]%baris16[j]==0){
                        cout << baris16[j] << " " << baris16[k];
                        hasil.push_back(baris16[k]/baris16[j]);
                    }
                }
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << hasil[0]<<"  ";
    for (int i=1; i<hasil.size(); ++i){
        cout << hasil[i] << " ";
        hasil[0]+=hasil[i];
    }
    cout << endl << "====" << endl;
    cout << hasil[0];
    return 0;

}

