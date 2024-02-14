#ifndef DOG_H
#define DOG_H

/**
 * Dog class, Dog is a Pet
 */

#include "pet.h"

class Dog : public Pet {
public:
  void say() const override;
};

/**
 * Creating DogFactory to make Dog objects
 * DogFactory object will register itself later and get stored in Pet class
 */
class DogFactory : public PetFactory {
public:
  DogFactory();
  Pet *create() const override;
};

#endif // DOG_H
