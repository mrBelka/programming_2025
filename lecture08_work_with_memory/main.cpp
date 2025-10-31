#include <iostream>

int main() {
    // "Сырой" указатель = raw pointer
    int x = 1000;
    int y = 1;
    // x = a*256^0 + b*256^1 + c*256^2 + d*256^3
    // a = (1000 / 256^0) % 256 = 232
    // b = (1000 / 256^1) % 256 = 3
    // c = (1000 / 256^2) % 256 = 0
    // d = (1000 / 256^3) % 256 = 0

    // Указатель - переменная, хранящая адрес и тип другой переменной
    // Размер указателя - 8 байта (64-бит. система)

    int* px = &x;
    int* py = &y;

    // операция взятия адреса
    std::cout << &x << std::endl;
    std::cout << &y << std::endl;
    std::cout << &px << std::endl;
    std::cout << &py << std::endl;
    std::cout << px << std::endl;
    std::cout << py << std::endl;

    // разыменование
    std::cout << *px << std::endl;
    std::cout << *py << std::endl;

    // выделение памяти
    int* pz;
    pz = new int; // дай нам место под тип int
    *pz = 10;
    std::cout << &pz << std::endl;
    std::cout << pz << std::endl;

    /*char* pc = (char*)pz; // Memory leak
    delete pc;
    // some code
    delete pc; // double free*/

    int* ptr = new int;
    *ptr = 2;
    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;
    delete ptr;
    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;

    std::cout << "Finish" << std::endl;

    // RTTI
    // typeid
}