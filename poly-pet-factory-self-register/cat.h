#ifndef CAT_H
#define CAT_H

/**
 * Cat class, Cat is a Pet
 */

#include <string>
#include "pet.h"

class Cat : public Pet
{
public:
  void say() const override;
};

/**
 * Creating CatFactory to make Cat objects
 * CatFactory object will register itself later and get stored in Pet class
 */
class CatFactory : public PetFactory
{
public:
  CatFactory();
  Pet *makePet() const override;
};

#endif // CAT_H
