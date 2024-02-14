
#include "dog.h"
#include <iostream>

using namespace std;

void Dog::say() const { cout << "Woof" << endl; }

DogFactory::DogFactory() { Pet::registerType("Dog", this); }

Pet *DogFactory::create() const { return new Dog(); }

// creating the object registers the type at run time
DogFactory anonymous_DogFactory;