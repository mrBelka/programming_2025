#include <functions.hpp>
#include <string>
#include <iostream>

namespace mt {
    std::ostream& operator<<(std::ostream& out, const BigInt& x) {
        std::string out_value;
        for (int i = x.value_.size() - 1; i >= 0; --i) {
            out_value += x.value_[i]; 
        }
        out << out_value; // TODO -> friend
        return out;
    }

    BigInt BigInt::operator+(const BigInt& other) {
        BigInt result = *this;
        result += other;
        return result;
    }

    int foo(int a, int b) {
        std::string s("abc");
        return a + b + 2;
    }

    void print(const std::string s) {
        std::cout << s << std::endl;
    }
}
