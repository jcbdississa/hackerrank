/****************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/classes-objects/problem?isFullScreen=true
 * 
 * Problem : Here a student want to know if she has shoot at being valedictorian of her high school,
 *           for that she need to compare her exam scores with other students. 
 *           So the task is to create a class with an instance variable named scores containing the
 *           five scores of the student, a void input() function that read 5 integers from the command
 *           line and stores them in scores and function int calculateTotalScore() that return the 
 *           sum of the student's scores.
 *****************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/**
 * @brief A class representing a student
 */
class Student {
private:
    int scores[5];
public:
/******************************* Setters ***************************************** */

    /** 
     * @brief Get the five scores of the student from the user
     * 
     * The values are stored internally
     */
    void input() {
        for (int i = 0; i < 5; i++) {
            cin>>this->scores[i];
        }
    }

    /**
     * @brief Return the sum of all the student's scores
     * 
     * @return The sum of the scores
     */
    int calculateTotalScore() {
        int total_score = 0;

        for (int i = 0; i < 5; i++) {
            total_score += this->scores[i];
        }

        return total_score;
    }
};

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}