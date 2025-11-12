#ifndef PET_H
#define PET_H

#include <map>
#include <string>

using namespace std;

// forward declaration, will declare class Pet fully later
class Pet;

// An abstract PetFactory, each subclass of Pet needs its own concrete version
class PetFactory
{
public:
  virtual Pet *makePet() const = 0;

  // find the corresponding pet factory and get factory to create the object
  static Pet *create(const string &type);

protected:
  // register a concrete factory with a given name
  static void registerType(const string &type, PetFactory *factory);

private:
  /**
   * Storage place for the concrete pet factories
   * Having it available only through this function guarantees that
   * this static variable is initialized
   * when a concrete factory tires to register itself
   * @return map
   */
  static map<string, PetFactory *> &getMap();
};

/**
 * The abstract class at the top of the hierarchy
 * All Pets are derived from this class
 * Stores pet factories and creates Pet objects through static functions
 **/
class Pet
{
public:
  // different pets make different noises, all subclasses must implement say
  virtual void say() const = 0;

  // Abstract classes should always have virtual destructors
  // not really used in this case
  virtual ~Pet() = default;
};

#endif // PET_H
