#include <bits/stdc++.h>
using namespace std;

class Malware
{
    string name;
    string file;
public:
    Malware()
    {
    }
    virtual void Nhap()
    {
        cout <<"Hay nhap ten cua malware: ";
        cin.ignore();
        getline(cin,this->name);
        cout <<"Hay nhap ten file malware dang o: ";
        cin.ignore();
        getline(cin,this->file);
    }
    virtual void Xuat()
    {
        cout <<"Ten cua malware la: " <<this->name <<endl;
        cout <<"Ten file cua malware la: " <<this->file <<endl;
    }
};

class Virus : public Malware
{
    string signature;
    string behavior;
public:
    Virus(){}
    void Nhap()
    {
        cout <<"Hay nhap chu ki cua virus: ";
        cin.ignore();
        getline(cin,this->signature);
        cout <<"Hay nhap hanh vi cua virus: ";
        cin.ignore();
        getline(cin,this->behavior);
    }
    void Xuat()
    {
        cout <<"Chu ki cua virus la: " <<this->signature <<endl;
        cout <,"Hanh vi cua virus la: " <<this->behavior <<endl;
    }
};

class Trojan : public Malware
{
    string payload;
    string disguise;
public:
    void Nhap()
    {
        cout <<"Hay nhap payload cua Trojan: ";
        cin.ignore();
        getline(cin,this->payload);
        cout <<"Hay nhap hanh vi gia mao cua Trojan: ";
        cin.ignore();
        getline(cin,this->disguise);
    }
    void Xuat()
    {
        cout <<"Payload cua Trojan la: " <<this->payload <<endl;
        cout <,"Hanh vi gia mao cua Trojan la: " <<this->disguise <<endl;
    }
};

class Ransomware:public Malware
{
    string encrypKey;
    int ransomAmount;
    void Nhap()
    {
        cout <<"Hay nhap khoa ma hoa cua RansomWare: ";
        cin.ignore();
        getline(cin,this->encrypkey);
        cout <<"Hay nhap so tien chuoc cua Trojan: ";
        cin.ignore();
        getline(cin,this->ransomAmount);
    }
    void Xuat()
    {
        cout <<"Payload cua Trojan la: " <<this->payload <<endl;
        cout <,"Hanh vi gia mao cua Trojan la: " <<this->disguise <<endl;
    }

};

int main()
{
    Malware *p;
}
