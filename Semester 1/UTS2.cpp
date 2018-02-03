#include <iostream>
#include <math.h>

using namespace std;

int main ()
{
    float jam, menit;

    cout << "Inputkan jam : ";
    cin >> jam;
    cout << "Inputkan menit : ";
    cin >> menit;

    float jarumJam, jarumMenit;
    float temp;
    jarumJam = jam * 30 - ((float)menit/(float)60 * 30);
    jarumMenit = menit * 5;

    temp = sqrt((jarumJam - jarumMenit)*(jarumJam - jarumMenit));

    if (temp > 180)
        temp = 360 - temp;

    cout << temp;
    return 0;
}
