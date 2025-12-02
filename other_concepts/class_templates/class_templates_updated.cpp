#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;


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
    int lengh_;
    AddElements(string element) {
         element_ = (char *)element.data();
         lengh_ = element.size();
    }
    char* concatenate(string second_element) {
        unsigned int i = 0;
        while (i < second_element.size()) {
            element_[lengh_ + i] = second_element[i];
            i++;
        }
        element_[lengh_ + second_element.size()] = '\0';
        
        return element_;
    }
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

/*
Sample input
3
string John Doe
int 1 2
float 4.0 1.5

Sample output
JohnDoe
3
5.5
*/