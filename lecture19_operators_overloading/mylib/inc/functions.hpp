#pragma once
#include <string>
#include <iostream>

namespace mt {
int foo(int a, int b);
void print(const std::string s);

class BigInt {
public:
    explicit BigInt(const std::string& value) : value_(value) {
        for (int i = 0; i < value_.size() / 2; ++i) {
            std::swap(value_[i], value_[value_.size() - i - 1]);
        }
    }

    BigInt operator+(const BigInt& other) {
        // BAD REALIZATION
        std::string result;
        int carry = 0;
        for (int i = 0; i < value_.size(); ++i) {
            int tmp = (value_[i] - 48 + other.value_[i] - 48);
            if (tmp > 9) {
                carry = 1;
            }
            result += tmp % 10 + carry + 48;
            carry = 0;
        }
        return BigInt(result);
    }

    BigInt add(const BigInt& other) {
        // BAD REALIZATION
        std::string result;
        int carry = 0;
        for (int i = 0; i < value_.size(); ++i) {
            int tmp = (value_[i] - 48 + other.value_[i] - 48);
            if (tmp > 9) {
                carry = 1;
            }
            result += tmp % 10 + carry + 48;
            carry = 0;
        }
        return BigInt(result);
    }

    void print() {
        std::cout << value_ << std::endl;
    }

    std::string get() {
        return value_;
    }

    BigInt& operator++()
    {
        value_[0] += 1;
        // TODO
        return *this; // return new value by reference
    }

    BigInt operator++(int)
    {
        BigInt old = *this; // copy old value
        operator++();  // prefix increment
        return old;    // return old value
    }

private:
    std::string value_;
};
}
