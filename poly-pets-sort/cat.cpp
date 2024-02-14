#include "cat.h"
#include <cassert>

using namespace std;

Cat::Cat(const string &name, int age) : age{age} { this->name = name; }

ostream &Cat::printer(ostream &os) const {
  os << name << "(" << age << ")";
  return os;
}

bool Cat::lessThan(const Pet &other) const {
  // won't work, no variable named age
  // return age < other.age;

  // downcasting base class to derived class
  // even better to use auto here: auto otherCat = ....
  const Cat &otherCat = dynamic_cast<const Cat &>(other);
  return age < otherCat.age;
}
