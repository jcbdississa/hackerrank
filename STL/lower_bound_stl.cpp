/****************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/cpp-lower-bound/problem?isFullScreen=true
 * 
 * Problem : You are given N integers in sorted order. Also, you are given Q queries. In each query,
 *           you will be given an integer and you have to tell whether that integer is present in the
 *           array. If so, you have to tell at which index it is present and if it is not present, you
 *           have to tell the index at which the smallest integer that is just greater than the given
 *           number is present.
 *           Lower bound is a function that can be used with a sorted vector. Learn how to use lower
 *           bound to solve this problem in https://cplusplus.com/reference/algorithm/lower_bound/ 
 *****************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, Q, Y, val;
    vector<int> v;
    vector<int>::iterator low;
    cin>>N;
    for(int i = 0; i < N; i++) {
        cin>>val;
        v.push_back(val);
    }
    cin>>Q;
    for(int i = 0; i < Q; i++) {
        cin>>Y;
        low = lower_bound(v.begin(), v.end(), Y);
        cout<<(*low == Y ? "Yes " : "No ")<<(low -v.begin() + 1)<<endl;
    }
    return 0;
}
