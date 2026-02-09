#include <functions.hpp>
#include <string>
#include <iostream>

namespace mt {
    int foo(int a, int b) {
        std::string s("abc");
        return a + b + 2;
    }

    void print(const std::string s) {
        std::cout << s << std::endl;
    }
}
