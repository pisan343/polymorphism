/**
 * Carol Zander  http://courses.washington.edu/css343/zander/Code/factory.cpp
 */
#include <string>
#include <iostream>
using namespace std;

// ----- CLASS Stuff ------ virtual print, create -----------------------------
class Stuff {
 protected:
  string name;
 public:
  Stuff() = default;
  virtual ~Stuff() = default;
  void setData(const string& s) { name = s; }
  virtual Stuff *create() const = 0;
  virtual void print() const = 0;
};

// ----- DERIVED CLASS AObject ------------------------------------------------
class AObject : public Stuff {
 public:
  Stuff *create() const override { return new AObject; }
  void print() const override { cout << "  AObject:  " << name << endl; }
};

// ----- DERIVED CLASS BObject ------------------------------------------------
class BObject : public Stuff {
 public:
  Stuff *create() const override { return new BObject; }
  void print() const override { cout << "  BObject:  " << name << endl; }
};

// ----- DERIVED CLASS CObject -----------------------------------------------
class CObject : public Stuff {
 public:
  Stuff *create() const override { return new CObject; }
  void print() const override { cout << "  CObject:  " << name << endl; }
};

// ----- DERIVED CLASS DObject -----------------------------------------------
class DObject : public Stuff {
 public:
  Stuff *create() const override { return new DObject; }
  void print() const override { cout << "  DObject:  " << name << endl; }
};

// ----- DERIVED CLASS EObject -----------------------------------------------
class EObject : public Stuff {
 public:
  Stuff *create() const override { return new EObject; }
  void print() const override { cout << "  EObject:  " << name << endl; }
};

// ----- CLASS List ----------------------------------------------------------
class List {
 private:
  struct Node {
    explicit Node(Stuff *aStuff) {
      stuffPtr = aStuff;
      next = nullptr;
    }
    Stuff *stuffPtr;                              // pointer to the data
    Node *next;
  };
  Node *head, *tail;

 public:
  List() {
    head = tail = nullptr;
  }

  ~List() {
    makeEmpty();
  }

  void makeEmpty() {
    while (head != nullptr) {
      Node *save = head;
      head = head->next;
      delete save->stuffPtr;
      save->stuffPtr = nullptr;
      delete save;
      save = nullptr;
    }
    tail = nullptr;
  }

  void append(Stuff *aStuff) {
    if (head == nullptr)
      head = tail = new Node(aStuff);
    else {
      tail->next = new Node(aStuff);
      tail = tail->next;
    }
  }

  void printList() const {
    for (Node *p = head; p != nullptr; p = p->next)
      p->stuffPtr->print();
  }
};

// ----- CLASS Factory -------------------------------------------------------
// A factory creates and returns a new object. Does no work beyond creation.

class Factory {
 private:
  Stuff *objFactory[10]; // in general, do not hard code numbers, room to grow
  int hash(char ch) const { return ch - 'A'; }

 public:
  Factory() {
    objFactory[0] = new AObject;
    objFactory[1] = new BObject;
    objFactory[2] = new CObject;
    objFactory[3] = new DObject;
    objFactory[4] = new EObject;
    for (int i = 5; i < 10; i++) objFactory[i] = nullptr;
  }

  ~Factory() {
    for (int i = 0; i < 5; i++) {
      delete objFactory[i];
    }
  }

  Stuff *createIt(char ch) const {
    int subscript = hash(ch);             // would do error checking
    return objFactory[subscript]->create();
  }
};

// ----- CLASS Manager -------------------------------------------------------
class Manager {
 private:
  Factory objFactory;
  List myList;
  char pretendDataFile[5];

 public:
  Manager() {
    pretendDataFile[0] = 'C';
    pretendDataFile[1] = 'A';
    pretendDataFile[2] = 'B';
    pretendDataFile[3] = 'E';
    pretendDataFile[4] = 'D';
  }

  void buildCollectionBySwitch() { // violates Open-Closed Principle
    string s = " is the data";
    char obj;                    // for reading from pretend data file
    Stuff *p;                    // the object created

    for (int i = 0; i < 5; i++) {
      obj = pretendDataFile[i];
      switch (obj) {
        case 'A': p = new AObject;
          p->setData(obj + s);
          break;
        case 'B': p = new BObject;
          p->setData(obj + s);
          break;
        case 'C': p = new CObject;
          p->setData(obj + s);
          break;
        case 'D': p = new DObject;
          p->setData(obj + s);
          break;
        case 'E': p = new EObject;
          p->setData(obj + s);
          break;
        default:
          cout << "Bad switch statement" << endl;
          p = nullptr;
      }
      myList.append(p);
    }
  }

  void buildCollectionByFactory() { // good design, no OCP violation
    string s = " is the data";
    char obj;                     // for reading from pretend data file
    Stuff *p;                     // the object obtained from factory

    for (int i = 0; i < 5; i++) {
      obj = pretendDataFile[i];    // normally read from data file
      p = objFactory.createIt(obj);
      p->setData(obj + s);
      myList.append(p);
    }
  }

  void displayCollection() {
    myList.printList();
    cout << endl;
  }

  void destroyCollection() {
    myList.makeEmpty();
  }
};

// ------------------------------ main ---------------------------------------
int main() {
  Manager myStuff;
  myStuff.buildCollectionBySwitch();
  cout << "Collection built by using switch:" << endl;
  myStuff.displayCollection();
  myStuff.destroyCollection();
  cout << endl;

  cout << "Collection built by using factory:" << endl;
  myStuff.buildCollectionByFactory();
  myStuff.displayCollection();
  myStuff.destroyCollection();
  return 0;
}
