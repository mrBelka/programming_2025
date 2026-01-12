#pragma once

namespace mt {
class Car {
public:
    Car(int n);
    ~Car();
    Car(int x, int y, float r);

    // Метод
    void move();

    // сеттер
    void set_r(float r);

    int get_x() const;
private:
    bool is_radius_valid_(float r);
private:
    int x_ = 10; // Поле
    int y_ = 20;
    float r_ = 1.5f;
    int n_;
    int* arr_;
};
} // namespace mt