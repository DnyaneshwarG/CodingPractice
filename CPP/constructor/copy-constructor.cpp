#include <iostream>
#include <stdio.h>

using namespace std;

class Test {
  int x, y;

  public:
  Test() { }

  Test(int xx, int yy) {
    x = xx;
    y = yy;
  }
  Test(Test &obj) {
    x = obj.x;
    y = obj.y;
  }
  void print_obj() {
    cout << "\nx = " << x << " y = " << y;
  }
  void operator=(Test& obj) {
    x = obj.x;
    y = obj.y;
  }
};

int main () {
  Test t0(10,20);
  t0.print_obj();
  Test t1;
  t1 = t0;
  t1.print_obj();
  return 0;
}
