/******************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/c-tutorial-struct/problem?isFullScreen=true
 * 
 * Problem : Create a strucutre Student containing 4 fields,
 *           - age : an integer
 *           - first_name : a string, all lower-case latin characters ('a'-'z') whith no more than 50 
 *                          characters.
 *           - last_name :  a string, all lower-case latin characters ('a'-'z') whith no more than 50
 *                          characters.
 *           - standard : an integer
 *******************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @brief Structure defining a student
 */
typedef struct Student {
    int age;            /**< Age of the student */
    string first_name;  /**< Fist name of the student */
    string last_name;   /**< Last name of the student */
    int standard;       /**< Student's standard */
}Student;

int main() {
    Student st;
    
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    
    return 0;
}