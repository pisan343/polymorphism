/**
 * Yusuf Pisan, Nov 2018
 *
 * Cat and Dog are subclasses of Pet
 * PetFactory is used to create each type of Pet
 * Different pets know how to read themselves and create copies
 *
 */

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <cassert>
#include <vector>

using namespace std;

string readNextItem(istream &io, char delimiter = ',') {
  const char space = ' ';
  string str;
  getline(io, str, delimiter);
  if (str.empty())
    return str;
  else
    return str.substr(str.find_first_not_of(space),
                      str.find_last_not_of(space) + 1);
}

// read to end of line, returning string for debugging
const string discardLine(istream &is) {
  string discard;
  getline(is, discard);
  return discard;
}

/**
 * The abstract class at the top of the hierarchy
 * All Pets are derived from this class
 **/
class Pet {
  friend ostream &operator<<(ostream &os, const Pet &p) { return p.printer(os); }
 protected:
  string name, units;
  int age, weight;
 public:
  virtual Pet *create() = 0;
  virtual bool read(istream &is) = 0;
  virtual void say() = 0;
  virtual ostream &printer(ostream &os) const = 0;
  // Abstract classes should always have virtual destructors
  // not really used in this case
  virtual ~Pet() = default;
};

/**
 * Cat class, Cat is a Pet
 */
class Cat : public Pet {
 private:
  string type;
 public:
  Pet *create() override { return new Cat(); }
  // cats are: C FirstName LastName, Age Type, Weight WeightUnits
  bool read(istream &is) override {
    name = readNextItem(is);  // default delimiter is comma
    is >> age;
    type = readNextItem(is);
    is >> weight >> units;
    return true;
  }
  void say() override { cout << "Meeow" << endl; }
  ostream &printer(ostream &os) const override {
    os << "Cat: " << "name: " << name
       << ", age: " << age << ", type: " << type
       << ", weight: " << weight << ", wu: " << units;
    return os;
  }
};

/**
 * Dog class, Dog is a Pet
 */
class Dog : public Pet {
 private:
  string color;
 public:
  Pet *create() override { return new Dog(); }
  // dogs are: D Name Age, Color, Weight, WeightUnits
  bool read(istream &is) override {
    is >> name >> age;
    char discard_comma;
    is >> discard_comma;
    color = readNextItem(is);
    is >> weight >> discard_comma >> units;
    return true;
  }
  void say() override { cout << "Woof" << endl; }
  ostream &printer(ostream &os) const override {
    os << "Dog: " << "name: " << name
       << ", age: " << age << ", color: " << color
       << ", weight: " << weight << ", wu: " << units;
    return os;
  }
};

// PetFactory, each subclass of Pet needs its own concrete version
class PetFactory {
 private:
  static const int factory_size = 'Z' - 'A' + 1;
  Pet *pets[factory_size];
  int getBucket(char petType) const {
    assert(petType >= 'A' && petType <= 'Z');
    return petType - 'A';
  }
 public:
  PetFactory() {
    for (auto &p : pets) p = nullptr;
    pets[getBucket('C')] = new Cat();
    pets[getBucket('D')] = new Dog();
  }
  ~PetFactory() { for (const auto &p : pets) delete p; }

  Pet *create(char petType) {
    if (pets[getBucket(petType)])
      return pets[getBucket(petType)]->create();
    else
      return nullptr;
  }
};

class PetStore {
 private:
  PetFactory factory;
  vector<Pet *> pets;
 public:
  PetStore() = default;
  ~PetStore() { for (const auto &p : pets) delete p; }
  void readPetsFromFile(const string &filename) {
    ifstream fs(filename);
    if (!fs.is_open()) {
      cerr << "Could not open file: " << filename << endl;
    }
    char petType;
    while (fs >> petType) {
      Pet *pet = factory.create(petType);
      if (pet) {
        if (pet->read(fs)) {
          pets.push_back(pet);
        } else {
          delete pet;
        }
      } else {
        cout << "Unrecognized pet type: " << petType << endl;
        cout << "Discarding line: " << discardLine(fs) << endl;
      }
    }
    fs.close();
  }
  void processPets(const string &filename) {
    readPetsFromFile(filename);
    for (const auto &p : pets) {
      cout << *p << " says ---> ";
      p->say();
    }
  }
};

int main() {
  PetStore store;
  store.processPets("pets0.txt");
  return 0;
}
