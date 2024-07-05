#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    int tmp;
    while(b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    int a,b;
    cout <<"Nhap vao tu so: ";
    cin >>a;
    cout <<"Nhap vao mau so: ";
    cin >>b;

    int i = gcd(a,b);
    a /= i;
    b /= i;
    float z;
    z = (float)a/b;
    if (a%b==0 )cout <<"Phan so da rut gon la: " <<z;
    else  cout<<"Phan so da rut gon la: " <<a <<"/" <<b;
    return 0;
}
