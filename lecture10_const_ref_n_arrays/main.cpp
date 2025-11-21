#include <iostream>
#include <vector>

/*void foo(const int n) {
    n = 10;
}*/

/*void bar(int* x) {
    *x = 15;
}*/

void foo(const int& x) {
    int& changeable_x = const_cast<int&>(x);
    changeable_x = 15;
}

// array-to-pointer cast
void bar(int* arr2) {
    *arr2 = 0;
}

int* read() {
    int arr[20];
    arr[0] = 123;
    return arr;
}

std::vector<int> write(std::vector<int>& vec) {

}

int main() {
    /*const int N = 10;
    const double Pi = 3.141592;

    const int x = 10;
    const int* px = &x; // указатель на константу

    int y = 11;
    int* const py = &y; // константный указатель
    py += 1;
    *py = 12;

    const int* const pz = &x; // константный указатель на константу
    pz += 1;
    *pz = 13;*/

    /*int x = 10;
    int* px = &x;
    bar(&x);
    std::cout << x << std::endl;*/

    /*const int x = 10;
    const int& rx = x; // ссылка на константу, говорят - константная ссылка
    //rx = 13;
    int y = 15;

    int num_of_even_digit_in_big_number_with_million_zeros = 10;
    int& r = num_of_even_digit_in_big_number_with_million_zeros;

    int result = r*r;

    //foo(x);*/

    /*int x = 10;
    foo(x);
    std::cerr << x << std::endl;*/

    /*// Массив фиксированной длины
    int arr[20] = {1,2,3,4,5,6};        // стек
    std::cout << *(arr+0) << std::endl; // arr[0]
    std::cout << *(arr+1) << std::endl; // arr[1]
    std::cout << *(arr+2) << std::endl;
    std::cout << sizeof(arr) << std::endl;
    bar(arr);
    std::cout << *(arr+0) << std::endl; 

    // Динамический массив
    int* arr_dyn = new int[20];
    *(arr_dyn+1) = 0; // arr_dyn[1] = 0;
    bar(arr_dyn);
    delete[] arr_dyn;

    int arr3[20];
    read(arr3);
    std::cout << arr3[0] << std::endl;*/

    // Вектор (динамический массив)

    using ArrOfDigits = std::vector<int>;

    ArrOfDigits vec(100'000); // стек 24/32 байта, хип
    vec.resize(100'000);
    vec[1] = 10;
    vec[2] = 12;
    vec[99'999] = 99'999;

    vec.reserve(100'000);

    vec.push_back(21);
    vec.push_back(22);



    int i = 1000; // 232 3 0 0
    double d = static_cast<double>(i);

    int* p = &i;
    unsigned char* pc = reinterpret_cast<unsigned char*>(p);



}