#include <iostream>
#include <vector>
#include <algorithm>

void QuickSort(int a, int b, int* arr) {
    if(a>=b)
        return;
    // Выбор опорного элемента
    // 142 % 6 = 4
    // int k = (a + b) / 2;
    // медиана трех
    int k = (rand()*rand()) % (b-a+1) + a;
    int m = arr[k];
    // Пресорт
    int l = a - 1;
    int r = b + 1;
    while(true) {
        do l++; while(arr[l] < m);
        do r--; while(arr[r] > m);
        if(l >= r) 
            break;
        std::swap(arr[l], arr[r]);
    }
    l = r;
    r++;
    QuickSort(a, l, arr);
    QuickSort(r, b, arr);
}

/*size_t fact(size_t n, size_t* factorials) {
    if (factorials[n] != 0)
        return factorials[n];
    factorials[n] = fact(n-1, factorials)*n; // factorial[4] = fact(3)*4;
    return factorials[n];
}

// 0 1 1 2 3 5 8 13
// 0 1 2 3 4 5 6 7
size_t fibo(int n) {
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    return fibo(n-2) + fibo(n-1);
}*/

int main() {

    std::vector<int> vec;// = {3,1,2,4,6,7};
    vec.resize(1000000, 1);
    QuickSort(0, vec.size()-1, vec.data());

    std::sort(vec.begin(), vec.end());

    //for(auto x : vec) {
    //    std::cout << x << std::endl;
   // }
    // O(n^2)
    //std::cout << vec.size()-1 << std::endl;
    /*for(int i=0;i<vec.size();i++) {
        for(int j=i+1;j<vec.size();j++) {
            if(vec[i] > vec[j]) {
                std::swap(vec[i], vec[j]);
            }
        }
    }*/

    /*// Посчитать число Фибоначчи
    int fibo[100];
    fibo[0] = 0;
    fibo[1] = 1;
    int n = 10;
    for (int i = 2; i <= n; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    std::cout << fibo[n] << std::endl;*/

    /*// Вычислить факториал
    int n = 10;
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    size_t factorials[100] = {1, 1, 2, 6, 24, 0};
    std::cout << fact(27, factorials) << std::endl;

    for(size_t i = 0; i<28; ++i) {
        std::cerr << factorials[i] << std::endl;
    }*/
}
