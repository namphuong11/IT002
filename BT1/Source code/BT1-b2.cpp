#include <iostream>
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
    if (a%b==0 ) cout <<"Phan so lon hon la: " <<z;
    else cout <<"Phan so lon hon la: " <<a <<"/" <<b;
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
    if (b == d)
    {
        if (a>c) rutgonPS(a,b);
            else rutgonPS(c,d);
    }
    else
    {
        int z,x;

        z=a * d;
        x =c* b;
        if (z>x) rutgonPS(a,b);
            else rutgonPS(c,d);
    }
    return 0;
}
