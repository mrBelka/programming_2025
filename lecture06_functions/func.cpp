#include "func.hpp"

int SumOfDigits(int x) {
    int sum = 0;
    while(x>0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}