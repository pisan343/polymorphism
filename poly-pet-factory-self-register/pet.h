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
 */

#ifndef POLY_PET_FACTORY_SELF_REGISTER_PET_H
#define POLY_PET_FACTORY_SELF_REGISTER_PET_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

// forward declaration, will declare class Pet fully later
class Pet;

// An abstract PetFactory, each subclass of Pet needs its own concrete version
class PetFactory {
 public:
  virtual Pet *create() const = 0;
};

/**
 * The abstract class at the top of the hierarchy
 * All Pets are derived from this class
 * Stores pet factories and creates Pet objects through static functions
 **/
class Pet {
 private:
  /**
   * Storage place for the concrete pet factories
   * Having it available only through this function guarantees that
   * this static variable is initialized
   * when a concrete factory tires to register itself
   * @return map
   */
  static map<string, PetFactory *> &getMap() {
    static map<string, PetFactory *> factories;
    return factories;
  }

 public:
  // register a concrete factory with a given name
  static void registerType(const string &type, PetFactory *factory) {
    getMap().emplace(type, factory);
  }
  // find the corresponding pet factory and get factory to create the object
  static Pet *create(const string &type) {
    if (!getMap().count(type)) {
      cout << "Don't know how to create " << type << endl;
      return nullptr;
    }
    return getMap().at(type)->create();
  }
  // different pets make different noises, all subclasses must implement say
  virtual void say() const = 0;

  // Abstract classes should always have virtual destructors
  // not really used in this case
  virtual ~Pet() = default;
};

/**
 * Cat class, Cat is a Pet
 */
class Cat : public Pet {
 public:
  void say() const override { cout << "Meeow" << endl; }
};

/**
 * Creating CatFactory to make Cat objects
 * CatFactory object will register itself later and get stored in Pet class
 */
class CatFactory : public PetFactory {
 public:
  CatFactory() {
    Pet::registerType("Cat", this);
  }
  Pet *create() const override { return new Cat(); }
};

/**
 * Dog class, Dog is a Pet
 */
class Dog : public Pet {
 public:
  void say() const override { cout << "Woof" << endl; }
};

/**
 * Creating DogFactory to make Dog objects
 * DogFactory object will register itself later and get stored in Pet class
 */
class DogFactory : public PetFactory {
 public:
  DogFactory() {
    Pet::registerType("Dog", this);
  }
  Pet *create() const override { return new Dog(); }
};

/**
 * factories have been declared, and now have to be registered
 * this is normally done in the cpp file for the concrete factory
 * CatFactory.cpp or DogFactory.cpp
 * Creating a factory automatically registers it
 * Using anonymous namespace to not create a global variable
 *  // NOLINT stops the warning message about may throw an exception
 */
namespace {
CatFactory anonymous_CatFactory __attribute__((unused));   // NOLINT
DogFactory anonymous_DogFactory __attribute__((unused));   // NOLINT
}

#endif // POLY_PET_FACTORY_SELF_REGISTER_PET_H
