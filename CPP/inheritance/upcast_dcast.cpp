#include <iostream>
using namespace std;

class Parent {
public:
 void sleep() {}
};
class Child: public Parent {
public:
 void gotoSchool(){}
};
int main( )
{
 Parent parent;
 Child child;
 // upcast - implicit type cast allowed
 Parent *pParent = &child;
 // downcast - explicit type case required
 Child *pChild =  (Child *) &parent;
 pParent -> sleep();
 pChild -> gotoSchool();
 return 0;
}
