#include <iostream>
#include "some_functions.hpp"
#include "graphics.hpp"
#include <thread>

int divide(int n) {
  throw 10;
  if (n==0) {
    throw "[main]: N is equal zero; ";  
  }
  return 10 / n;
}

int main() {
  int c;
  while(1) {
    std::cin >> c;
    std::cout << "<" << (int)c << ">" << std::endl;
    std::cout << std::cin.good() << std::endl;
    std::cin.clear();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }


  int n;
  float m;
  while(1) {
    while(1) {
      if(!std::cin.good()) {
        std::cout << "Error: invalid type" << std::endl;
      }
      std::cin >> n;
      std::cin >> m;
    }
  }
  std::cout << "Correct type " << n << std::endl;

  try {
    int value = divide(n);
    std::cout << value << std::endl;
  } 
  catch (const char* msg) {
    std::cout << msg << std::endl;
  }
  catch (...) {
    std::cout << "Error" << std::endl;
  }


  /*int* p = new int(1000); // 0 0 3 232
  std::cout << p << std::endl;
  std::cout << p + 1 << std::endl;
  std::cout << *p << std::endl;

  unsigned char* pc = reinterpret_cast<unsigned char*>(p);
  std::cout << pc << std::endl;
  std::cout << static_cast<int>(*pc) << std::endl;
  std::cout << static_cast<int>(*(pc+1)) << std::endl;

  // Сравнение
  // + число

  delete p;
  */
  //void* pv = reinterpret_cast<void*>(p);
  //*pv;


  /*int* px = (int*)malloc(sizeof(int));

  int* px = (int*)calloc(2, 4);

  int* px = (int*)realloc(px, 2*sizeof(int));

  free(px);*/

  /*int arr_fixed[1'000];
  arr_fixed[0] = 10;

  *arr_fixed = 10;

  *(arr_fixed+1) = 11; // arr_fixed[1] = 11;

  while(1) {
    int* arr_dyn = new int[1'000'000'000'000];
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    delete[] arr_dyn;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  //arr_dyn[0] = 10;
  //*(arr_dyn+1) = 11;

  //delete[] arr_dyn;

  std::cout << "Finish" << std::endl;*/
}
