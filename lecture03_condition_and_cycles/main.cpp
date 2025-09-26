#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <numbers>
#include <limits>
#include <bitset>
#include <iomanip>
int main() {
    // float 3.1415923728478247
    // double 3.1415923728478247
    // 1 | 8 | 23
    // 12345.6
    // 
    //const double PI = acos(-1);
    /*double r;
    std::cin >> r;
    double S = std::numbers::pi*r*r;
    std::cout << S << std::endl;*/

    //std::cout << INT_MAX << std::endl;
    // std::cout << std::numeric_limits<int>::max() << std::endl;
    
    /*// битовый сдвиг
    int x = 0b0010;
    int y = (x << 1); // x*2^1
    // 0b0100;
    int x1 = 0b0011; // -> 0b0001
    std::cout << (x1 >> 1) << std::endl;

    // битовое &
    int a = 0b0010;
    int b = 0b1110;
    // 0b0010;
    std::cout << (a & b) << std::endl;
    int c = 11;
    // 0b1011
    // 0b0001
    std::cout << (c & 1) << std::endl;
    // битовое |
    int a = 0b0010;
    int b = 0b1110;
    // 0b1110;
    // битовая инверсия
    int d = 0b1010;
    std::cout << ~d << std::endl; // 0b0101
    // битовый xor (^)
    int a = 0b0110;
    int b = 0b1010;
    // 0b1100*/

    /*// 0b'0000'0000;
    char lamp_status = 0b0000'0000;
    // 0b00000010
    int i = 5;
    std::cout << (lamp_status | (1<<i)) << std::endl;
    // 0b00000001 = 1
    // 0b00000010 = (1<<1)
    // 0b00000000 | 0b00000010

    lamp_status = 0b00101010;
    i = 3;
    std::cout << (lamp_status & ~(1 << i));
    // 0b00000001 = 1
    // 0b00001000 = (1<<i)
    // 0b11110111 = ~(1<<i)
    // 0b00101010*/

    /*int x = 11;
    bool isEven = x % 2;
    std::cout << isEven << std::endl; 

    // Логические операторы
    // ==, !=, !, <, >, <=, >=
    int a = 10;
    int b = 11;
    std::cout << (a < b) << std::endl;
    std::cout << ((a < b) && (b % 2 == 0)) << std::endl;
    // && - логическое И
    // || - логическое ИЛИ
    // ! - логическое НЕ*/

    /*int x = 10;
    bool f = ((x++) || (x == 10));
    // short-curcuit evaluation
    std::cout << x << std::endl;*/

    /*int x = 11;
    bool isEven = (x % 2 == 0);
    if (isEven) {
        if(x == 13) {
            std::cout << "Even" << std::endl;
        }
        else {

        }
    }
    else if (x == 12){
        std::cout << "X == 12" << std::endl;
    }
    else {
        std::cout << "abc" << std::endl;
    }*/

    /*int monthNumber = 0;
    switch(monthNumber) {
        case 0: break;
        case 1: std::cout << "February"; break;
        
        default: std::cout << "Unknown month";
    }

    // Тернарный
    int x = 11;
    std::cout << (x % 2 == 0 ? "Even" : "Odd");
    */

    int x = 10;
    // std::bitset
    // std::bitset<32> b2 = x;
    std::cout << std::hex << x << std::endl;
    printf("%02hhX", x);
    printf("%2.7f", std::numbers::pi);


    return 0;
}