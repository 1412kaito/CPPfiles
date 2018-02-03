#include <iostream>

using namespace std;

int main()
{
    int input;
    cin >> input;

    // cetak kerangka nya dulu (segitiga sama sisi)

    for (int baris = 1; baris <= input; baris++)
    {
        double paskal = 1;
        for (int spasi = input; spasi >= baris; spasi--)
        {
            cout << " ";
        }
        for (int isi = 1; isi <= (baris); isi++)
        {
            cout << paskal << " ";
            paskal = (double)(paskal*(baris-isi)/isi);
        }
        //cout << baris;

        cout << endl;
    }


    return 0;
}
