/****************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/cpp-sets/problem?isFullScreen=true
 * 
 * Problem : You are appointed as the assistant to a teacher in a school and she is correcting the
 *           answer sheets of the students.Each student can have multiple answer sheets.So the teacher
 *           has Q queries:
 *           1 X Y : Add the marks Y to the student whose name is X
 *           2 X : Erase the marks of the students whose name is X
 *           3 X : Print the marks of the student whose name is X. (if X didn't get any marks print 0)
 *****************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string, int> m;
    int Q, Y, type;
    string X;
    cin>>Q;
    for(int i = 0; i < Q; i++) {
        cin>>type;
        switch (type) {
            case 1:
                cin>>X>>Y;
                // if (!((m.try_emplace(X, Y)).second))
                //      m[X] += Y;                
                m[X] += Y;
            break;
            case 2:
                cin>>X;
                m[X] = 0;
            break;
            case 3:
                cin>>X;
                cout<<m[X]<<endl;
            break;
            default:
            break;
        }
    }
    return 0;
}