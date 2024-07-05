#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{

    if (a == 0) return b;
    return gcd(a, b % a);
}


void rutgonPS(int a,int b)
{
    int i = __gcd(a,b);
    a /= i;
    b /= i;
    float z;
    z = (float)a/b;
    if (a%b==0 )cout <<z;
    else cout <<a <<"/" <<b;
}
void Tong (int a,int b, int c ,int d)
{
    int z,x;
    if (b==d ) {z = a+c; x =d;}
    else {z= a*d + b*c; x = b*d;};
    rutgonPS(z,x);
}

void Hieu(int a,int b, int c ,int d)
{
    int z,x;
    if (b==d ) {z = a-c; x =d;}
    else {z= a*d - b*c; x = b*d;};
    rutgonPS(z,x);
}
void Tich(int a,int b, int c ,int d)
{
    int z,x;
    z = a*c;
    x = b*d;
    rutgonPS(z,x);
}

void Thuong(int a,int b, int c ,int d)
{
    int z,x;
    z = a*d;
    x = b*c;
    rutgonPS(z,x);
}
int main()
{
    int a,b,c,d;
    cout <<"Nhap vao tu so cua phan so thu nhat: ";
    cin >>a;
    cout <<"Nhap vao mau so cua phan so thu hai: ";
    cin >>b;
    cout <<"Nhap vao tu so cua phan so thu hai: ";
    cin >>c;
    cout <<"Nhap vao mau so cua phan so thu hai: ";
    cin >>d;
    cout<<"Tong: "; Tong(a,b,c,d); cout<<endl;
    cout<<"Hieu: "; Hieu(a,b,c,d);cout<<endl;
    cout<<"Tich: "; Tich(a,b,c,d);cout<<endl;
    cout<<"Thuong: "; Thuong(a,b,c,d);cout<<endl;
    return 0;

}
