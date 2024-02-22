#ifndef DOG_H
#define DOG_H

/**
 * Dog class, Dog is a Pet
 */

#include "pet.h"
#include <iostream>

using namespace std;

class Dog : public Pet {
private:
  string breed;

protected:
  ostream &printer(ostream &os) const override;

public:
  Dog(const string &name, const string &breed);
  bool operator<(const Pet &other) const override;
};

#endif // DOG_H