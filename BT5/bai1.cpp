#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
class String
{
    char *data;
public:
    String()
    {
        data = nullptr;
    }
    String(char *str)
    {
        int length = strlen(str);
        data = new char [length+1];
        strcpy(data,str);
    }
    ~String()
    {
        delete[] data;
    }

    int getLength()
    {
        return strlen(data);
    }

    String link(String &other)
    {
        int newlen = getLength() + other.getLength();
        char *p = new char [newlen+1];
        strcpy(p,data);
        strcat(p,other.data);
        String result(p);
        delete []p;
        return result;
    }
    String reverseString()
    {
        int length = getLength();
        char *p = new char[length+1];
        for (int i = 0;i<length;i++)
        {
            p[i] = data[length - i -1];
        }
        p[length] = '\0' ;
        String result(p);
        delete []p;
        return result;
    }

    void input()
    {
        char p[MAX];
        cout <<"Hay nhap vao chuoi: ";
        cin.getline(p,MAX);
        int length = strlen(p);
        data = new char [length +1];
        strcpy(data,p);
    }
    void output()
    {
        cout <<"Chuoi: " <<data <<endl;
    }



};

int main()
{
    String s1;
    String s2;
    s1.input();
    s2.input();
    cout<<s1.getLength() <<endl;
    s1.output();
    String s3 = s2.reverseString();
    s3.output();
    String s4 = s1.link(s2);
    s4.output();
}
