//
// Created by Yusuf Pisan on 11/20/18.
//

#include "pet.h"

/**
 * factories have been declared, and now have to be registered
 * this is normally done in the cpp file for the concrete factory
 * CatFactory.cpp or DogFactory.cpp
 * Creating a factory automatically registers it
 * Using anonymous namespace to not create a global variable
 *  // NOLINT stops the warning message about may throw an exception
 */

// // creating the object registers the type at run time
CatFactory anonymous_CatFactory;
DogFactory anonymous_DogFactory;

// left intentionally empty, everything in pet.h for
// demonstration purposes