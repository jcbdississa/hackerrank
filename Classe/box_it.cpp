/****************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/box-it/problem?isFullScreen=true
 * 
 * Problem : Design a class named Box whose dimensions are integers and private to the class. The 
 *           dimensions are labelled: length l, breadth b and height h.
 *           The default constructor of the class should initialize l, b and h to 0 and the paramete-
 *           rized constructor Box(int length, int breadth, int height) should initialized Box's l, b
 *           and h to length, breadth and height. The copy constructor Box(Box B) should set l, b and
 *           h to B's l, b and h respectively.
 *           Appart from the above, the class should have 4 functions
 *           - int getLength() - Return box's length
 *           - int getBreadth() - Return box's breadth
 *           - int getHeight() - Return box's height
 *           - long long CalculateVolume() - Return the volume of the box
 *           Overload the operator < for the class Box. Box A < Box B if:
 *           1 - A.l < B.l
 *           2 - A.b < B.b and A.l == B.l
 *           3 - A.h < B.h and A.b == B.b and A.l == B.l
 *           Overload operator << for the class Box() so that if B is an object of class Box,
 *           cout<<B should print B.l, B.b and B.h on a single line separated by spaces
 *****************************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Box {
private:
    int b, l, h;
public:
/* ****************************** Constructors ***************************************** */

    /**
     * @brief Default constructor
     * 
     * Set all attributs to 0
     */
    Box() {
        this->l = 0;
        this->b = 0;
        this->h = 0;
    }

    /**
     * @brief Parameterized constructor
     * 
     * Should be given initalization's values
     * 
     * @param[in] length  Length of the box
     * @param[in] breadth Breadth of the box
     * @param[in] height  Height of the box
     */
    Box(int length, int breadth, int height) {
        this->l = length;
        this->b = breadth;
        this->h = height;
    }

    /**
     * @brief Copy constructor
     * 
     * Should be given initalization's values
     * 
     * @param[in] B Box used for intitialization
     */
    Box(Box& B) {
        this->l = B.getLength();
        this->b = B.getBreadth();
        this->h = B.getHeight();
    }

/* ****************************** Getters ***************************************** */

    int getLength() { return this->l; }
    int getBreadth() { return this->b; }
    int getHeight() { return this->h; }

/* ****************************** Facilitators ***************************************** */

    long long CalculateVolume() { return (long long)this->l * this->b * this->h; }

    bool operator<(Box& B) {
        if (this->l < B.getLength())
            return true;
        else if ((this->b < B.getBreadth()) && (this->l == B.getLength()))
            return true;
        else if ((this->h < B.getHeight()) && (this->b == B.getBreadth()) && (this->l == B.getLength()))
            return true;
        else
            return false;
    }

    friend ostream& operator<<(ostream& out, Box& B);
};

ostream& operator<<(ostream& out, Box& B) {
    out<<B.getLength()<<" "<<B.getBreadth()<<" "<<B.getHeight()<<endl;

    return out;
}

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main() {
    check2();

    return 0;
}

/* Corner case input
6
2 1039 3749 8473
4
3 1456 3836 283
3 729 3749 272
2 4839 283 273
4


1039 3749 8473
33004122803
Greater
Lesser
4839 283 273
373856301

*/