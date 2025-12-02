/**************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem?isFullScreen=true
 * 
 * Problem : You will be given two positive integers, a and b (a<b), separated by a newline.
 *           For each integer  in the inclusive interval [a, b]
 *              * if 1 <= n <=9, then print the English representation of it in lowercase. 
 *                That is "one" for 1, "two" for 2 and so on.
 *              * Else if n > 9 and it is an even number, then print "even"
 *              * Else if n > 9 and it is an odd number, then print "odd"
 **************************************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    // Complete the code.
    vector<string> vec = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int a, b;
    cin>>a;
    cin>>b;
    for(int i = a; i <= b; i++) {
        if ((i >= 1) && (i <= 9)) {
            cout<<vec[i]<<endl;
        } else {
            if (i%2)
                cout<<"odd"<<endl;
            else
                cout<<"even"<<endl;
        }
    }
    
    return 0;
}