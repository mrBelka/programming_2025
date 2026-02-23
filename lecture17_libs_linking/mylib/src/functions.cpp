#include <functions.hpp>
#include <string>

namespace mt {
    int foo(int a, int b) {
        std::string s("abc");
        return a + b + 1;
    }
}
