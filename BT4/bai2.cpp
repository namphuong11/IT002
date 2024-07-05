#include <bits/stdc++.h>
using namespace std;
class CTime
{
    int h,m,s;
public:
    CTime(){this -> h = 0;this -> m = 0;this -> s = 0;}

    void Nhap()
    {

        cout <<"Hay nhap thoi diem: ";
        cin >> h >>m>>s;
        this -> h = h;
        this -> m = m;
        this -> s = s;
        if (h>24 || h >60 ||s>60)
        {
            cout <<"Hay nhap lai thoi diem: ";
        cin >> h >>m>>s;
        this -> h = h;
        this -> m = m;
        this -> s = s;
        }
    }
    void Xuat()
    {

        cout <<h <<"h" <<m <<"m" <<s <<"s" <<endl;
    }
    void Cong(int s1)
    {
        cout <<"Hay nhap so giay cong vao: ";
        cin >>s1;
        s += s1;
    if (s >= 60) {
        m += s / 60;
        s %= 60;
    }
    if (m >= 60) {
        h+= m / 60;
        m %= 60;
    }
    }

    void Tru(int s2)
    {
        cout <<"Hay nhap so giay tru di: ";
        cin >>s2;
        s -= s2;
    if (s <= 0) {
        m += s / 60 - 1;
        s = 60 + s % 60;
    }
    if (m < 0) {
        h+= m / 60 - 1;
        m = 60 + m % 60;
    }

    }

    void CTimeSpan(CTime &b)
    {
        this -> s  -= b.s;
        this -> m  -= b.m;
        this -> h -=  b.h;
        if (s <= 0) {
        m += s / 60 - 1;
        s = 60 + s % 60;
    }
    if (m < 0) {
        h+= m / 60 - 1;
        m = 60 + m % 60;
    }

    }

    void Cong1s()
    {
        this -> s++;
        if (s >= 60) {
        m += s / 60;
        s %= 60;
    }
    if (m >= 60) {
        h+= m / 60;
        m %= 60;
    }

    }
    void Tru1s()
    {
        this -> s--;
        if (s < 0) {
        m += s / 60 - 1;
        s = 60 + s % 60;
    }
    if (m < 0) {
        h+= m / 60 - 1;
        m = 60 + m % 60;
    }
    }

};

int main()
{
    CTime a;
    a.Nhap();
    a.Xuat();
    a.Cong(0);
    a.Xuat();
    a.Tru(0);
    a.Xuat();
    CTime b;
    cout <<"Nhap moc thoi gian thu 2: ";
    b.Nhap();
    a.CTimeSpan(b);
    a.Xuat();
    a.Tru1s();
    cout <<"Bot 1 giay vao thoi diem: ";
    a.Xuat();
}
