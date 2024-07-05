#include <iostream>
#include <ctime>

using namespace std;

void Bai4()
{

    int day, month, year;
    cout << "Nhap nam (yyyy): ";
    cin >> year;
    bool is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int days_in_month = 31;
    cout << "Nhap thang (mm): ";
    cin >> month;
    do {
        cout << "Nhap ngay (dd): ";
        cin >> day;
    } while ((is_leap_year == 0 && month == 2) && (day > 28));

    switch (month)
    {
    case 2:
        if (is_leap_year)
            days_in_month = 29;
        else
            days_in_month = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days_in_month = 30;
        break;
    default:
        break;
    }


    if (day == days_in_month)
    {
        day = 1;
        if (month == 12)
        {
            month = 1;
            year++;
        }
        else
        {
            month++;
        }
    }
    else
    {
        day++;
    }
    cout << "Ngay ke tiep la: " << day << "/" << month << "/" << year << endl;
}
int main() {
    Bai4();
}
