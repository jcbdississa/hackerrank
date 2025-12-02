/****************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem?isFullScreen=true
 * 
 * Problem : Complete the parseInts function that has the following parameters:
 *           string str : a string of comma separated integers
 *           The function returns a vector of the parsed integers
 *****************************************************************************************************/

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> v;
    int a; char c;
    stringstream ss(str);
    do {
        ss>>a;
        v.push_back(a);
    } while(ss>>c);

    return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}