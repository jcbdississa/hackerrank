/****************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/vector-erase/problem?isFullScreen=true
 * 
 * Problem : You are provided with a vector of N integers. Then, you are given 2 queries. For the
 *           first query, you are provided with 1 integer, which denotes a position in the vector. The
 *           value at this position in the vector needs to be erased. The next query consists of 2
 *           integers denoting a range of the positions in the vector. The elements which fall under
 *           that range should be removed. The second query is performed on the updated vector which
 *           we get after performing the first query.
 *****************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, val, index, end_index;
    vector<int> v;
    cin>>N;
    for(int i = 0; i < N; i++) {
        cin>>val;
        v.push_back(val);
    }
    cin>>index;
    v.erase(v.begin() + index - 1);
    cin>>index>>end_index;
    v.erase(v.begin() + index - 1, v.begin() + end_index -1);
    cout<<v.size()<<endl;
    for(int value:v)
        cout<<value<<" ";

    return 0;
}