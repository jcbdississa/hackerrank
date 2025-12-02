/********************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem?isFullScreen=true
 * 
 * Problem : Input consists of the following space-separated values: int, long, char, float, and double,
 *           respectively.
 *           Print each element on a new line in the same order it was received as input. Note that the
 *           floating point value should be correct up to 3 decimal places and the double to 9 decimal
 *           places.
 *********************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int a; long b; char c; float d; double e;
    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);
    printf("%d\n%ld\n%c\n%f\n%lf\n", a, b, c, d, e);

    return 0;
}