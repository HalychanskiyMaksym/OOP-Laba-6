#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ===== Базовий клас без virtual inheritance =====
class Base {
protected:
    int baseData;
public:
    Base() {
        baseData = rand() % 100;
        cout << "[Base] Created with baseData = " << baseData << endl;
    }
    virtual ~Base() {
        cout << "[Base] Destroyed" << endl;
    }
    virtual void show() const {
        cout << "[Base] baseData = " << baseData << endl;
    }
    void setFromKeyboard() {
        cout << "Enter baseData: ";
        cin >> baseData;
    }
    void setFromFile(ifstream &fin) {
        fin >> baseData;
    }
};

class Left1 : public Base {
protected:
    int left1Data;
public:
    Left1() {
        left1Data = rand() % 100;
        cout << "[Left1] Created with left1Data = " << left1Data << endl;
    }
    ~Left1() {
        cout << "[Left1] Destroyed" << endl;
    }
    void show() const override {
        Base::show();
        cout << "[Left1] left1Data = " << left1Data << endl;
    }
    void setFromKeyboard() {
        Base::setFromKeyboard();
        cout << "Enter left1Data: ";
        cin >> left1Data;
    }
    void setFromFile(ifstream &fin) {
        Base::setFromFile(fin);
        fin >> left1Data;
    }
};

class Right1 : public Base {
protected:
    int right1Data;
public:
    Right1() {
        right1Data = rand() % 100;
        cout << "[Right1] Created with right1Data = " << right1Data << endl;
    }
    ~Right1() {
        cout << "[Right1] Destroyed" << endl;
    }
    void show() const override {
        Base::show();
        cout << "[Right1] right1Data = " << right1Data << endl;
    }
    void setFromKeyboard() {
        Base::setFromKeyboard();
        cout << "Enter right1Data: ";
        cin >> right1Data;
    }
    void setFromFile(ifstream &fin) {
        Base::setFromFile(fin);
        fin >> right1Data;
    }
};

class TopNoVirtual : public Left1, public Right1 {
    int topData;
public:
    TopNoVirtual() {
        topData = rand() % 100;
        cout << "[TopNoVirtual] Created with topData = " << topData << endl;
    }
    ~TopNoVirtual() {
        cout << "[TopNoVirtual] Destroyed" << endl;
    }
    void show() const {
        cout << "\n=== Дані з лівої гілки ===\n";
        Left1::show();
        cout << "\n=== Дані з правої гілки ===\n";
        Right1::show();
        cout << "[TopNoVirtual] topData = " << topData << endl;
    }
    void setFromKeyboard() {
        cout << "\n--- Введення Left1 ---\n";
        Left1::setFromKeyboard();
        cout << "\n--- Введення Right1 ---\n";
        Right1::setFromKeyboard();
        cout << "Enter topData: ";
        cin >> topData;
    }
    void setFromFile(ifstream &fin) {
        Left1::setFromFile(fin);
        Right1::setFromFile(fin);
        fin >> topData;
    }
};

// ===== Базовий клас з virtual inheritance =====
class BaseV {
protected:
    int baseDataV;
public:
    BaseV() {
        baseDataV = rand() % 100;
        cout << "[BaseV] Created with baseDataV = " << baseDataV << endl;
    }
    virtual ~BaseV() {
        cout << "[BaseV] Destroyed" << endl;
    }
    virtual void show() const {
        cout << "[BaseV] baseDataV = " << baseDataV << endl;
    }
    void setFromKeyboard() {
        cout << "Enter baseDataV: ";
        cin >> baseDataV;
    }
    void setFromFile(ifstream &fin) {
        fin >> baseDataV;
    }
};

class LeftV1 : virtual public BaseV {
protected:
    int left1DataV;
public:
    LeftV1() {
        left1DataV = rand() % 100;
        cout << "[LeftV1] Created with left1DataV = " << left1DataV << endl;
    }
    ~LeftV1() {
        cout << "[LeftV1] Destroyed" << endl;
    }
    void show() const override {
        BaseV::show();
        cout << "[LeftV1] left1DataV = " << left1DataV << endl;
    }
    void setFromKeyboard() {
        BaseV::setFromKeyboard();
        cout << "Enter left1DataV: ";
        cin >> left1DataV;
    }
    void setFromFile(ifstream &fin) {
        BaseV::setFromFile(fin);
        fin >> left1DataV;
    }
};

class RightV1 : virtual public BaseV {
protected:
    int right1DataV;
public:
    RightV1() {
        right1DataV = rand() % 100;
        cout << "[RightV1] Created with right1DataV = " << right1DataV << endl;
    }
    ~RightV1() {
        cout << "[RightV1] Destroyed" << endl;
    }
    void show() const override {
        BaseV::show();
        cout << "[RightV1] right1DataV = " << right1DataV << endl;
    }
    void setFromKeyboard() {
        BaseV::setFromKeyboard();
        cout << "Enter right1DataV: ";
        cin >> right1DataV;
    }
    void setFromFile(ifstream &fin) {
        BaseV::setFromFile(fin);
        fin >> right1DataV;
    }
};

class TopVirtual : public LeftV1, public RightV1 {
    int topDataV;
public:
    TopVirtual() {
        topDataV = rand() % 100;
        cout << "[TopVirtual] Created with topDataV = " << topDataV << endl;
    }
    ~TopVirtual() {
        cout << "[TopVirtual] Destroyed" << endl;
    }
    void show() const override {
        cout << "\n=== Virtual Inheritance Tree ===\n";
        LeftV1::show();
        RightV1::show();
        cout << "[TopVirtual] topDataV = " << topDataV << endl;
    }
    void setFromKeyboard() {
        cout << "\n--- Введення LeftV1 ---\n";
        LeftV1::setFromKeyboard();
        cout << "\n--- Введення RightV1 ---\n";
        RightV1::setFromKeyboard();
        cout << "Enter topDataV: ";
        cin >> topDataV;
    }
    void setFromFile(ifstream &fin) {
        LeftV1::setFromFile(fin);
        RightV1::setFromFile(fin);
        fin >> topDataV;
    }
};

int main() {
    srand(time(nullptr));

    // Розміри класів
    cout << "\n=== Розміри класів (без virtual) ===\n";
    cout << "sizeof(Base) = " << sizeof(Base) << " байт" << endl;
    cout << "sizeof(Left1) = " << sizeof(Left1) << " байт" << endl;
    cout << "sizeof(Right1) = " << sizeof(Right1) << " байт" << endl;
    cout << "sizeof(TopNoVirtual) = " << sizeof(TopNoVirtual) << " байт" << endl;

    cout << "\n=== Розміри класів (з virtual) ===\n";
    cout << "sizeof(BaseV) = " << sizeof(BaseV) << " байт" << endl;
    cout << "sizeof(LeftV1) = " << sizeof(LeftV1) << " байт" << endl;
    cout << "sizeof(RightV1) = " << sizeof(RightV1) << " байт" << endl;
    cout << "sizeof(TopVirtual) = " << sizeof(TopVirtual) << " байт" << endl;

    // Введення з клавіатури
    cout << "\n--- Введення TopNoVirtual з клавіатури ---\n";
    TopNoVirtual obj1;
    obj1.setFromKeyboard();
    obj1.show();

    cout << "\n--- Введення TopVirtual з клавіатури ---\n";
    TopVirtual obj2;
    obj2.setFromKeyboard();
    obj2.show();

    // Зчитування з файлу
    ifstream fin("C:/Users/Maks/Desktop/Laba2/task1.txt");
    if (fin) {
        cout << "\n--- Зчитування TopNoVirtual з файлу ---\n";
        TopNoVirtual obj3;
        obj3.setFromFile(fin);
        obj3.show();
        fin.close();
    } else {
        cout << "\nНе вдалося відкрити файл!\n";
    }

    return 0;
}