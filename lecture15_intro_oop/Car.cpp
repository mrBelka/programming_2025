#include "Car.hpp"
#include <iostream>
#include <exception>

namespace mt {
Car::Car(int n) : arr_(new int[n_]), n_(n) {
    std::cerr << "ctor" << std::endl;
}
Car::~Car() {
    delete[] arr_;
    std::cerr << "dtor" << std::endl;
}
Car::Car(int x, int y, float r) : x_(x), y_(y), r_(r) {
    std::cerr << "ctor param" << std::endl;
}

void Car::move() {
    x_ += 10;
    y_ += 10;
}

// сеттер
void Car::set_r(float r) {
    if (is_radius_valid_(r)) {
        return;
    }
    r_ = r;
}

int Car::get_x() const {return x_;}

bool Car::is_radius_valid_(float r) {
    if (r < 0.01) {
        throw std::invalid_argument("Radius have to be positive");
    }
}
} // namespace mt