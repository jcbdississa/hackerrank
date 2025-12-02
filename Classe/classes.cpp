/******************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/c-tutorial-class/problem?isFullScreen=true
 * 
 * Problem : Create a class Student containing 4 variables,
 *           - age : an integer
 *           - first_name : a string, all lower-case latin characters ('a'-'z') whith no more than 50 
 *                          characters.
 *           - last_name :  a string, all lower-case latin characters ('a'-'z') whith no more than 50
 *                          characters.
 *           - standard : an integer
 *           And getters and setters for each of these variables, the naming convention of theses
 *           functions is get_<variable name> for getters and set_<variable name> for setters
 *           You also need to create a method "to_string" which returns all the attributs of the
 *           separated by a comma in one string ("age,first_name,last_name,standard")
 *******************************************************************************************************/

#include <iostream>
#include <sstream>
using namespace std;


/**
 * @brief A class representing a student
 */
class Student {
private:
    int age_;
    string first_name_;
    string last_name_;
    int standard_; /**< Representing the level of the student */

public:
/******************************* Getters ***************************************** */

    int get_age() { return this->age_; }
    string get_first_name() { return this->first_name_; }
    string get_last_name() { return this->last_name_; }
    int get_standard() { return this->standard_; }

/******************************* Setters ***************************************** */

    void set_age(int age) { this->age_ = age; }
    void set_first_name(string first_name) { this->first_name_ = first_name; }
    void set_last_name(string last_name) { this->last_name_ = last_name; }
    void set_standard(int standard) { this->standard_ = standard; }

/******************************* Facilitators ***************************************** */

    /**
     * @brief Return all the attributs of the student in a single string
     * 
     * @return The formatted string
     */
    string to_string() {
        string student_info;
        stringstream ss;
        ss<<this->age_<<","<<this->first_name_<<","<<this->last_name_<<","<<this->standard_<<endl;
        ss>>student_info;

        return student_info;
    }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}