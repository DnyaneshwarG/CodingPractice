#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include<algorithm>

using namespace std;

int main()
{ 
    deque<int> dq(5);
    
    cout << "Deque Example:" << endl;
    for (int i = 0; i < 5; i++) {
        dq[i] = i + 1;
    }
    dq.push_back(10);
    dq.push_front(100);
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";
    }
    
    if (!dq.empty())
      cout << "\nDeque is not empty, size = " << dq.size();

    cout << "\n\nVector Example:" << endl;
    vector<int> vc(5);

    vc.resize(7);
    for (int i = 0; i < vc.size(); i++) {
        vc[i] = i + 1;
    }
    vc.push_back(6);
    auto it = vc.begin()+2;
    vc.insert(it, 2, 333);
    vc.insert(vc.begin()+5, 555);
    for (auto it = vc.begin(); it != vc.end(); it++) {
        cout << *it << " ";
    }
    if (!vc.empty())
      cout << "Vector is not empty, size = " << vc.size();

    cout << "\n\nLists Example:" << endl;
    list<int> lst;

    for (int i = 0; i < 5; i++) {
        lst.push_back(i+1);
    }

    for (auto it = lst.begin(); it != lst.end(); it++) {
       cout << *it << " "; 
    }
    list<int>::iterator lst_it = find(lst.begin(), lst.end(), 4);
    cout << "\nFound item: " << *lst_it;

    cout << endl << endl;
    return 0;
}

