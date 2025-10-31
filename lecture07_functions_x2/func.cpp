#include "func.hpp"
#include <cmath>

namespace mt {

    bool isPrime(int x) {
        if(x < 2) {
            return false;
        }
        for(int d = 2; d <= sqrt(x); ++d) {
            if(x % d == 0) {
                return false;
            }
        }
        return true;
    }

} // mt