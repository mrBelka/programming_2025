#include <iostream>
#include "func.hpp"

int main() {
    std::cout << SumOfDigits(123);
}

/*#include <iostream>

int MultOfDigit(int x) {
    int mult = 1;
    while(x>0){
        mult = mult * (x % 10);
        x /= 10;
    }
    return mult;
}

bool isPrime(int x) {

}

int main() {
    const int NMax = 20000;
    int arr[NMax];

    // Ввод
    int n;
    std::cin >> n;
    // Проверка (optional)
    if(n < 1 || n > NMax) {
        std::cout << "Incorrect input" << std::endl;
        return -1;
    }

    // Ввод
    for(int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Обработка
    // Удаление
    int i = 0;
    int j = 0;
    while(i<n) {
        if(MultOfDigit(arr[i]) % 70 != 0) {
            arr[j] = arr[i];
            ++i;
            ++j;
        }
        else {
            ++i;
        }
    }
    n = j;

    // Продублировать простые числа


    // Вывод
    for(int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

}*/


/*#include <iostream>
#include <limits>
// Стадии сборки:
// 1. Препроцессинг
// 2. Ассемблирование
// 3. Компиляция -> main.cpp.o
// 4. Линковка


// Заголовок функции (сигнатура)
// 1. тип возвращаемого значения - void (int, float, char)
// 2. название Read
// 3. аргументы
// Тело функции {}

// Declaration - объявление
void Read(int n, int arr[]);

int FindMax(int n, int arr[]) {
    int max = std::numeric_limits<int>::min();
    for(int i = 0; i < n; ++i) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void ChangeMax(int n, int arr[], int max, int change) {
    for(int i = 0; i < n; ++i) {
        if(arr[i] == max) {
            arr[i] = change;
        }
    }
}

void Write(int n, int arr[]) {
    for(int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
}

void Swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int SumOfDigits(int number) {
    int sum = 0;
    while(number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    const int NMax = 3;
    const int CHANGE = 777;

    int a = 10;
    int b = 5;

    std::cout << SumOfDigits(a);

    Swap(a, b);

    int arr[NMax];
    // 1. Ввод
    Read(NMax, arr); // 

    // 2. Поиск максимума
    int max = FindMax(NMax, arr); // где находится тело функции

    // 3. Замена на CHANGE
    ChangeMax(NMax, arr, max, CHANGE);

    std::cout << "max = " << max << std::endl;

    // 4. Вывод
    Write(NMax, arr);
}*/

// Definition - определение
/*void Read(int n, int arr[]) {
    for(int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
}*/
