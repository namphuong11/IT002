#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
    int ngay, thang, nam;

public:
    Person(string name, int age, int ngay,int thang,int nam) {
        this->name = name;
        this->age = age;
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
    }

    void setName(string newName) {
        name = newName;
    }

    void setAge(int newAge) {
        age = newAge;
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
    void getNtns()
    {
        cout << this->ngay << "/" << this->thang << "/" << this->nam;
    }

    virtual void displayInfo() {
        cout << "Ten: " << name << endl;
        cout << "Tuoi: " << age << endl;
        cout << "Ngay thang nam sinh: "; getNtns(); cout<<endl;
    }
};

class Student : public Person {
private:
    long long studentID;

public:
    Student(string name, int age,int ngay,int thang,int nam, long long id) : Person(name, age,ngay,thang,nam) {
        this->studentID = id;
    }

    void setID(long long id) {
        this->studentID = id;
    }

    long long getID() {
        return studentID;
    }

    void displayInfo() {
        cout<<"----Student Info----" <<endl;
        Person::displayInfo();
        cout << "Student ID: " << studentID << endl;
    }
};

class Pupil : public Person {
private:
    int grade;

public:
    Pupil(string name, int age,int ngay,int thang,int nam, int grade) : Person(name,age,ngay,thang,nam) {
        this->grade = grade;
    }

    void setGrade(int grade) {
        this->grade = grade;
    }

    int getGrade() {
        return grade;
    }

    void displayInfo() {
        cout<<"----Pupil Info----" <<endl;
        Person::displayInfo();
        cout << "Pupil grade: " << grade << endl;
    }
};

class Worker : public Person {
private:
    int workDays;

public:
    Worker(string name, int age,int ngay,int thang,int nam, int workDays) : Person(name,age,ngay,thang,nam) {
        this->workDays = workDays;
    }

    void setWorkDays(int workDays) {
        this->workDays = workDays;
    }

    int getWorkDays() {
        return workDays;
    }

    void displayInfo() {
        cout<<"----Worker Info----" <<endl;
        Person::displayInfo();
        cout << "Number of work days: " << workDays << endl;
    }
};

class Artist : public Person {
private:
    string field;

public:
    Artist(string name, int age,int ngay,int thang,int nam, string field) : Person(name,age,ngay,thang,nam) {
        this->field = field;
    }

    void setField(string field) {
        this->field = field;
    }

    string getField() {
        return field;
    }

    void displayInfo() {
        cout<<"----Artist Info----" <<endl;
        Person::displayInfo();
        cout << "Field: " << field << endl;
    }
};

class Singer : public Person {
private:
    string genre;

public:
    Singer(string name, int age,int ngay,int thang,int nam, string genre) : Person(name,age,ngay,thang,nam) {
        this->genre = genre;
    }

    void setGenre(string genre) {
        this->genre = genre;
    }

    string getGenre() {
        return genre;
    }

    void displayInfo() {
        cout<<"----Singer Info----" <<endl;
        Person::displayInfo();
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    int choice;
    Person* p[100];
    int i = 0;
    int ngay,thang,nam;

    do {
        cout << "Enter the type of person: " << endl;
        cout << "1. Student" << endl;
        cout << "2. Pupil" << endl;
        cout << "3. Worker" << endl;
        cout << "4. Artist" << endl;
        cout << "5. Singer" << endl;
        cout << "0. Quit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int age;
                long long studentID;

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
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
                cout << "Enter student ID: ";
                cin >> studentID;

                Student* s = new Student(name, age,ngay,thang,nam ,studentID);
                p[i] = s;
                i++;
                break;
            }
            case 2: {
                string name;
                int age, grade;

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
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
                cout << "Enter grade: ";
                cin >> grade;

                Pupil* pupil = new Pupil(name, age,ngay,thang,nam, grade);
                p[i] = pupil;
                i++;
                break;
            }
            case 3: {
                string name;
                int age, workDays;

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
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
                cout << "Enter number of work days: ";
                cin >> workDays;

                Worker* worker = new Worker(name, age,ngay,thang,nam, workDays);
                p[i] = worker;
                i++;
                break;
            }
            case 4: {
                string name, field;
                int age;

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
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
                cout << "Enter art field: ";
                cin.ignore();
                getline(cin, field);

                Artist* artist = new Artist(name, age,ngay,thang,nam, field);
                p[i] = artist;
                i++;
                break;
            }
            case 5: {
                string name, genre;
                int age;

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
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
                cout << "Enter genre: ";
                cin.ignore();
                getline(cin, genre);

                Singer* singer = new Singer(name, age,ngay,thang,nam, genre);
                p[i] = singer;
                i++;
                break;
            }
            case 0: {
                cout << "Thanks for using the application" << endl;
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    for (int j = 0; j < i; j++) {
        p[j]->displayInfo();
    }

    for (int j = 0; j < i; j++) {
        delete p[j];
    }

    return 0;
}
