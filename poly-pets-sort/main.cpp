/**
 * Yusuf Pisan, Nov 2018
 *
 * Cat and Dog are subclasses of Pet
 * Different pets are stored in different containers
 * How do we sort the containers?
 *
 * Answer: Downcasting, dynamically cast Base class to derived class
 *
 */

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * The abstract class at the top of the hierarchy
 * All Pets are derived from this class
 **/
class Pet {
  friend ostream &operator<<(ostream &os, const Pet &p) {
    return p.printer(os);
  }
 protected:
  string name;
 public:
  const string &getName() const {
    return name;
  }
  virtual ostream &printer(ostream &os) const = 0;
  virtual bool lessThan(Pet *pet) const = 0;
  virtual ~Pet() = default;
};

/**
 * Cat class, Cat is a Pet
 */
class Cat : public Pet {
 private:
  int age;
 public:
  Cat(const string &name, int age) : age{age} { this->name = name; }
  ostream &printer(ostream &os) const override {
    os << name << "(" << age << ")";
    return os;
  }
  // implementation of lessThan is below
  bool lessThan(Pet *other) const override;
};

/**
 * Dog class, Dog is a Pet
 */
class Dog : public Pet {
 private:
  string breed;
 public:
  Dog(const string &name, const string &breed) : breed{breed} {
    this->name = name;
  }
  ostream &printer(ostream &os) const override {
    os << name << "(" << breed << ")";
    return os;
  }
  // need to write dog lessThan
  bool lessThan(Pet *other) const override { return false; }
};

void addPet(Cat *cat, map<char, vector<Pet *>> &petStore) {
  petStore['C'].push_back(cat);
}

void addPet(Dog *dog, map<char, vector<Pet *>> &petStore) {
  petStore['D'].push_back(dog);
}

void display(vector<Pet *> &pets) {
  for (const auto &pet : pets) {
    cout << *pet << " ";
  }
  cout << endl;
}

// sort by name
// Cats: Fluffy Hunter Misty
// Dogs: Fetch King Sweet
void sortByName(vector<Pet *> &pets) {
  sort(pets.begin(), pets.end(),
       [](Pet *p, Pet *q) { return p->getName() < q->getName(); });
}

bool Cat::lessThan(Pet *other) const {
  // don't want any nullptr here
  assert(other);
  // won't work, no variable named age
  // return age < other->age;

  // downcasting base class to derived class
  // even better to use auto here: auto othercat = ....
  Cat *othercat = dynamic_cast<Cat *>(other);
  // better make sure things worked, a bit overkill
  assert(othercat && othercat == other);
  return age < othercat->age;
}

// sort by key, for Cats it is age, for dogs it is breed
// use polymorphic function lessThan
// Cats: Hunter(1) Fluffy(2) Misty(5)
void sortByDefaultKey(vector<Pet *> &pets) {
  sort(pets.begin(), pets.end(),
       [](Pet *p, Pet *q) { return p->lessThan(q); });
}

void testPets() {
  map<char, vector<Pet *>> petStore;
  addPet(new Cat("Fluffy", 2), petStore);
  addPet(new Cat("Misty", 5), petStore);
  addPet(new Cat("Hunter", 1), petStore);
  addPet(new Dog("Sweet", "german shepard"), petStore);
  addPet(new Dog("King", "pug"), petStore);
  addPet(new Dog("Fetch", "labrador"), petStore);
  for (auto &cv : petStore) {
    cout << "Looking at animals in container: " << cv.first << endl;
    vector<Pet *> &v = cv.second;
    cout << "* Sort by name" << endl;
    sortByName(v);
    display(v);
    cout << "* Sort by default key" << endl;
    sortByDefaultKey(v);
    display(v);
  }

  // delete them
  for (const auto &cv : petStore) {
    for (const auto &petptr : cv.second) {
      delete petptr;
    }
  }
}

int main() {
  testPets();
  cout << "Done." << endl;
  return 0;
}
