#include <iostream>

struct Mom {
int y_;

protected:
int z_;
private:
  int x_;
};

struct Son : public Mom {
void foo() {
  z_ = 10;
}
}


/*
namespace mt {
class string {
public:
  // The Rule of Three

  string() : size_(0), str_(nullptr) {}
  string(const char c, const size_t size) : size_(size), str_(new char[size_]) {
    std::fill(str_, str_ + size_, c);
    std::cerr << "ctor" << std::endl;
  }
  ~string() {
    if (str_ != nullptr) {
      delete[] str_;
    }
    std::cerr << "dtor" << std::endl;
  }

  string(const char* str) : size_(strlen(str)), str_(new char[size_]) {
    std::copy(str, str + size_, str_);
    
    std::cerr << "ctor" << std::endl;
  }
  string(const string& other) : string(other.str_) {
    std::cerr << "copy ctor" << std::endl;
  }

  //string(const string& other) = delete;

  // idiom copy-and-swap
  string& operator=(string& other) {
    string tmp = other;
    std::swap(tmp.size_, size_);
    std::swap(tmp.str_, str_);
    if (this != &other) {
      delete[] str_;
      size_ = other.size_;
      str_ = new char[size_];
      std::copy(other.str_, other.str_ + other.size_, str_);
      std::cerr << "copy assigment operator" << std::endl;
    }
    return *this;
  }

  void print() const {
    for (size_t i = 0; i < size_; ++i) {
      std::cout << str_[i];
    }
    std::cout << std::endl;
  }

  void set(size_t index, char c) {
    str_[index] = c;
  }
private:
  size_t size_;
  char* str_; // small string optimization
};
} // namespace mt

void foo(const mt::string& s) {
  s.print();
}

int main() {
  mt::string a('a', 5);
  a = a;
  a.print();
  //foo(a);
  //a.print();
  //mt::string b = a; // copy ctor
  //mt::string c(a); // copy ctor

  //mt::string c;
  //mt::string b('c', 10);
  //c = b = a;  // copy assigment operator
  //b.print();
  //std::cout << s << std::endl;
}*/

/*
class Test {
public:
void print() const {
  x_ = 10;
  std::cout << x_ << std::endl;
}

private:
  mutable int x_ = 123;
};
*/

/*
class Test {
private:
  int x_ = 123;
};

int main() {
  Test test;
  int* p = reinterpret_cast<int*>(&test); // Test*
  std::cout << *p << std::endl;
  *p = 10;
  std::cout << *p << std::endl;
}
*/

/*
struct Longitude {
  double value;
};

struct Latitude {
  double value;
};

class Car {
public:
  Car(Longitude lon, Latitude lat) : lon_(lon.value), lat_(lat.value) {}
private:
  double lon_;
  double lat_;
};

int main() {
  Latitude lat;
  lat.value = 54.344542;
  Longitude lon;
  lon.value = 20.622427;
  Car car(lon, lat);
}*/

/*
class Test {
public:
  explicit Test(int x) : x_(x) {

  }
  void Init() {
    // 
  }
private:
  int x_;
};

void print(const Test& test) {
  // ...
}

int main()
{
  Test test(10);
  test.Init();
  Test test1 = 10;
  print(10);
}*/