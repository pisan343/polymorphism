
#include "pet.h"
#include <iostream>

using namespace std;

ostream &operator<<(ostream &os, const Pet &p) { return p.printer(os); }

bool Pet::operator<(const Pet &other) { return lessThan(other); }

const string &Pet::getName() const { return name; }