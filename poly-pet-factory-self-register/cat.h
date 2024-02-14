#ifndef CAT_H
#define CAT_H

/**
 * Cat class, Cat is a Pet
 */

#include "pet.h"

class Cat : public Pet {
public:
  void say() const override;
};

/**
 * Creating CatFactory to make Cat objects
 * CatFactory object will register itself later and get stored in Pet class
 */
class CatFactory : public PetFactory {
public:
  CatFactory();
  Pet *create() const override;
};

#endif // CAT_H
