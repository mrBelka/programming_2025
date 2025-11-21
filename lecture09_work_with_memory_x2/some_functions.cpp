#include "some_functions.hpp"
#include <iostream>

namespace mt::some_func {
int n = 10;

/*
int get_n() {
    return n;
}

void set_n(int n_) {
    n = n_;
}
*/

void foo() {
  std::cerr << "Hello " << std::endl;
}

void bar() {
    // ...
}
}