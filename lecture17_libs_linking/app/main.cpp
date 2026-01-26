#include <functions.hpp>
#include <iostream>

int main() {
  std::cerr << mt::foo(2, 2) << std::endl;
} 

/*
// 0.000000...1
// 1e-15 = 1 * 10 ^ -15

const double EPS = 1e-6;

double get_dv(const double dS, const double dt) {

  if (fabs(dt - 0) < EPS) { ... }

  if (!(dt > EPS)) {
    std::runtime_error("[get_dv]: dt have to be positive");
  }
  const double dv = dS/dt;
  return dv;
}
*/