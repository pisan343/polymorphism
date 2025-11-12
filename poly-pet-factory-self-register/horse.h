#ifndef HORSE_H
#define HORSE_H

#include <string>
#include "pet.h"

class Horse : public Pet
{
public:
  void say() const override;
};

class HorseFactory : public PetFactory
{
public:
  HorseFactory();
  Pet *makePet() const override;
};

#endif // HORSE_H
