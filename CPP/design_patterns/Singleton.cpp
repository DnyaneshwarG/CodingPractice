#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Singleton {
  private:
    int data;
    Singleton() {
      data = 0;
    }
    static Singleton *instance;

  public:
    static Singleton* getInstance() {
        if (!instance) {
          instance = new Singleton();
        }
        return instance;
    }
    int getData() {
      return data;
    }
    void setData(int d) {
      data = d;
    }
};
Singleton* Singleton::instance = 0;

int main()
{
    Singleton *obj = Singleton::getInstance();
    obj->setData(11111);
    cout << "data= " << obj->getData();    

    cout << endl;
    return 0;
}

