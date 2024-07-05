
#include<bits/stdc++.h>
using namespace std;
struct nhantobian{
string ten;
double toan;
double van;
};
nhantobian a;
double dtb(double &toan, double &van)
{
    return ((toan+van)/2);
}
int main()
{
    cout <<"Nhap ho ten cua hoc sinh: ";
    getline(cin,a.ten);
    cout <<"Nhap diem toan: ";
    cin>>a.toan;
    cout <<"Nhap diem van: ";
    cin>>a.van;
    cout <<"Ten cua hoc sinh la: "<<a.ten<<' ';
    cout<<"Diem trung binh cua hoc sinh: "<<dtb(a.toan,a.van);
    return 0;
}
