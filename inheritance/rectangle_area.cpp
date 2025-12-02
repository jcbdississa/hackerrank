/****************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/rectangle-area/problem?isFullScreen=true
 * 
 * Problem : Create 2 classes, the first class, Rectangle should have two data fields-width and
 *           height of int types. The class should have display() method, to print the width and
 *           height of the rectangle separated by space. The second class RectangleArea is derived
 *           from Rectangle class, i.e., it is the sub-class of Rectangle class. The class should
 *           have read_input() method, to read the values of width and height of the rectangle. The
 *           RectangleArea class should also overload the display() method to print the area
 *           (width * height) of the rectangle.
 *           The input format is as follow, The first and only line of input contains two space
 *           separated integers denoting the width and height of the rectangle.
 *           The output format should consist of exactly 2 lines, in the first line, print the width
 *           and height of the rectangle separated by space. In the second line, print the area of the
 *           rectangle.
 *****************************************************************************************************/
#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle {
protected:
    int width, height;
public:
    void display() {
        cout<<this->width<<" "<<this->height<<endl;
    }
};

class RectangleArea: public Rectangle {
public:
    void read_input() {
        cin>>this->width>>this->height;
    }

    void display() {
        cout<<this->width * this->height<<endl;
    }
};

int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}