
#include "dog.h"
#include <cassert>
#include <iostream>

using namespace std;

Dog::Dog(const string &name, const string &breed) : breed{breed} {
  this->name = name;
}
ostream &Dog::printer(ostream &os) const {
  os << name << "(" << breed << ")";
  return os;
}
// need to write dog lessThan
bool Dog::operator<(const Pet &other) const {
  // downcasting base class to derived class
  const Dog &otherDog = dynamic_cast<const Dog &>(other);
  // better make sure things worked, a bit overkill
  return breed < otherDog.breed;
};
