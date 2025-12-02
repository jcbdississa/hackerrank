/****************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/inheritance-introduction/problem?isFullScreen=true
 * 
 * Problem : You are given class: Triangle and Isoceles which inherits from Triangle, you need to
 *           create the function description so that the output on std output looks like this
 *           "   
 *           I am an isosceles triangle
 *           In an isosceles triangle two sides are equal
 *           I am a triangle
 *           "  
 *****************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Triangle{
    public:
    	void triangle(){
     		cout<<"I am a triangle\n";
    	}
};

class Isosceles : public Triangle{
    public:
    	void isosceles(){
    		cout<<"I am an isosceles triangle\n";
    	}
  		
        void description() {
            cout<<"In an isosceles triangle two sides are equal"<<endl;
        }
};

int main(){
    Isosceles isc;
    isc.isosceles();
  	isc.description();
    isc.triangle();
    return 0;
}