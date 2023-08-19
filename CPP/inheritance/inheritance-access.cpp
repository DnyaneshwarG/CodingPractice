#include <iostream>

using namespace std;

class Base {
public:
  Base() {
    cout << "Base contructor" << endl;
  }

  virtual ~Base() {
    cout << "Base destructor" << endl;
  }
};

class Derived : public Base {
public:
  Derived() {
    cout << "Derived constructor" << endl;
  }

  ~Derived() {
    cout << "Derived destroctor" << endl;
  }
};


int main()
{
  {
    Base *b;
    Derived d;
    b = &d;
  }
  cout << "downcasting" << endl;
  {
    Base b;
    Derived *d;
    d = dynamic_cast<Derived*>(&b);
    delete d;
  }
  return 0;
}
