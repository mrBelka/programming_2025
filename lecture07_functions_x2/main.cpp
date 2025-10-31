#include <iostream>
#include "func.hpp"
#include "math.hpp"

namespace mt::math {
    
}

namespace mt {
    void print() {

    }
}

int main() {
    mt::print();
    std::cout << mt::isPrime(11) << std::endl;
    std::cout << mt::math::distance(1, 1, 0, 0) << std::endl;
}

/*

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(float& a, float& b) {
    float tmp = a;
    a = b;
    b = tmp;
}

bool foo(float x) {
    return true;
}

void foo(int x) {
    std::cout << "123" << std::endl;
}
*/
