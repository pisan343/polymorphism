/**
 * No changes is needed when a new animal is added
 *
 * Try commenting out horse.h/cpp and recompile, Horse objects will not be made
 * Recompile with horse.h/horse.cpp and HorseFactory self-registers,
 * factory can now make a Horse objects
 *
 * You can edit the CMakeLists.txt file to exclude it from project or
 * use block comments
 */

#ifndef POLY_PET_FACTORY_SELF_REGISTER_HORSE_H
#define POLY_PET_FACTORY_SELF_REGISTER_HORSE_H

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


#endif // POLY_PET_FACTORY_SELF_REGISTER_HORSE_H
