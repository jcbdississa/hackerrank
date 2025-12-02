#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;

/*Write the class AddElements here*/
template <class T>
class AddElements {
    public:
    T element_;
    AddElements(T element) {element_ = element;}
    T add(T second_element) { return  element_ + second_element;}
};

template<>
class AddElements<string> {
public:
    char* element_;
    AddElements(string element) { element_ = (char *)element.c_str();}
    char* concatenate(string second_element) { return strcat(element_, second_element.c_str());}
};
int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}