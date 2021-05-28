#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main()
{
  set<int> s1 = {30, 10, 20, 9, 50};
  s1.insert(100);
  for (auto i = s1.begin(); i != s1.end(); i++) {
    cout << *i << " ";
  }
  return 0;
}
