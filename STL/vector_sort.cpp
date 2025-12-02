/****************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/vector-sort/problem?isFullScreen=true
 * 
 * Problem : You are given N integers.Sort the N integers and print the sorted order. Store the N
 *           integers in a vector.Vectors are sequence containers representing arrays that can change
 *           in size.
 *****************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> v;
    int N, val;

    cin>>N;
    for(int i = 0; i < N; i++) {
        cin>>val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    for(int value:v) {
        cout<<value<<" ";
    }
    return 0;
}
