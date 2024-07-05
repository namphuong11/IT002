#include <iostream>
#include <vector>
#include <ctime>
#include <memory>

class Account {
protected:
    std::string username;
    std::string passwordHashed;
    std::string permission;
    int ngay, thang, nam;

public:
    Account(std::string username, std::string passwordHashed, std::string permission, int ngay, int thang, int nam)
        : username(username), passwordHashed(passwordHashed), permission(permission), ngay(ngay), thang(thang), nam(nam) {}

    std::string getUsername() const {
        return username;
    }

    std::string getPasswordHashed() const {
        return passwordHashed;
    }

    std::string getPermission() const {
        return permission;
    }

    void getTime() const {
        std::cout << ngay << "/" << thang << "/" << nam;
    }

    int getThang() const {
        return thang;
    }

    int getNgay() const {
        return ngay;
    }

    virtual void nhap() {}
    virtual void xuat() {}
};

class RegularAccount : public Account {
public:
    RegularAccount() : Account("", "", "", 0, 0, 0) {}
    void setPass(std::string a) {
        this->passwordHashed = a;
    }

    void nhap() override {
        std::string username1;
        std::string passwordHashed1;
        std::string permission1;
        int ngay1, thang1, nam1;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Nhap vao ten nguoi dung: ";
        std::getline(std::cin, username1);
        std::cout << "Nhap vao mat khau: ";
        std::getline(std::cin, passwordHashed1);
        std::cout << "Quyen han cua nguoi dang nhap: ";
        std::getline(std::cin, permission1);

        // Random ngay, thang, nam
        thang1 = rand() % 12 + 1;
        if (thang1 == 2) {
            ngay1 = rand() % 28 + 1;
        }
        else if (thang1 == 4 || thang1 == 6 || thang1 == 9 || thang1 == 11) {
            ngay1 = rand() % 30 + 1;
        }
        else {
            ngay1 = rand() % 31 + 1;
        }
        nam1 = rand() % (2022 - 2018 + 1) + 2018;

        this->username = username1;
        this->passwordHashed = passwordHashed1;
        this->permission = permission1;
        this->ngay = ngay1;
        this->thang = thang1;
        this->nam = nam1;
    }

    void xuat() override {
        std::cout << "Ten cua nguoi dung: " << this->username << std::endl;
        std::cout << "Mat khau la: " << this->passwordHashed << std::endl;
        std::cout << "Quyen truy cap cua nguoi dung khi dang nhap la: " << this->permission << std::endl;
        std::cout << "Lan dang nhap cuoi cung cua tai khoan nay la: ";
        Account::getTime();
        std::cout << std::endl;
    }
};

class AdminAccount : public Account {
public:
    AdminAccount(std::string username, std::string passwordHashed, std::string permission, int ngay, int thang, int nam)
        : Account(username, passwordHashed, permission, ngay, thang, nam) {}

    AdminAccount() : Account("", "", "", 0, 0, 0) {}

    void nhap() override {
        std::string username1;
        std::string passwordHashed1;
        std::string permission1;
        int ngay1, thang1, nam1;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Nhap vao ten nguoi quan li: ";
        std::getline(std::cin, username1);
        std::cout << "Nhap vao mat khau: ";
        std::getline(std::cin, passwordHashed1);
        std::cout << "Quyen han cua nguoi dang nhap: ";
        std::getline(std::cin, permission1);

        // Random ngay, thang, nam
        thang1 = rand() % 12 + 1;
        if (thang1 == 2) {
            ngay1 = rand() % 28 + 1;
        }
        else if (thang1 == 4 || thang1 == 6 || thang1 == 9 || thang1 == 11) {
            ngay1 = rand() % 30 + 1;
        }
        else {
            ngay1 = rand() % 31 + 1;
        }
        nam1 = rand() % (2022 - 2018 + 1) + 2018;

        this->username = username1;
        this->passwordHashed = passwordHashed1;
        this->permission = permission1;
        this->ngay = ngay1;
        this->thang = thang1;
        this->nam = nam1;
    }

    void xuat() override {
        std::cout << "Ten cua nguoi quan li: " << this->username << std::endl;
        std::cout << "Mat khau la: " << this->passwordHashed << std::endl;
        std::cout << "Quyen truy cap cua nguoi dung khi dang nhap la: " << this->permission << std::endl;
        std::cout << "Lan dang nhap cuoi cung cua tai khoan nay la: ";
        Account::getTime();
        std::cout << std::endl;
    }

    void changePass(RegularAccount& A, std::string a) {
        A.setPass(a);
    }
};

class ManagerAccount {
    std::vector<std::shared_ptr<Account>> danhsach;

public:
    void add(std::shared_ptr<Account> s) {
        danhsach.push_back(s);
    }

    void xuat1thang(int thang, int ngay) {
        std::cout << "----------Cac tai khoan truy cap trong 1 thang gan nhat----------\n";
        for (const auto& account : danhsach) {
            if ((account->getThang() == thang && account->getNgay() < ngay) || (account->getThang() == thang - 1 && account->getNgay() > ngay)) {
                account->xuat();
            }
        }
    }

    void change(AdminAccount& s, RegularAccount& q, std::string newpass) {
        s.changePass(q, newpass);
    }

    void xuat() {
        std::cout << "----------Cac tai khoan da truy cap----------\n";
        for (const auto& account : danhsach) {
            account->xuat();
        }
    }
};

int main() {
    ManagerAccount manager;
    int d, m, y;
    std::cout << "Hay nhap vao thoi gian cua hom nay: ";
    std::cin >> d >> m >> y;

    srand(static_cast<unsigned>(time(0))); // Seed random number generator

    for (int i = 0; i < 3; i++) {
        std::cout << "1. Admin Account\n2. Regular Account\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::shared_ptr<Account> adminAccount = std::make_shared<AdminAccount>();
            adminAccount->nhap();
            manager.add(adminAccount);
        }
        else if (choice == 2) {
            std::shared_ptr<Account> regularAccount = std::make_shared<RegularAccount>();
            regularAccount->nhap();
            manager.add(regularAccount);
        }
    }

    manager.xuat();
    manager.xuat1thang(m, d);
    std::cout << "Thay doi mat khau:\n";
std::cout << "Nhap vao ten tai khoan can thay doi mat khau: ";
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
std::string accountName;
std::getline(std::cin, accountName);

bool foundAccount = false;
for (const auto& account : manager.danhsach) {
    if (account->getUsername() == accountName) {
        std::cout << "Nhap vao mat khau moi: ";
        std::string newPassword;
        std::getline(std::cin, newPassword);
        manager.change(*dynamic_cast<AdminAccount*>(manager.danhsach[0]), *dynamic_cast<RegularAccount*>(account), newPassword);
        foundAccount = true;
        break;
    }
}

if (!foundAccount) {
    std::cout << "Khong tim thay tai khoan co ten nguoi dung nhu vay.\n";
}


    return 0;
}
