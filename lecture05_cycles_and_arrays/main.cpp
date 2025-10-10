#include <iostream>

int main() {
    /*
    // Алгоритм распаковки натурального числа
    // 123 -> 1 2 3
    int x = 123;
    // std::cout << x % 10 << std::endl; // 3
    // std::cout << (x / 10) % 10 << std::endl; // 2

    int sum = 0;
    int mult = 1;
    int min = 9;
    int max = 0;
    while(x > 0) {
        int d = x % 10;
        sum += d;
        mult *= d;
        min = std::min(min, d);
        max = std::max(max, d);
        x /= 10;
    }
    std::cout << "Sum = " << sum << std::endl;
    std::cout << "Mult = " << mult << std::endl;
    std::cout << "Min_d = " << min << std::endl;
    std::cout << "Max_d = " << max << std::endl;
    */

    /*
    // найти наиболее часто встречающуюся цифру
    int x = 1231;
    int most_frequently = 0;
    int max_cnt = 0;
    for(int d = 0;d < 10;++d) {
        int cnt = 0;
        int tmp = x;
        while(tmp > 0) {
            int digit = tmp % 10;
            if(digit == d) {
                ++cnt;
            }
            tmp /= 10;
        }
        if(max_cnt < cnt) {
            max_cnt = cnt;
            most_frequently = d;
        }
    }
    std::cout << most_frequently << std::endl;
    */

    /*
    // области видимости

    {
        int x = 10;
        x = 1;
        std::cout << x << std::endl;
    }

    {
        int x = 123;
        x = 2;
        std::cout << x << std::endl;
    }

    for (int i = 0;i < 10;++i) {
        if (i == 5)
            break;
    }
    */

    int x1 = 5;
    int x2 = 1;
    int x3 = 2;
    int x4 = 50;
    int x5 = 10;

    const int NMax = 5;
    int x[NMax];
    x[0] = 5;
    x[1] = 1;
    x[2] = 2;
    x[3] = 50;
    x[4] = 10;
    std::cout << x[0] << std::endl;

    for(int i=0;i<NMax-1;++i) {
        for(int j=i+1;j<NMax;++j) {
            if(x[i] < x[j]) {
                // std::swap(x[i], x[j]);
                int tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;
            }
        }
    }

    for(int i=0;i<5;++i) {
        std::cout << x[i] << std::endl;
    }

    int arr[] = {1,2,3,4,5};

    // Многомерный массив (2х мерный)
    const int MMax = 10;

    int matrix[NMax][MMax] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    std::cout << matrix[1][0] << std::endl;

    for(int i=0;i<NMax;++i) {
        for(int j=0;j<MMax;++j) {
            std::cout << matrix[i][j] << " "; 
        }
        std::cout << std::endl;
    }

    int arr_not_inited[4] = {};
    for(int i = 0;i<4;++i)
        std::cout << arr_not_inited[i] << std::endl;
}