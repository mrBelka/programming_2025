#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <fstream>
#include <vector>

const char LOWER_TO_UPPER_CASE_DIFF = 32;

char to_lower(char c) {
    if ('a' <= c && c <= 'z') {
        return c;
    }
    return c - LOWER_TO_UPPER_CASE_DIFF;
}

bool is_alpha(char c) {
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'B')) {
        return true;
    }
    return false;
}

void foo(const std::string& s) {
    std::cout << s << std::endl;
}

void bar(std::string_view s) {
    std::cout << s << std::endl;
}

int main() {
    // Чтение из файла
    std::ifstream in("input.txt");
    if(!in.is_open()) {
        std::cout << "File not open" << std::endl;
        return -1;
    }

    std::ofstream out("output.txt");

    std::vector<std::string> words;
    words.reserve(100);

    std::string s;
    while(!in.eof()) {
        std::getline(in, s);
        words.push_back(s);
        out << s << std::endl;
    }

    words.shrink_to_fit();


    /*std::string s = "Some string";
    foo(s);

    // Конвертация
    int age = 20;
    float height = 180.0f;
    std::string person = "Person`s age is " 
        + std::to_string(age) 
        + " and height is " 
        + std::to_string(height);

    std::stringstream stream;
    stream << "Person`s age is " << age << " and height is " << height;
    std::cout << stream.str() << std::endl;

    int d = std::stoi("123a456");
    std::cout << d << std::endl;*/
/*

    char c; // symbolic type, integer type
    char c1 = 'a'; // = 97
    char c2 = 'B';
    // char c3 = c1 + c2; // 97 + 98
    // Лексикографический порядок: a b c d
    // B < a
    // Регистр: нижний (lower), верхний (upper)
    std::cout << (to_lower(c1) < to_lower(c2)) << std::endl;

    char str[100] = "Hello, world!";
    std::cout << str << std::endl;

    size_t len = strlen(str);
    for(size_t i = 0; i < len; ++i) {
        std::cout << static_cast<int>(str[i]) << " ";
    }

    // Конкатенация
    char str1[100] = "hello";
    char str2[100] = "world";
    strcat(str1, str2);
    std::cout << str1 << std::endl;

    // Сравнение
    if (strcmp(str1, str2) == 1) {
        // ba
        // ab
    }

    // std::string
    std::string s = "Hello, world!";
    // char* str
    // size_t length
    // char* cap
    s.length(); // O(1)

    // Конкатенация
    std::string s1 = "Hello";
    std::string s2 = "world";
    std::string s3 = s1 + ' ' + s2 + "!";
    std::cout << s3 << std::endl;

    // Сравнение строк
    if(s1 < s2) {

    }

    // Удаление
    s1.erase(2, 2); // O(n)
    std::cout << s1 << std::endl;

    // Дублирование
    s1.insert(2, "ll"); // O(n^2)
    std::cout << s1 << std::endl;

    // Поиск O(n)
    // '#'
    std::cout << (s1.find("#") != std::string::npos)<< std::endl;

    // Построка
    std::string s3 = s1.substr(2, 2);*/
}