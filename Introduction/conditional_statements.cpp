/**********************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem?isFullScreen=true
 * 
 * Problem : Given a positive integer , do the following:
 *              * if 1 <= n <=9, then print the English representation of it in lowercase. That is "one"
 *                for 1, "two" for 2 and so on.
 *              * Else if n > 9, print "Greater than 9"
 ***********************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*************************************************************************
 * @brief Gives the corresponding lower case string of a number
 * 
 * @param[in] numb : The number to transform
 * 
 * @return The corresponding string if successful, "" otherwise
 *************************************************************************/
string string_version_of(int numb);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    scanf("%d", &n);
    if ((n >= 1) && (n <= 9))
        cout<<string_version_of(n)<<endl;
    else
        cout<<"Greater than 9"<<endl; 
    return 0;
}

string string_version_of(int numb) {
    string res = "";
    switch (numb) {
        // case 0:
        //     res.assign("zero");
        // break;
        case 1:
            res.assign("one");
        break;
        case 2:
            res.assign("two");
        break;
        case 3:
            res.assign("three");
        break;
        case 4:
            res.assign("four");
        break;
        case 5:
            res.assign("five");
        break;
        case 6:
            res.assign("six");
        break;
        case 7:
            res.assign("seven");
        break;
        case 8:
            res.assign("eight");
        break;
        case 9:
            res.assign("nine");
        break;
    default:
        printf("ERROR: %d is not a positive digit\n", numb);
        break;
    }

    return res;
}