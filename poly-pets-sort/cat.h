#ifndef CAT_H
#define CAT_H

#include "pet.h"
#include <iostream>

using namespace std;

/**
 * Cat class, Cat is a Pet
 */
class Cat : public Pet {
private:
  int age;

protected:
  virtual ostream &printer(ostream &os) const override;

public:
  Cat(const string &name, int age);
  bool operator<(const Pet &other) const override;
};

#endif // CAT_H
