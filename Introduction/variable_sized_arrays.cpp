/**************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/variable-sized-arrays/problem?isFullScreen=true
 * 
 * Problem : The first line contains two space-separated integers denoting the respective values
 *           of n (the number of variable-length arrays) and q (the number of queries).
 *           Each line i of the n subsequent lines contains a space-seperated sequence in the
 *           format k a[i]0 a[i]1 ... a[i]k-1 describing the k-element array located at a[i].
 *           Each of the q subsequent lines contains two space-seperated integers describing the
 *           respective values of i (an index in array a) and j (an index in the array reference
 *           by a[i]) for a query.
 **************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q, k, val, ind_i, ind_j;   
    int **a;
    cin>>n>>q;
    int rep[q];
    a = (int **)malloc(n*sizeof(int *));
    for (int i = 0; i < n; i++) {
        cin>>k;
        int *a_i = (int *)malloc(k*sizeof(int));
        for (int j = 0; j < k; j++) {
            cin>>a_i[j];
        }
        a[i] = a_i;
    }

    for(int l = 0; l < q; l++) {
        cin>>ind_i>>ind_j;
        rep[l] = a[ind_i][ind_j];
    }

    for(int l = 0; l < q; l++) {
        printf("%d\n", rep[l]);
    }

    return 0;
}