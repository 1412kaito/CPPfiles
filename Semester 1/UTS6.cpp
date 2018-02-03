#include <iostream>

using namespace std;

int main()
{
    short A, B;
    float C, temp;
    A=100;

    do
    {
        A--;
        if (A%11 == 0) A -= 1;

        B=(A/10)+(A%10*10);

        if (B > A) A--;
        else temp = A - B;

    } while ((float)temp/(float)2 * 10 != B);

    cout << "Umur A : " << A << " tahun" << endl;
    cout << "Umur B : " << B << " tahun" << endl;;
    cout << "Umur C : " << temp << " tahun" << endl;;

    return 0;
}
