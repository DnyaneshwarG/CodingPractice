#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template <class T>
void hello(T t) 
{
  cout << "\nData = " << t;
}

template <class T>
class Array {
  T data;

  public:
    void setData(T t) {
      data = t;
    }
    void printData() {
      cout << "\nData = " << data << " ";
    }
};

int main()
{ 
    cout << "\nClass Template Example";
    Array<int> a0;
    a0.setData(500);
    a0.printData();

    Array<double> a1;
    a1.setData(500.32);
    a1.printData();

    cout << endl;
    cout << "\nFunction Template Example";
    hello(12);
    hello(12.23);

    cout << endl << endl;
    return 0;
}

