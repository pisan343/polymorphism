#include <iostream>
#include <map>

using namespace std;

class Pet {
 public:
  virtual void say() = 0;
  virtual ~Pet() = default;
};

// Cat class, Cat isa Pet
class Cat : public Pet {
 public:
  void say() override { cout << "Meeow" << endl; }
};

// Dog class, Cat isa Pet
class Dog : public Pet {
 public:
  void say() override { cout << "Woof" << endl; }
};

// PetFactory is the only one that knows about different Pets
class PetFactory {
 public:
  static Pet *create(string type) {
    if (type == "Cat")
      return new Cat();
    else
      return new Dog();
  }
};

int main() {
  Pet *p1 = PetFactory::create("Cat");
  Pet *p2 = PetFactory::create("Dog");
  p1->say();
  p2->say();
  delete p1;
  delete p2;
  return 0;
}