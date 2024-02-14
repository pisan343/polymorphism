//
// Created by Yusuf Pisan on 11/20/18.
//

#include "horse.h"
#include <iostream>

using namespace std;

void Horse::say() const { cout << "Neighhhh" << endl; }

HorseFactory::HorseFactory() { Pet::registerType("Horse", this); }

Pet *HorseFactory::create() const { return new Horse(); }

// creating the object registers the type at run time
HorseFactory anonymous_HorseFactory;
