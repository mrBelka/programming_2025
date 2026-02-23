#include <functions.hpp>
#include <iostream>

int main() {
  mt::BigInt a("123");
  mt::BigInt b("789");
  mt::BigInt c = a + b;

  if (a != b) {

  }

  c[2] = '1';

  mt::BigInt* ptr_c = std::addressof(c);

  std::cout << c << std::endl;
} 