#include <iostream>
#include <Windows.h>
#include <io.h>    // For _setmode and _O_BINARY
#include <fcntl.h> // For _setmode and _O_BINARY

int main() {
    
    /*
    int x = 2; // 32 бита, 0b0000...0010
    x += 1;
    x -= 1;

    x & (1 << 3)

    // (1<<3) = 1*2^3 = 8 (10) = 0b0000...1000
    // & 0b0000...0010
    //   0b0000...1000
    //   0b0000...0000 == 0 == false
    */
    /*
    int i = 1; // iterator, index (переменная-счетчик)
    while ((i <= 10) && (i % 2 == 0)) { // проверка условия
        std::cout << i << " ";
        ++i; // инкремент счетчика
    } // в фигурных скобках - тело цикла
    std::cout << "end" << std::endl;
    */
    /*
    int i = 2;
    while (true) {
        if (i > 10)
            break;
        std::cout << i << " ";
        i += 2;
    }
    std::cout << "end" << std::endl;
    */
    /*
    int i = 1;
    while (i <= 10) {
        if (i % 2 != 0) {
            ++i;
            continue;
        }
        std::cout << i << " ";
        ++i;
    }
    std::cout << "end" << std::endl;
    */
    /*
    for (int i = 1; i <= 10; ++i) {
        if (i % 2 != 0) {
            continue;
        }
        std::cout << i << " ";
    }
    std::cout << "end" << std::endl;
    */
    /*
    for (int i = 2; i <= 10; i+=2) {
        std::cout << i << " ";
    }
    std::cout << "end" << std::endl;
    */
    /*
    for(int i = 0;;++i) {
        std::cout << i << " ";
    }
    */
    /*
    int x = 0;
    do {
        std::cin >> x;
    } while(x % 2 == 0);
    std::cout << "end" << std::endl;
    */
    /*
    // Определение простоты числа
    // 121
    // 2 3 4 5 6 7 8 9 10 11 12 . . . 42
    // 63 42 . . . . . . . . . .. . . .3
    bool isPrime = true;
    int x = 1;
    if (x < 2) {
        std::cout << "is not prime" << std::endl;
    }
    else {
        for (int d = 2; d <= sqrt(x); ++d) {
            if (x % d == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            std::cout << "is prime" << std::endl;
        }
        else {
            std::cout << "is not prime" << std::endl;
        }
    }*/

    _setmode(_fileno(stdin), _O_BINARY);
    char ch;
    std::cin.read(&ch, 1); // '1' == 49
    std::cout << ch + 10 << std::endl;

    short s;
    std::cin >> s;
    char c = s;
    return 0;
}