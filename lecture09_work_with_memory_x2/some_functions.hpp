#pragma once

// ODR = One Definition Rule

namespace mt::some_func {

extern int n;

//int get_n();
//void set_n(int n_);
void foo();
void bar();
}