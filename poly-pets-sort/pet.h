#ifndef PET_H
#define PET_H

#include <iostream>

using namespace std;

class Pet {
  friend ostream &operator<<(ostream &os, const Pet &p);

protected:
  string name;
  virtual ostream &printer(ostream &os) const = 0;
  virtual bool lessThan(const Pet &pet) const = 0;

public:
  const string &getName() const;
  bool operator<(const Pet &other);
  virtual ~Pet() = default;
};

#endif // PET_H