#ifndef HORSE_H
#define HORSE_H

#include "pet.h"

class Horse : public Pet {
public:
  void say() const override;
};

class HorseFactory : public PetFactory {
public:
  HorseFactory();
  Pet *create() const override;
};

#endif // HORSE_H
