/**
 * Yusuf Pisan, Nov 2018
 *
 * Cat and Dog are subclasses of Pet
 * PetFactory provides an abstraction for CatFactory, DogFactory, etc
 * All Pet objects are created through static function Pet::create
 * Subclasses of Pet are responsible for registering themselves
 * Each subclass has its own factory which is kept in a static variable in the
 * getMap() function of of Pet class
 *
 * For instructional simplicity, it is all in a single file
 * Once you understand the example, each class should get its own file
 *
 * One Problem: We do have a couple of pointers in the static variable
 * inside Pet::getMap that are never deleted until the end of the program
 * Smart pointers, specifically unique_ptr would take care of that, but not
 * much to be done with regular pointers
 *
 */

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "pet.h"

using namespace std;

// helper - get rid of spaces before and after string
string trimString(const string &str) {
  return str.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') + 1);
}

// helper - split string into multiple based on delimiter
vector<string> splitString(const string &str, char delimiter = ',') {
  vector<string> tokens;
  string token;
  istringstream tokenStream(str);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(trimString(token));
  }
  return tokens;
}

// helper function for reading from file
vector<Pet *> readPetsFromFile(const string &filename) {
  vector<Pet *> pets;
  ifstream fs(filename);
  if (!fs.is_open()) {
    cerr << "Could not open file: " << filename << endl;
    return pets;
  }
  string str;
  while (getline(fs, str) && !str.empty()) {
    vector<string> vs = splitString(str);
    // ignoring other pet parameters for this example
    Pet *pet = Pet::create(vs[0]);
    if (pet)
      pets.push_back(pet);
  }
  return pets;
}

// test pets by reading a file
void testPetsFromFile() {
  cout << "Testing pets by reading pets0.txt" << endl;
  vector<Pet *> pets = readPetsFromFile("pets0.txt");
  for (const auto &pet : pets) {
    pet->say();
    delete pet;
  }
}

int main() {
  testPetsFromFile();
  return 0;
}
