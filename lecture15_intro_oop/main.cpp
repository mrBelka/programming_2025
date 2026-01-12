#include <iostream>
#include "Car.hpp"
// 1 принцип - Абстракция
// 2 принцип - Инкапсулляция
// x, y
// struct - хранение
// class - хранение, описывает поведения

void intersect(const mt::Car& c1, const mt::Car& c2) {
    c1.get_x();
}

int main()
{
    try {
        /*Car car(100); // объект / экземпляр
        std::cerr << "===" << std::endl;
        car.set_r(1);
        std::cerr << "===" << std::endl;
        */
        mt::Car* car = new mt::Car(100);
        car->get_x(); // синтаксический сахар
        (*car).get_x(); // ->

        delete car;
    } catch(const std::invalid_argument& ex) {
        std::cerr << ex.what() << std::endl;
    } catch(const std::bad_alloc& ex) {
        std::cerr << ex.what() << std::endl;
    } catch(const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    } catch(...) {
        std::cerr << "Unhandled exception" << std::endl;
    }


    /*int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    move(x1, y1);
    move(x2, y2);*/
}