#include <iostream>
#include <iterator>
#include <unordered_map>
#include <map>

using namespace std;

int main()
{
  {
    cout << "\nunordered_map example : " << endl;
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

  }
  {
    cout << "\nmap of map example : " << endl;
    map< int, map<int, int>> mp1;
    mp1.insert(make_pair(10, map<int, int>()));
    mp1[10].insert(make_pair(22, 44));

    map<int, map<int, int>>::iterator itr;
    map<int, int>::iterator ptr;
    
    for (itr = mp1.begin(); itr != mp1.end(); itr++) {
      for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
        cout << itr->first << " : [ " << ptr->first << " : " << ptr->second << " ]" << endl;
      }
    }
  }
  return 0;
}
