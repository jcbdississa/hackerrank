/**************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/c-tutorial-strings/problem?isFullScreen=true
 * 
 * Problem : You are given two strings, a and b, separated by a new line. Each string will consist
 *           of lower case Latin characters ('a'-'z').
 *           In the first line print two space-separated integers, representing the length of a and
 *           b respectively. In the second line print the string produced by concatenating a and b
 *           (a + b). In the third line print two strings separated by a spac. a' and b' are the 
 *           same as a and b respectively, except that their first characters are swapped.
 **************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a, b;
    cin>>a>>b;
    cout<<a.size()<<" "<<b.size()<<endl;
    cout<<a + b<<endl;
    char c = a[0];
    a[0] = b[0];
    b[0] = c;
    cout<<a<<" "<<b<<endl;
    return 0;
}