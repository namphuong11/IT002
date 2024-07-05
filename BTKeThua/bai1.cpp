    #include <iostream>
using namespace std;

class Nhanvien
{
protected:
    string name;
    int ngay, thang, nam;
    long long salary;

public:
    Nhanvien(string name, int ngay, int thang, int nam, long long salary)
    {
        this->name = name;
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
        this->salary = salary;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setNgay(int ngay)
    {
        this->ngay = ngay;
    }

    void setThang(int thang)
    {
        this->thang = thang;
    }

    void setNam(int nam)
    {
        this->nam = nam;
    }

    void setSalary(long long salary)
    {
        this->salary = salary;
    }

    string getName()
    {
        return name;
    }

    void getNtns()
    {
        cout << this->ngay << "/" << this->thang << "/" << this->nam;
    }

    long long getSalary()
    {
        return salary;
    }

    void display()
    {
        cout << "Ho ten cua nhan vien nay la: " << this->name << endl;
        cout << "Ngay thang nam sinh cua nhan vien la: ";
        getNtns();
        cout << endl;
        cout << "Luong cua nhan vien nay la: " << getSalary() << endl;
    }
};

class VanPhong : public Nhanvien
{
    int songaylamviec;

public:
    VanPhong(string name, int ngay, int thang, int nam, long long salary, int songaylamviec)
        : Nhanvien(name, ngay, thang, nam, salary)
    {
        this->songaylamviec = songaylamviec;
    }

    void calculateSalary()
    {
        salary  = songaylamviec * 100000;
    }
};

class SanXuat : public Nhanvien
{
    int sosp;

public:
    SanXuat(string name, int ngay, int thang, int nam, long long salary, int sosp)
        : Nhanvien(name, ngay, thang, nam, salary)
    {
        this->sosp = sosp;
    }

    void calculateSalary()
    {
        salary += sosp * 5000;
    }
};

int main()
{
    cout << "Hay nhap so nhan vien: ";
    int n;
    cin >> n;
    Nhanvien *p[n];
    for (int i = 0; i < n; i++)
    {
        cout << "1. Nhan vien san xuat" << endl;
        cout << "2. Nhan vien van phong" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            string name;
            int ngay, thang, nam;
            long long salary;
            int sosp;

            cout << "Hay nhap ten cua nhan vien: ";
            cin.ignore();
            getline(cin, name);

            cout << "Hay nhap vao ngay thang nam sinh cua nhan vien: ";
            cin >> ngay >> thang >> nam;
            if (ngay >31||thang > 12 || nam < 0 || ngay < 1 || thang < 1)
            {
                cout << "Hay nhap lai ngay thang nam sinh phu hop! : ";
                cin >> ngay >> thang >> nam;
            }
            else if (thang == 1 || thang == 3 || thang == 5 ||thang ==7 ||thang ==8||thang ==10 || thang == 12)
            {
                if (ngay >31)
                    {
                        cout << "Hay nhap lai ngay thang nam sinh phu hop! : ";
                        cin >> ngay >> thang >> nam;
                    }
            }
            else if (thang == 2)
            {
                if (ngay> 28)
                {
                    cout << "Hay nhap lai ngay thang nam sinh phu hop! : ";
                    cin >> ngay >> thang >> nam;
                }
            }
            else
            {
                if (ngay > 30)
                {
                    cout << "Hay nhap lai ngay thang nam sinh phu hop! : ";
                    cin >> ngay >> thang >> nam;
                }
            }

            cout << "Hay nhap luong co ban cua nhan vien: ";
            cin >> salary;

            cout << "Hay nhap so san pham cua nhan vien: ";
            cin >> sosp;

            SanXuat *a = new SanXuat(name, ngay, thang, nam, salary, sosp);
            a->calculateSalary();
            p[i] = a;
        }
        else if (choice == 2)
        {
            string name;
            int ngay, thang, nam;
            int songaylamviec;

            cout << "Hay nhap ten cua nhan vien: ";
            cin.ignore();
            getline(cin, name);

            cout << "Hay nhap vao ngay thang nam sinh cua nhan vien: ";
            cin >> ngay >> thang >> nam;
            if (ngay >31||thang > 12 || nam < 0 || ngay < 1 || thang < 1)
            {
                cout << "Hay nhap lai ngay thang nam sinh phu hop! : ";
                cin >> ngay >> thang >> nam;
            }
            else if (thang == 1 || thang == 3 || thang == 5 ||thang ==7 ||thang ==8||thang ==10 || thang == 12)
            {
                if (ngay >31)
                    {
                        cout << "Hay nhap lai ngay thang nam sinh phu hop! : ";
                        cin >> ngay >> thang >> nam;
                    }
            }
            else if (thang == 2)
            {
                if (ngay> 28)
                {
                    cout << "Hay nhap lai ngay thang nam sinh phu hop! : ";
                    cin >> ngay >> thang >> nam;
                }
            }
            else
            {
                if (ngay > 30)
                {
                    cout << "Hay nhap lai ngay thang nam sinh phu hop! : ";
                    cin >> ngay >> thang >> nam;
                }
            }

            cout << "Hay nhap so ngay lam viec cua nhan vien: ";
            cin >> songaylamviec;

            VanPhong *a = new VanPhong(name, ngay, thang, nam, 0, songaylamviec);
            a->calculateSalary();
            p[i] = a;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Thong tin cua nhan vien thu " << i + 1 << " la: " << endl;
        p[i]->display();
    }

    for (int i = 0; i < n; i++)
    {
        delete p[i];
    }

    return 0;
}
