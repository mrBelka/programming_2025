#pragma once
#include <string>
#include <iostream>

namespace mt {
int foo(int a, int b);
void print(const std::string s);

class BigInt {
public:
    // "123"
    explicit BigInt(const std::string& value) : value_(value) {
        // "123" -> "321"
        for (int i = 0; i < value_.size() / 2; ++i) {
            std::swap(value_[i], value_[value_.size() - i - 1]);
        }
    }
    BigInt(const BigInt& other) = default;
    BigInt& operator=(const BigInt& other) = default;
    ~BigInt() = default;

    char& operator[](size_t index) {
        return value_[index];
    }

    char& operator()(size_t i) {
        return value_[i];
    }

    char at(size_t index) {
        if (index < 0 || index >= value_.size()) {
            throw std::invalid_argument("....");
        }
        return value_[index];
    }

    // c = a + b;
    // Return value optimization
    BigInt operator+(const BigInt& other);

    BigInt operator-() const {

    }

    BigInt& operator+=(const BigInt& other) {
        // BAD REALIZATION
        int carry = 0;
        for (int i = 0; i < value_.size(); ++i) {
            int tmp = (value_[i] - '0' + other.value_[i] - '0');
            value_[i] = tmp % 10 + carry + '0';
            carry = tmp > 9 ? 1 : 0;
        }
        return *this;
    }

    bool operator==(const BigInt& other) {
        if (value_.size() != other.value_.size()) {
            return false;
        }
        for (size_t i = 0; i < value_.size(); i++) {
            if (value_[i] != other.value_[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const BigInt& other) {
        return !(*this == other);
    }

    bool operator<(const BigInt& other) {

    }

    bool operator>(const BigInt& other) {
        return !(*this < other || *this == other);
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

    friend std::ostream& operator<<(std::ostream& out, const BigInt& x);

private:
    std::string value_;
};

std::ostream& operator<<(std::ostream& out, const BigInt& x);

}
