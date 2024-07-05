
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Animal
{
protected:
    string sound;
    int milk;
    int soluong;
public:
    Animal(int milk, int soluong)
    {
        this -> milk = milk;
        this -> soluong = soluong;
    }
    virtual void displaySound()
    {
        cout <<sound <<endl;
    }
    virtual void calculate(int sinh)
    {
        this ->soluong += sinh;
    }
    virtual void display()
    {
        cout<<"So luong con hien tai sau lua sinh trong nong trai la: " <<this ->soluong <<endl;
        cout<<"So lua sua loai nay cho sau lua sinh la: " <<this->milk <<endl;
    }

};

class Cow : public Animal
{
public:
    Cow(int milk = 0, int soluong=0) : Animal(milk,soluong)
    {
        this -> sound = "moo moo";
        this ->milk = milk;
        this ->soluong = soluong;
    }
    void display()
    {
        cout <<"-----Cow Info-----" <<endl;
        Animal ::display();
    }

};

class Sheep : public Animal
{
public:
    Sheep( int milk= 0, int soluong=0) : Animal(milk,soluong)
    {
        this -> sound = "bleat bleat";
        this -> milk = milk;
        this -> soluong = soluong;
    }
    void display()
    {
        cout <<"-----Sheep Info-----" <<endl;
        Animal ::display();
    }
};

class Goat : public Animal
{
public:
    Goat(int milk=0 , int soluong=0) : Animal(milk,soluong)
    {
        this -> sound = "baa baa";
        this -> milk = milk;
        this -> soluong = soluong;
    }
    void display()
    {
        cout <<"-----Goat Info-----" <<endl;
        Animal ::display();
    }
};

int main()
{
    srand(time(0));
    Animal *p[3];
    Cow *cow = new Cow();
    Sheep *sheep = new Sheep();
    Goat *goat = new Goat();
    p[0] = cow;
    p[1] = sheep;
    p[2] = goat;
    cout <<"Khi chu nong trai di vang, nhung tieng keu doi nghe duoc trong nong trai la: " <<endl;
    for (int i = 0;i<3;i++)
    {
        p[i] ->displaySound();
    }
    for (int i = 0;i<3;i++)
    {
        delete p[i];
    }
    int numberOfCow;
    int numberOfSheep;
    int numberOfGoat;
    cout <<"Hay nhap so luong con bo truoc khi lua sinh den: ";
    cin >>numberOfCow;
    cout <<"Hay nhap so luong con cuu  truoc khi lua sinh den: ";
    cin >>numberOfSheep;
    cout <<"Hay nhap so luong con de  truoc khi lua sinh den: ";
    cin >>numberOfGoat;
    int milkCow = rand() % 21;
    int milkSheep = rand() % 6;
    int milkGoat = rand() % 11;
    Cow *cow1 = new Cow(milkCow,numberOfCow);
    Sheep *sheep1 = new Sheep(milkSheep,numberOfSheep);
    Goat *goat1 = new Goat(milkGoat,numberOfGoat);
    p[0] = cow1;
    p[1] = sheep1;
    p[2] = goat1;
    for (int i = 0;i<3;i++)
    {
        int sinh = rand();
        p[i]->calculate(sinh);
        p[i] ->display();
    }


}
