// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №6. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

//#include <iostream>

// Ваші файли загловки 
//
//#include "Lab6Example.h"
//int main()
//{
    //std::cout << " Lab #6  !\n";
    //  Код виконання завдань
    //  Головне меню завдань
    //  Функції та класи можуть знаходитись в інших файлах проекту

  //  Example();

//}

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// класс А
class A {
public:
    int a;
    char b;
};

// класс B с не віртуальним наследованием от A
class B : public A {
public:
    float c;
};

// класс F
class F {
public:
    double d;
};

// класс H с не віртуальним наследованием от F
class H : public F {
public:
    bool e;
};

// класс C с віртуальним наследованием от A и F
class C : public A, virtual public F {
public:
    long long f;
};

// класс D с не віртуальним наследованием от A, B, C
class D : public A, public B, public C {
public:
    short g;
};

int option1() {
    A a;
    B b;
    C c;
    D d;
    F f;
    H h;

    cout << "Size of object a: " << sizeof(a) << endl;
    cout << "Size of object b: " << sizeof(b) << endl;
    cout << "Size of object c: " << sizeof(c) << endl;
    cout << "Size of object d: " << sizeof(d) << endl;
    cout << "Size of object f: " << sizeof(f) << endl;
    cout << "Size of object h: " << sizeof(h) << endl;

    return 0;
}

//2
class Progression {
public:
    virtual double sum(int n) = 0;
};

class ArithmeticProgression : public Progression {
public:
    ArithmeticProgression(double a0, double d) : m_a0(a0), m_d(d) {}
    double sum(int n) override {
        return (n + 1) * (2 * m_a0 + (n - 1) * m_d) / 2;
    }
private:
    double m_a0;
    double m_d;
};

class GeometricProgression : public Progression {
public:
    GeometricProgression(double a0, double r) : m_a0(a0), m_r(r) {}
    double sum(int n) override {
        return (m_a0 - pow(m_r, n) * m_a0) / (1 - m_r);
    }
private:
    double m_a0;
    double m_r;
};

int option2() {
    Progression* ap = new ArithmeticProgression(1.0, 2.0);
    Progression* gp = new GeometricProgression(1.0, 0.5);

    std::cout << "Arithmetic Progression sum(10): " << ap->sum(10) << std::endl;
    std::cout << "Geometric Progression sum(10): " << gp->sum(10) << std::endl;

    delete ap;
    delete gp;

    return 0;
}


//3

class File {
protected:
    std::string m_name;
    int m_size;

public:
    File(const std::string& name = "", int size = 0)
        : m_name(name), m_size(size)
    {
    }

    virtual ~File() {}

    virtual void printInfo() const
    {
        std::cout << "File name: " << m_name << ", size: " << m_size << " bytes" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const File& file);
    friend std::istream& operator>>(std::istream& is, File& file);
};

std::ostream& operator<<(std::ostream& os, const File& file)
{
    os << file.m_name << " " << file.m_size;
    return os;
}

std::istream& operator>>(std::istream& is, File& file)
{
    is >> file.m_name >> file.m_size;
    return is;
}

class ReadFile : virtual public File {
public:
    ReadFile(const std::string& name = "", int size = 0)
        : File(name, size)
    {
    }

    virtual ~ReadFile() {}

    virtual void printInfo() const
    {
        std::cout << "Read file name: " << m_name << ", size: " << m_size << " bytes" << std::endl;
    }
};

class WriteFile : virtual public File {
public:
    WriteFile(const std::string& name = "", int size = 0)
        : File(name, size)
    {
    }

    virtual ~WriteFile() {}

    virtual void printInfo() const
    {
        std::cout << "Write file name: " << m_name << ", size: " << m_size << " bytes" << std::endl;
    }
};

class ReadWriteFile : public ReadFile, public WriteFile {
public:
    ReadWriteFile(const std::string& name = "", int size = 0)
        : File(name, size), ReadFile(name, size), WriteFile(name, size)
    {
    }

    virtual ~ReadWriteFile() {}

    virtual void printInfo() const
    {
        std::cout << "Read/Write file name: " << m_name << ", size: " << m_size << " bytes" << std::endl;
    }
};

int option3()
{
    File file("document.txt", 1024);
    ReadFile rFile("readme.txt", 512);
    WriteFile wFile("output.txt", 2048);
    ReadWriteFile rwFile("data.bin", 4096);

    std::cout << "File: " << file << std::endl;
    std::cout << "Read file: " << rFile << std::endl;
    std::cout << "Write file: " << wFile << std::endl;
    std::cout << "Read/Write file: " << rwFile << std::endl;

    std::cout << std::endl;

    file.printInfo();
    rFile.printInfo();
    wFile.printInfo();
    rwFile.printInfo();

    return 0;
}

void showMenu() {
    cout << "=== Menu ===" << endl;
    cout << "1. Task 1" << endl;
    cout << "2. Task 2" << endl;
    cout << "3. Task 3" << endl;
    cout << "4. Exit" << endl;
    cout << "============" << endl;
    cout << "Chose option: ";
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Task 1" << endl;
            option1();
            break;
        case 2:
            cout << "Task 2" << endl;
            option2();
            break;
        case 3:
            cout << "Task 3" << endl;
            option3();
            break;
        case 4:
            cout << "Good bye!" << endl;
            break;
        default:
            cout << "Incorrect choice. Please repeat the request." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
