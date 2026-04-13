#include <iostream>
#include <string>
#include <vector>

enum class Colors {
  ORANGE,
  BLACK,
  WHITE
};

class Animal {
  public:
    Animal(const std::string& name, unsigned short age, 
      Colors color) : name_(name), age_(age), color_(color) {
        std::cout << "animal ctor" << std::endl;
      }
    virtual ~Animal() {
      std::cout << "animal dtor" << std::endl;
    }
    virtual void say() = 0;
  protected:
    std::string name_;
    unsigned short age_;
    Colors color_;
};

class Cat : public Animal {
  public:
    //using Animal::Animal;
    Cat(const std::string& name, unsigned short age, 
      Colors color) : Animal(name, age, color) {
        std::cout << "cat ctor" << std::endl;
      }
    ~Cat() {
      std::cout << "cat dtor" << std::endl;
    }
    void say() override {
      std::cout << "meooowww" << std::endl;
    }
  private:
    size_t num_of_catched_mice_;
};

class Dog : public Animal {
  public:
    //using Animal::Animal;
    Dog(const std::string& name, unsigned short age, 
      Colors color) : Animal(name, age, color) {
        std::cout << "dog ctor" << std::endl;
      }
    ~Dog() {
      std::cout << "dog dtor" << std::endl;
    }
    void say() override {
      std::cout << "gavvv" << std::endl;
    }
  private:
    size_t num_of_catched_mice_;
};

int main() {
  // Cat cat("Barsik", 1, Colors::ORANGE);
  // cat.say();
  //Animal animal("Barsik", 1, Colors::ORANGE);
  //animal.say();

  std::vector<Animal*> animals;
  animals.emplace_back(new Cat("Barsik", 1, Colors::ORANGE));
  animals.emplace_back(new Dog("Tuzik", 2, Colors::BLACK));
  for (Animal* animal : animals) {
    animal->say();
  }

  Animal* cat = new Cat("Barsik", 1, Colors::ORANGE);
  Animal* dog = new Dog("Tuzik", 2, Colors::BLACK);
  cat->say();
  dog->say();
  delete cat;
  delete dog;
  // delete cat; // TODO
}