//
// Created by Yusuf Pisan on 2/14/24
//

#include "pet.h"
#include <iostream>

using namespace std;

/**
 * Storage place for the concrete pet factories
 * Having it available only through this function guarantees that
 * this static variable is initialized
 * when a concrete factory tires to register itself
 * @return map
 */
map<string, PetFactory *> &Pet::getMap() {
  static map<string, PetFactory *> factories;
  return factories;
}

// register a concrete factory with a given name
void Pet::registerType(const string &type, PetFactory *factory) {
  getMap().emplace(type, factory);
}
// find the corresponding pet factory and get factory to create the object
Pet *Pet::create(const string &type) {
  if (!getMap().count(type)) {
    cout << "Don't know how to create " << type << endl;
    return nullptr;
  }
  return getMap().at(type)->create();
}
