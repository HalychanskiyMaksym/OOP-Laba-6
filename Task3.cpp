#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <windows.h>

using namespace std;

// ----------- Базовий клас -----------
class Person {
protected:
    string name;
    int age;
public:
    Person() : name("Невідомий"), age(0) {
        cout << "[Person] Створено\n";
    }
    Person(string n, int a) : name(n), age(a) {
        cout << "[Person] Створено з даними\n";
    }
    virtual ~Person() {
        cout << "[Person] Знищено\n";
    }
    virtual void input() {
        cout << "Введіть ім'я: ";
        cin >> name;
        cout << "Введіть вік: ";
        cin >> age;
    }
    virtual void randomData() {
        name = "Випадковий";
        age = rand() % 50 + 18;
    }
    virtual void show() const {
        cout << "Ім'я: " << name << ", Вік: " << age << endl;
    }
};

// ----------- Клас Студент -----------
class Student : virtual public Person {
protected:
    string university;
    int year;
public:
    Student() : university("Невідомий ВНЗ"), year(1) {
        cout << "[Student] Створено\n";
    }
    ~Student() override {
        cout << "[Student] Знищено\n";
    }
    void input() override {
        Person::input();
        cout << "Введіть назву університету: ";
        cin >> university;
        cout << "Введіть курс: ";
        cin >> year;
    }
    void randomData() override {
        Person::randomData();
        university = "УкрПолітех";
        year = rand() % 5 + 1;
    }
    void show() const override {
        Person::show();
        cout << "Університет: " << university << ", Курс: " << year << endl;
    }
};

// ----------- Клас Батько -----------
class Father : virtual public Person {
protected:
    int children;
    string job;
public:
    Father() : children(0), job("Безробітний") {
        cout << "[Father] Створено\n";
    }
    ~Father() override {
        cout << "[Father] Знищено\n";
    }
    void input() override {
        Person::input();
        cout << "Введіть кількість дітей: ";
        cin >> children;
        cout << "Введіть професію: ";
        cin >> job;
    }
    void randomData() override {
        Person::randomData();
        children = rand() % 5;
        job = "Інженер";
    }
    void show() const override {
        Person::show();
        cout << "Кількість дітей: " << children << ", Професія: " << job << endl;
    }
};

// ----------- Студент-Батько -----------
class StudentFather : public Student, public Father {
public:
    StudentFather() {
        cout << "[StudentFather] Створено\n";
    }
    ~StudentFather() override {
        cout << "[StudentFather] Знищено\n";
    }
    void input() override {
        Person::input();
        cout << "Введіть університет: ";
        cin >> university;
        cout << "Введіть курс: ";
        cin >> year;
        cout << "Введіть кількість дітей: ";
        cin >> children;
        cout << "Введіть професію: ";
        cin >> job;
    }
    void randomData() override {
        Person::randomData();
        university = "НацТехУн";
        year = rand() % 5 + 1;
        children = rand() % 4;
        job = "Фрілансер";
    }
    void show() const override {
        Person::show();
        cout << "Університет: " << university << ", Курс: " << year << endl;
        cout << "Кількість дітей: " << children << ", Професія: " << job << endl;
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

// ----------- Основна функція -----------
int main() {
    setlocale(LC_ALL, "ukr");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    srand(time(nullptr));

    StudentFather sf1, sf2, sf3;

    cout << "\n--- Введення з клавіатури ---\n";
    sf1.input();
    sf1.show();

    cout << "\n--- Випадкові дані ---\n";
    sf2.randomData();
    sf2.show();
а
    cout << "\n--- Зчитування з файлу ---\n";
    ifstream fin("C:/Users/Maks/Desktop/Laba2/task3.txt");
    if (fin) {
        fin >> sf3;
        sf3.show();
    } else {
        cout << "Не вдалося відкрити файл\n";
    }

    return 0;
}
