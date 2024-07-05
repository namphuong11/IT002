 v#include <bits/stdc++.h>
using namespace std;
#define MAX 10000

class dathuc
{
    int bac;
    float heso[MAX];
public:

    void Nhap() {
        cout << "Hay nhap bac cua da thuc: ";
        cin >> bac;
        for (int i = bac; i >= 0; i--) {
            cout << "Hay nhap vao he so cua x^" << i << ": ";
            cin >> heso[i];
        }
    }


    void Xuat() {
        cout << "Da thuc cua ban la: ";
        for (int i = bac; i >= 0; i--) {
            if (heso[i] != 0) {
                if (i == bac) {
                    cout << heso[i] << "x^" << i;
                } else if (i == 1) {
                    if (heso[i] > 0) {
                        cout << " + " << heso[i] << "x";
                    } else {
                        cout << " - " << -heso[i] << "x";
                    }
                } else if (i == 0) {
                    if (heso[i] > 0) {
                        cout << " + " << heso[i];
                    } else {
                        cout << " - " << -heso[i];
                    }
                } else {
                    if (heso[i] > 0) {
                        cout << " + " << heso[i] << "x^" << i;
                    } else {
                        cout << " - " << -heso[i] << "x^" << i;
                    }
                }
            }
        }
        cout <<endl;
    }

    double giatri(double x)
    {
        float sum =0;
        for (int i = bac ;i>=0;i--)
        {
            sum += heso[i] * pow(x,i);
        }
        return sum;
    }

    dathuc operator + (dathuc &a) const
    {
        dathuc result;
        result.bac = max(this -> bac,a.bac);
        for (int i = 0;i<=result.bac;i++)
        {
            result.heso[i] =  this->heso[i] + a.heso[i];
        }
        return result;

    }

    dathuc operator - (dathuc &a) const
    {
        dathuc result;
        result.bac = max(this -> bac,a.bac);
        for (int i = 0;i<=result.bac;i++)
        {
            result.heso[i] =  this->heso[i] - a.heso[i];
        }
        return result;

    }
    dathuc operator * (dathuc &a) const
    {
        dathuc result;
        result.bac = this -> bac+a.bac;
        for (int i = 0;i<=a.bac;i++)
        {
            for (int j = 0;j<=this->bac;j++)
            {
                result.heso[i+j] += this->heso[j] * a.heso[i];
            }
        }
        return result;

    }
    dathuc operator * (float k) const
    {
        dathuc result;
        result.bac = this -> bac;
        for (int i = 0;i<= result.bac;i++)
        {
            result.heso[i] = this->heso[i] *k;
        }
        return result;

    }
    dathuc daoham ()
    {
        dathuc result;
        result.bac = this -> bac - 1;
        for (int i = 0;i<=result.bac;i++)
        {
            result.heso[i] =  this->heso[i+1] * (i+1);
        }
        return result;

    }
    dathuc nguyenham ()
    {
        dathuc result;
        result.bac = this -> bac + 1;
        result.heso[0] = 0;
        for (int i = 1;i<=result.bac;i++)
        {
            result.heso[i] =  this->heso[i-1] / i;
        }
        return result;

    }
    void laybac()
    {
        cout <<"Bac cua da thuc nay la: " <<this->bac;
    }





};

int main()
{
    dathuc a;
    a.Nhap();
    a.Xuat();
    int x;
    cout <<"Hay nhap vao gia tri cua x: ";
    cin >>x;
    cout <<endl <<"Gia tri cua da thuc voi x=" <<x <<" la: " <<a.giatri(x);
    dathuc b;
    cout <<"Da thuc thu 2" <<endl;
    b.Nhap();
    dathuc sum = a+b;
    dathuc hieu = a-b;
    dathuc nhandathuc = a*b;
    float k;
    cout <<"Nhap vao so k: ";
    cin >>k;
    dathuc nhank = a*k;
    cout <<"Tong: ";
    sum.Xuat();
    cout <<"Hieu: ";
    hieu.Xuat();
    cout <<"Tich: ";
    nhandathuc.Xuat();
    cout <<"Nhan voi k: ";
    nhank.Xuat();
    dathuc daoham = a.daoham();
    daoham.Xuat();
    dathuc nguyenham = daoham.nguyenham();
    nguyenham.Xuat();

    return 0;
}


