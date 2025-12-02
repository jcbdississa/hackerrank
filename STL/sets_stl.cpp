/****************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/cpp-sets/problem?isFullScreen=true
 * 
 * Problem : Coming to the problem, you will be given Q queries. Each query is of one of the following
 *           three types:
 *           1 x : Add an element x to the set
 *           2 x : Delete an element x x from the set. If the number x is not present in the set,
 *                 then do nothing.
 *           3 x : If the number x is present in the set, then print "Yes"(without quotes) else print
 *                 "No"(without quotes).
 *****************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    set<int> s;
    int Q, y, x;
    cin>>Q;
    for(int i = 0; i < Q; i++) {
        cin>>y>>x;
        if (y ==1) {
            s.insert(x);
        } else if (y == 2) {
            s.erase(x);
        } else {
            cout<<(s.find(x) == s.end() ? "No" : "Yes")<<endl;
        }
    }
    return 0;
}