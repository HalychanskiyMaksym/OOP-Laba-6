#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <windows.h>

using namespace std;

// ----------- ������� ���� -----------
class Person {
protected:
    string name;
    int age;
public:
    Person() : name("��������"), age(0) {
        cout << "[Person] ��������\n";
    }
    Person(string n, int a) : name(n), age(a) {
        cout << "[Person] �������� � ������\n";
    }
    virtual ~Person() {
        cout << "[Person] �������\n";
    }
    virtual void input() {
        cout << "������ ��'�: ";
        cin >> name;
        cout << "������ ��: ";
        cin >> age;
    }
    virtual void randomData() {
        name = "����������";
        age = rand() % 50 + 18;
    }
    virtual void show() const {
        cout << "��'�: " << name << ", ³�: " << age << endl;
    }
};

// ----------- ���� ������� -----------
class Student : virtual public Person {
protected:
    string university;
    int year;
public:
    Student() : university("�������� ���"), year(1) {
        cout << "[Student] ��������\n";
    }
    ~Student() override {
        cout << "[Student] �������\n";
    }
    void input() override {
        Person::input();
        cout << "������ ����� �����������: ";
        cin >> university;
        cout << "������ ����: ";
        cin >> year;
    }
    void randomData() override {
        Person::randomData();
        university = "���������";
        year = rand() % 5 + 1;
    }
    void show() const override {
        Person::show();
        cout << "����������: " << university << ", ����: " << year << endl;
    }
};

// ----------- ���� ������ -----------
class Father : virtual public Person {
protected:
    int children;
    string job;
public:
    Father() : children(0), job("����������") {
        cout << "[Father] ��������\n";
    }
    ~Father() override {
        cout << "[Father] �������\n";
    }
    void input() override {
        Person::input();
        cout << "������ ������� ����: ";
        cin >> children;
        cout << "������ �������: ";
        cin >> job;
    }
    void randomData() override {
        Person::randomData();
        children = rand() % 5;
        job = "�������";
    }
    void show() const override {
        Person::show();
        cout << "ʳ������ ����: " << children << ", �������: " << job << endl;
    }
};

// ----------- �������-������ -----------
class StudentFather : public Student, public Father {
public:
    StudentFather() {
        cout << "[StudentFather] ��������\n";
    }
    ~StudentFather() override {
        cout << "[StudentFather] �������\n";
    }
    void input() override {
        Person::input();
        cout << "������ ����������: ";
        cin >> university;
        cout << "������ ����: ";
        cin >> year;
        cout << "������ ������� ����: ";
        cin >> children;
        cout << "������ �������: ";
        cin >> job;
    }
    void randomData() override {
        Person::randomData();
        university = "��������";
        year = rand() % 5 + 1;
        children = rand() % 4;
        job = "��������";
    }
    void show() const override {
        Person::show();
        cout << "����������: " << university << ", ����: " << year << endl;
        cout << "ʳ������ ����: " << children << ", �������: " << job << endl;
    }

    friend ostream& operator<<(ostream& out, const StudentFather& sf) {
        out << sf.name << " " << sf.age << " "
            << sf.university << " " << sf.year << " "
            << sf.children << " " << sf.job;
        return out;
    }

    friend istream& operator>>(istream& in, StudentFather& sf) {
        in >> sf.name >> sf.age >> sf.university >> sf.year >> sf.children >> sf.job;
        return in;
    }
};

// ----------- ������� ������� -----------
int main() {
    setlocale(LC_ALL, "ukr");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    srand(time(nullptr));

    StudentFather sf1, sf2, sf3;

    cout << "\n--- �������� � ��������� ---\n";
    sf1.input();
    sf1.show();

    cout << "\n--- �������� ��� ---\n";
    sf2.randomData();
    sf2.show();
�
    cout << "\n--- ���������� � ����� ---\n";
    ifstream fin("C:/Users/Maks/Desktop/Laba2/task3.txt");
    if (fin) {
        fin >> sf3;
        sf3.show();
    } else {
        cout << "�� ������� ������� ����\n";
    }

    return 0;
}
