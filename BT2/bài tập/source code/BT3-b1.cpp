#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (a == 0) return b;
    else return gcd(b % a, a);
}
class PhanSo
{
private:
    int tu, mau;

public:
    PhanSo()
    {
        tu = 0;
        mau = 1;
    }
    PhanSo(int t, int m)
    {
        tu = t;
        mau = m;
    }
    void Nhap()
    {
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;
    }
    void Xuat()
    {
            int i = gcd(tu, mau);
            tu /= i;
            mau /= i;
            int z;
            z = (int)tu / mau;
            if (tu % mau == 0) cout << z << endl;
            else cout << tu << '/' << mau << endl;

    }
    PhanSo Cong(PhanSo b)
    {
        PhanSo c;
        c.tu = tu * b.mau + mau * b.tu;
        c.mau = mau * b.mau;
        return c;
    }
    PhanSo Tru(PhanSo b)
    {
        PhanSo c;
        c.tu = tu * b.mau - mau * b.tu;
        c.mau = mau * b.mau;
        return c;
    }

    PhanSo Nhan(PhanSo b)
    {
        PhanSo c;
        c.tu = tu * b.tu;
        c.mau = mau * b.mau;
        return c;

    }
    PhanSo Chia(PhanSo b)
    {
        PhanSo c;
        c.tu = tu * b.mau;
        c.mau = mau * b.tu;
        return c;
    }
    double GiaTri()
    {
        return (double)tu / mau;
    }
};


int main()
{
    PhanSo a, b, c;
    a.Nhap();
    b.Nhap();

    cout << "Phan so a = ";
    a.Xuat();
    cout << "Gia tri phan so a = " << a.GiaTri() << endl;


    cout << "Phan so b = ";
    b.Xuat();
    cout << "Gia tri phan so b = " << b.GiaTri() << endl;
    c = a.Cong(b);
    cout << "a + b = ";
    c.Xuat();

    c = a.Tru(b);
    cout << "a - b = ";
    c.Xuat();

    c = a.Nhan(b);
    cout << "a * b = ";
    c.Xuat();

    c = a.Chia(b);
    cout << "a / b = ";
    c.Xuat();
}
