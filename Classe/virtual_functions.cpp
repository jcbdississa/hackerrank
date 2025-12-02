/****************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/virtual-functions/problem?isFullScreen=true
 * 
 * Problem : This problem is to get you familiar with virtual functions. Create three classes Person,
 *           Professor and Student. The class Person should have data members name and age. The 
 *           classes Professor and Student should inherit from the class Person. The class Professor
 *           should have two integer members: publications and cur_id. There will be two member
 *           functions: getdata and putdata. The function getdata should get the input from the user:
 *           the name, age and publications of the professor. The function putdata should print the
 *           name, age, publications and the cur_id of the professor. The class Student should have
 *           two data members: marks, which is an array of size 6 and cur_id. It has two member
 *           functions: getdata and putdata. The function getdata should get the input from the user:
 *           the name, age, and the marks of the student in 6 subjects. The function putdata should
 *           print the name, age, sum of the marks and the cur_id of the student. For each object
 *           being created of the Professor or the Student class, sequential id's should be assigned
 *           to them starting from 1.
 *           Solve this problem using virtual functions, constructors and static variables. You can
 *           create more data members if you want.
 *****************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @brief Class describing a person
 */
class Person {
protected:
    string name;
    int age;
public:
/* ****************************** Constructors ***************************************** */

/* ****************************** Setters ***************************************** */
    /**
     * @brief Setting basic information about a person
     */
    virtual void getdata(void) = 0;

/* ****************************** Getters ***************************************** */
    /**
     * @brief Display information about a person
     */    
    virtual void putdata(void) = 0;
};


/**
 * @brief Class describing a professor
 */
class Professor: public Person {
private:
    static int number_of_professors; /**< Giving the number of professors */
    int cur_id;                      /**< Giving the index of the current professor */
    int publications;                /**< Number of publications of the professor */
public:
/* ****************************** Constructors ***************************************** */

    /**
     * @brief Default constructor
     */
    Professor() {
        number_of_professors++;
        cur_id = number_of_professors;
    }

/* ****************************** Setters ***************************************** */

    /**
     * @brief Setting basic information about a professor
     */
    void getdata(void) {
        cin>>this->name>>this->age>>this->publications;
    }

/* ****************************** Getters ***************************************** */

    /**
     * @brief Display information about a professor
     */
    void putdata(void) {
        cout<<this->name<<" "<<this->age<<" "<<this->publications<<" "<<this->cur_id<<endl;
    }
};

/**
 * @brief Class describing a student
 */
class Student: public Person {
private:
    static int number_of_students; /**< Giving the number of students */
    int cur_id;                    /**< Giving the index of the current student */
    int marks[6];                  /**< List of student's scores */
public:
/* ****************************** Constructors ***************************************** */

    /**
     * @brief Default constructor
     */
    Student() {
        number_of_students++;
        this->cur_id = number_of_students;
    }

/* ****************************** Setters ***************************************** */

    /**
     * @brief Setting basic information about a student
     */
    void getdata(void) {
        cin>>this->name>>this->age>>this->marks[0]>>this->marks[1]>>this->marks[2]>>this->marks[3]>>this->marks[4]>>this->marks[5];
    }

/* ****************************** Getters ***************************************** */

    /**
     * @brief Setting basic information about a student
     */
    void putdata(void) {
        int marks_sum = marks[0] + this->marks[1] + this->marks[2] + this->marks[3] + this->marks[4] + this->marks[5];
        cout<<this->name<<" "<<this->age<<" "<<marks_sum<<" "<<this->cur_id<<endl;
    }
};

int Professor::number_of_professors = 0;
int Student::number_of_students = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}