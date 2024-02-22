
#include "pet.h"
#include <iostream>

using namespace std;

ostream &operator<<(ostream &os, const Pet &p) { return p.printer(os); }

const string &Pet::getName() const { return name; }