/*****************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/arrays-introduction/problem?isFullScreen=true
 * 
 * Problem : The first line of the input contains N,where N is the number of integers.The next line
 *           contains N space-separated integers.
 *           Print the N integers of the array i the reverse order, space-seperated on a single line.
 *****************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin>>N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin>>arr[i];
    }
    for(int i = N - 1; i >= 0; i--) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}