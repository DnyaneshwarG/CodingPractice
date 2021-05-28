#include <iostream>
#include <iterator>
#include <unordered_map>
#include <map>

using namespace std;

int main()
{
  unordered_map<int, int> mp;

  mp.insert(pair<int, int>(5,50));
  mp.insert(pair<int, int>(3,30));
  mp.insert(pair<int, int>(2,20));
  mp.insert(pair<int, int>(1,10));
  mp.insert(pair<int, int>(4,40));
  mp.insert(pair<int, int>(9,90));
  mp.insert(pair<int, int>(8,80));

  unordered_map<int, int>::iterator itr;

  for (itr = mp.begin(); itr != mp.end(); itr++) {
    cout<< itr->first << " " << itr->second << endl;
  }

  return 0;
}
