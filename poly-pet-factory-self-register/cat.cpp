
#include "cat.h"
#include <iostream>

using namespace std;

void Cat::say() const { cout << "Meeow" << endl; }

CatFactory::CatFactory() { Pet::registerType("Cat", this); }

Pet *CatFactory::create() const { return new Cat(); }

// creating the object registers the type at run time
CatFactory anonymous_CatFactory;
