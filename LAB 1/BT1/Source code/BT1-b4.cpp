#include <iostream>
#include <ctime>

using namespace std;

void Bai4()
{

    int day, thang, nam;
    cout << "Nhap nam (yyyy): ";
    cin >> nam;
    bool Namnhuan = (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
    int ngay = 31;
    cout << "Nhap thang (mm): ";
    cin >> thang;
    do {
        cout << "Nhap ngay (dd): ";
        cin >> day;
    } while ((Namnhuan == 0 && thang == 2) && (day > 28));

    switch (thang)
    {
    case 2:
        if (Namnhuan)
            ngay = 29;
        else
            ngay = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        ngay = 30;
        break;
    default:
        break;
    }


    if (day == ngay)
    {
        day = 1;
        if (thang == 12)
        {
            thang = 1;
            nam++;
        }
        else
        {
            thang++;
        }
    }
    else
    {
        day++;
    }
    cout << "Ngay ke tiep la: " << day << "/" << thang << "/" << nam << endl;
}
int main() {
    Bai4();
}
