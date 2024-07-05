#include<iostream>
#include<math.h>
using namespace std;
class con {
private:
	float thuc, ao;
public:
	con()
	{
		thuc = 0;
		ao = 0;
	}
	con(float t, float a)
	{
		thuc = t;
		ao = a;
	}
	void nhap()
	{
		cout << "Nhap phan thuc: ";
		cin >> thuc;
		cout << "Nhap phan ao: ";
		cin >> ao;
	}
	void xuat()
	{
		cout << thuc <<" + " << ao << "i" << endl;
	}
	con cong(con b)
	{
		con c;
		c.thuc = thuc + b.thuc;
		c.ao = ao + b.ao;
		return c;
	}
	con tru(con b)
	{
		con c;
		c.thuc = thuc - b.thuc;
		c.ao = ao - b.ao;
		return c;
	}
	con nhan(con b)
	{
		con c;
		c.thuc = thuc * b.thuc - ao * b.ao;
		c.ao = thuc * b.ao + ao * b.thuc;
		return c;
	}
	con chia(con b)
	{
		con c;
		c.thuc = (thuc * b.thuc + ao * b.ao)/(pow(b.thuc,2) + pow(b.ao,2));
		c.ao = (ao * b.thuc - thuc * b.ao)/(pow(b.thuc, 2) + pow(b.ao, 2));
		return c;
	}
};

int main()
{
	con a, b, c;
	a.nhap();
	b.nhap();
	cout << "So phuc A: ";
	a.xuat();
	cout << "So phuc B: ";
	b.xuat();
	c = a.cong(b);
	cout << "Tong 2 so phuc= ";
	c.xuat();
	c = a.tru(b);
	cout << "Hieu 2 so phuc= ";
	c.xuat();
	c = a.nhan(b);
	cout << "Tich 2 so phuc= ";
	c.xuat();
	c = a.chia(b);
	cout << "So A chia so B= ";
	c.xuat();

}
