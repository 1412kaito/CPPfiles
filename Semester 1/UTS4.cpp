#include <iostream>

using namespace std;

int main()
{
    int JumlahPasien;
    do
    {
        cout << "Inputkan jumlah pasien yang akan diinput datanya : ";
        cin >> JumlahPasien;
    } while (JumlahPasien < 1);

    int kadar, batNormal, jumlahDM = 0, normal = 0, bahaya = 0, hati = 0;
    double rataan = 0;
    int terendah = 1000, tertinggi = 0;
    string n_Terendah, n_Tertinggi, nama;
    char DM;

    for (int i=1; i<= JumlahPasien; i++)
    {
        DM=' '; kadar = 0; batNormal = 200;

        cout << "Inputkan Nama Pelanggan : ";
        cin >> nama;
        cout << "Inputkan kandungan Trigliserida (mg/dL) : ";
        cin >> kadar;
        cout << "Apakah " << nama << " menderita diabetes melitus ? (Y/y/T/t)" << endl;
        cin >> DM;

        if (DM == 'Y' || DM == 'y')
        {
            batNormal = 150;
            jumlahDM++;
        }

        rataan += kadar;

        if (kadar < batNormal) normal++;
        else if (kadar > 400) bahaya++;
        else hati++;

        if (kadar >= tertinggi)
        {
            tertinggi = kadar;
            n_Tertinggi = nama;
        }

        if (kadar <= terendah)
        {
            terendah = kadar;
            n_Terendah = nama;
        }
    }

    cout << "Rata - rata kandungan  Trigliserida dalam darah pasien : " << rataan / (float) JumlahPasien << endl;
    cout << "Jumlah pasien yang menderita Diabetes Melitus / DM     : " << jumlahDM << endl;
    cout << "Pasien dalam kategori normal                           : " << normal << endl;
    cout << "Pasien dalam kategori hati - hati                      : " << hati << endl;
    cout << "Pasien dalam kategori bahaya                           : " << bahaya << endl;
    cout << "Pasien dengan kandungan Trigliserida tertinggi         : " << n_Tertinggi << endl;
    cout << "           kandungan Trigliseridanya sebesar           : " << tertinggi << endl;
    cout << "Pasien dengan kandungan Trigliserida terendah          : " << n_Terendah << endl;
    cout << "           kandungan Trigliseridanya sebesar           : " << terendah << endl;

    return 0;
}
