    #include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

class ToaDo {
 private:
     float hoanhdo,tungdo;
 public:
    ToaDo(){hoanhdo = 0;tungdo = 0;}
    void Nhap()
    {
        cout <<"Hay nhap vao hoanh do: ";
        int x;
        cin >>x;
        this -> hoanhdo = x;
        cout <<"Hay nhap vao tung do: ";
        int y;
        cin >>y;
        this -> tungdo = y;
    }
    void Xuat()
    {
        cout <<"Toa do cua diem la: " <<"(" <<this -> hoanhdo <<"," <<this -> tungdo <<")" <<endl;
    }
    void LayTung()
    {
        float x;
        cout <<"Hay nhap tung do: ";
        cin >>x;
        this -> tungdo = x;
    }
    void LayHoanh ()
    {
        float y;
        cout <<"Hay nhap hoanh do: ";
        cin >>y;
        this -> hoanhdo = y;
    }
    void tinhtien(float x , float y)
    {
        this -> hoanhdo += x;
        this -> tungdo += y;
    }
    void Ve()
    {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    putpixel(this -> hoanhdo, this -> tungdo, WHITE);

    getch();
    closegraph();
    }

    };

int main(int argc, char** argv)
{
    ToaDo p;
    p.Xuat();
    p.Nhap();
    p.Xuat();
    p.LayHoanh();
    p.Xuat();
    p.LayTung();
    p.Xuat();
    p.tinhtien(4,7);
    p.Xuat();
    p.Ve();



}
