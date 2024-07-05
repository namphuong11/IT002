#include <bits/stdc++.h>
using namespace std;

class Candidate{
private:
    string ma;
    string name;
    string ntns;
    int toan;
    int van;
    int anh;
public:
    Candidate(string ma,string name,string ntns,float toan,float van,float anh)
    {
        this -> ma = ma;
        this -> name = name;
        this -> ntns = ntns;
        this -> toan = toan;
        this -> van = van;
        this -> anh = anh;
    }
    int sum()
    {
        return toan + van + anh;
    }
    void Xuat()
    {
        cout <<"Ma: " <<ma <<endl;
        cout <<"Ten: " <<name<<endl;
        cout <<"Ngay thang nam sinh: " <<ntns<<endl;
        cout <<"Diem toan: " <<toan <<endl;
        cout <<"Diem van: " <<van <<endl;
        cout <<"Diem anh: " <<anh <<endl;
    }
    };

class TestCandidate
{
public:
    static vector<Candidate> Nhap_ds_ts()
    {
        int n;
        cout <<"Nhap vao so thi sinh: " ;
        cin >>n;

        vector<Candidate> danh_sach;
            for (int i = 0;i<n;i++)
            {
                cout <<"Nhap vao thong tin thi sinh thu " <<i+1 <<":" <<endl;
                string ma;
                string name;
                string ntns;
                float toan;
                float van;
                float anh;
                cout << "Ma: ";
                cin.ignore();
                cin >> ma;
                cout << "Ten: ";
                cin.ignore();
                getline(cin, name);
                cout << "Ngay sinh: ";cin.ignore();
                getline(cin, ntns);
                cout << "Diem toan: ";
                cin >> toan;
                cout << "Diem van: ";
                cin >> van;
                cout << "Diem anh: ";
                cin >> anh;


                Candidate thi_sinh(ma,name,ntns,toan,van,anh);
                danh_sach.push_back(thi_sinh);




            }
            return danh_sach;
    }
    static void display(vector<Candidate> danh_sach)
    {
        cout <<endl <<"Danh sach thi sinh co tong diem hon 15: " <<endl;
        for (Candidate thi_sinh : danh_sach) {
                if (thi_sinh.sum() > 15) {
                    thi_sinh.Xuat();
                }
            }

    }


};

int main()
{
    vector<Candidate> danh_sach = TestCandidate::Nhap_ds_ts();
    Candidate::Xuat(danh_sach);
    return 0;
}
