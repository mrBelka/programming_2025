#include <functions.hpp>

__declspec(dllexport) int foo(int a, int b) {
    return 11 + a + b;
}
