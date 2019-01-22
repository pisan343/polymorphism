//
// Created by Yusuf Pisan on 11/20/18.
//

#include "horse.h"

void Horse::say() const {
  cout << "Neighhhh" << endl;
}

HorseFactory::HorseFactory() {
  Pet::registerType("Horse", this);
}

Pet *HorseFactory::create() const {
  return new Horse();
}

namespace {
HorseFactory anonymous_HorseFactory;
}