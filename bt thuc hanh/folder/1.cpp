#include <iostream>
#define MAX 100

using namespace std;

class Matrix
{
    double a[MAX][MAX];
    int sodong;
    int socot;

public:
    Matrix(double a[MAX][MAX], int sodong, int socot)
    {
        this->sodong = sodong;
        this->socot = socot;

        for (int i = 0; i < sodong; i++)
        {
            for (int j = 0; j < socot; j++)
            {
                this->a[i][j] = a[i][j];
            }
        }
    }

    Matrix() {}

    void Nhap(double b[MAX][MAX], int sodong, int socot)
    {
        this->sodong = sodong;
        this->socot = socot;

        for (int i = 0; i < sodong; i++)
        {
            for (int j = 0; j < socot; j++)
            {
                this->a[i][j] = b[i][j];
            }
        }
    }

    void Xuat()
    {
        for (int i = 0; i < sodong; i++)
        {
            for (int j = 0; j < socot; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix &other) const
    {
        Matrix result;
        if (sodong != other.sodong || socot != other.socot)
        {
            cout << "Khong the cong hai ma tran khac kich thuoc!";
            return Matrix();
        }
        result.sodong = max(this->sodong, other.sodong);
        result.socot = max(this->socot, other.socot);

        for (int i = 0; i < result.sodong; i++)
        {
            for (int j = 0; j < result.socot; j++)
            {
                result.a[i][j] = this->a[i][j] + other.a[i][j];
            }
        }

        return result;
    }

    Matrix operator-(const Matrix &other) const
    {
        Matrix result;
        if (sodong != other.sodong || socot != other.socot)
        {
            cout << "Khong the tru hai ma tran khac kich thuoc!";
            return Matrix();
        }
        result.sodong = max(this->sodong, other.sodong);
        result.socot = max(this->socot, other.socot);

        for (int i = 0; i < result.sodong; i++)
        {
            for (int j = 0; j < result.socot; j++)
            {
                result.a[i][j] = this->a[i][j] - other.a[i][j];
            }
        }

        return result;
    }

    Matrix operator*(const Matrix &other) const
    {
        Matrix result;
        result.sodong = this->sodong;
        result.socot = other.socot;

        for (int i = 0; i < result.sodong; i++)
        {
            for (int j = 0; j < result.socot; j++)
            {
                result.a[i][j] = 0;

                for (int k = 0; k < this->socot; k++)
                {
                    result.a[i][j] += this->a[i][k] * other.a[k][j];
                }
            }
        }

        return result;
    }

    friend istream &operator>>(istream &is, Matrix &m)
    {
        cout << "Nhap vao so dong va so cot cua ma tran: ";
        is >> m.sodong >> m.socot;

        cout << "Nhap vao cac phan tu cua ma tran: " << endl;
        for (int i = 0; i < m.sodong; i++)
        {
            for (int j = 0; j < m.socot; j++)
            {
                is >> m.a[i][j];
            }
        }

        return is;
    }

    friend ostream &operator<<(ostream &os, const Matrix &m)
    {
        for (int i = 0; i < m.sodong; i++)
        {
            for (int j = 0; j < m.socot; j++)
            {
                os << m.a[i][j] << " ";
            }
            os << endl;
        }

        return os;
    }
};

int main()
{
    Matrix a, b;

    cin >> a;
    cout << "Ma tran A: " << endl;
    cout << a;

    cin >> b;
    cout << "Ma tran B: " << endl;
    cout << b;

    Matrix sum = a + b;
    cout << "Tong hai ma tran: " << endl;
    cout << sum;

    Matrix hieu = a - b;
    cout << "Tong hai ma tran: " << endl;
    cout << hieu;
    Matrix tich = a * b;
    cout << "Tich hai ma tran: " << endl;
    cout << tich;


    return 0;
}
