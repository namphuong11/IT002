#include"String.h"
#include<iostream>
const int ArSize=10;
const int MaxLen =81;
using namespace std;
int main(){
    String Name1;
    String Name2;
    cout<<"Input Name1: ";
    cin>>Name1;
    cout<<"Input Name2: ";
    cin>>Name2;
    cout<<"Name1: "<<Name1<<endl;
    cout<<"Name2: "<<Name2<<endl;
    String Sum;
    Sum=Name1+Name2;
    cout<<"After Add: "<<Sum<<endl;
   Sum.ReverseString();
   cout<<"After reverse: "<<Sum<<endl;
   Sum.ToLowerString();
   cout<<"After to Lower all: "<<Sum<<endl;
   Sum.ToUpperString();
   cout<<"After to Upper All: "<<Sum<<endl;
   cout<<"Get Len: "<<Sum.GetterLen();
   return 0;
}