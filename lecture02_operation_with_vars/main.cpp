#include <iostream>

// Показать про русский язык
/*123456
111
222
333
*/

int main() {

    // целочисленные
    char c1; // 1 байт, 256 значение, -128..127
    unsigned char c2; // 1 байт, 256 значений, 0..255
    short s1; // 2 байта, 65536 значений, -32768..37767
    unsigned short s2; // 2 байта, 65536 значений, 0..65535
    int i1; // 4 байта, 4.147 млдр., -2^31 .. 2^31 - 1
    unsigned int i2; // 4 байта, 4.147 млдр., 0..2^32 - 1
    long long ll1; // 8 байт
    unsigned long long ull2; // 8 байт

    i1 = 10.5;
    std::cout << i1 << std::endl;

    // символьный
    char c3 = 'a';

    // вещественные
    float f = 3.141592f; // 4 байта, 6-7 значащих цифр
    double d = 3.14159211111111111; // 8байт, 15-16 значащих цифр

    float f1 = 10;

    // логический тип данных
    //bool b; // false (0)
    //bool b; // 1 байт

    // declaration - объявление
    // definition - определение

    int x = 123;

    std::cout << x << std::endl;

    int sumOfDigits; // lower camel case
    int SumOfDigits; // upper camel case
    int sum_of_digits; // snake case
    int sumofdigits;


    return 0;
}