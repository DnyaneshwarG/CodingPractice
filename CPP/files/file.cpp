#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    char ch;
    fstream fin, fout;
    string str;

    cout << endl;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    while (!fin.eof()) {
      getline(fin, str);
      cout << str << "\n";
      fout << str << endl;
      //fin.get(ch);
      //cout << ch;
      //fout.put(ch);
    }
    cout << endl;
    fout.close();
    fout.open("output.txt", ios::in);

    cout << "\nOutput file is :" << endl;
    while (getline(fout, str)) {
      cout << str << endl;
    }

    fin.close();
    fout.close();

    cout << endl << endl;
    return 0;
}

