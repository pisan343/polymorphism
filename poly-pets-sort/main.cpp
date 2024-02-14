
#include "cat.h"
#include "dog.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void addPet(Cat *cat, map<char, vector<Pet *>> &petStore) {
  petStore['C'].push_back(cat);
}

void addPet(Dog *dog, map<char, vector<Pet *>> &petStore) {
  petStore['D'].push_back(dog);
}

// sort by name
// Cats: Fluffy Hunter Misty
// Dogs: Fetch King Sweet
void sortByName(vector<Pet *> &pets) {
  sort(pets.begin(), pets.end(),
       [](Pet *p, Pet *q) { return p->getName() < q->getName(); });
}

// sort by key, for Cats it is age, for dogs it is breed
// use polymorphic function lessThan
// Cats: Hunter(1) Fluffy(2) Misty(5)
void sortByDefaultKey(vector<Pet *> &pets) {
  sort(pets.begin(), pets.end(), [](Pet *p, Pet *q) { return *p < *q; });
}

void display(vector<Pet *> &pets) {
  for (const auto &pet : pets) {
    cout << *pet << " ";
  }
  cout << endl;
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
    for (const auto &ptr : cv.second) {
      delete ptr;
    }
  }
}

int main() {
  testPets();
  cout << "Done." << endl;
  return 0;
}
