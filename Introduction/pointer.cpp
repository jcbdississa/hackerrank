/**************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/c-tutorial-pointer/problem?isFullScreen=true
 * 
 * Problem : The function update is declared with a void return type, so there is no value to
 *           return. Modify the values in memory so that  contains their sum and  contains their
 *           absoluted difference.
 **************************************************************************************************/

 #include <stdio.h>
 #include <cmath>

void update(int *a,int *b) {
    // Complete this function
    int sum = *a + *b;        
    int sub = abs(*a - *b);
    *a = sum;
    *b = sub;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}