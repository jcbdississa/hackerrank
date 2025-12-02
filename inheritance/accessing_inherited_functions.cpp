/*********************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/accessing-inherited-functions/problem?isFullScreen=true
 * 
 * Problem : You need to modify the class D and implement the function update_val which sets D's val to
 *           new_val by manipulating the value by only calling the func defined in classes A, B and C.It
 *           is guaranteed that new_val has only 2, 3 and 5 as its prime factors.
 *********************************************************************************************************/
#include<iostream>
#include <chrono>

using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};

class D : public A, public B, public C 
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }


		 //Implement this function
		 void update_val(int new_val);
		 void update_val0(int new_val);

		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};



void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}

void D::update_val(int new_val) {
    // while (new_val - this->val) {
    //     if ((val*2 <= new_val) && (!(new_val%2))) {
    //         this->A::func(val);
    //     }
    //     if ((val*3 <= new_val) && (!(new_val%3))) {
    //         this->B::func(val);
    //     }
    //     if ((val*5 <= new_val) && (!(new_val%5))) {
    //         this->C::func(val);
    //     }
    // }
    while (new_val != 1)
    {
        if (new_val % 5 == 0)
        {
            C::func(val);
            new_val /= 5;
        }
        else if (new_val % 3 == 0)
        {
            B::func(val);
            new_val /= 3;
        }
        else if (new_val % 2 == 0)
        {
            A::func(val);
            new_val /= 2;
        }
    }
}
void D::update_val0(int new_val) {
    int mix = 1;
    if ((val*2 <= new_val) && (!(new_val%2))) {
        this->A::func(val);
        mix *= 2;
    }
    if ((val*3 <= new_val) && (!(new_val%3))) {
        this->B::func(val);
        mix *= 3;
    }
    if ((val*5 <= new_val) && (!(new_val%5))) {
        this->C::func(val);
        mix *= 5;
    }
    switch (mix) {
        case 30:
            while(new_val - val) {
                if (val*2 <= new_val)
                    this->A::func(val);
                if (val*3 <= new_val) 
                    this->B::func(val);
                if (val*5 <= new_val)
                    this->C::func(val);
            }                
        break;
        case 6:
            while(new_val - val) {
                if (val*2 <= new_val)
                    this->A::func(val);
                if (val*3 <= new_val) 
                    this->B::func(val);
            }                
        break;
        case 10:
            while(new_val - val) {
                if (val*2 <= new_val)
                    this->A::func(val);
                if (val*5 <= new_val)
                    this->C::func(val);
            }                
        break;
        case 15:
            while(new_val - val) {
                if (val*3 <= new_val) 
                    this->B::func(val);
                if (val*5 <= new_val)
                    this->C::func(val);
            }                
        break;
        case 2:
            while(new_val - val) {
                if (val*2 <= new_val)
                    this->A::func(val);
            }                
        break;
        case 3:
            while(new_val - val) {
                if (val*3 <= new_val) 
                    this->B::func(val);
            }               
        break;
        case 5:
            while(new_val - val) {
                if (val*5 <= new_val)
                    this->C::func(val);
            }                
        break;
        default:
        break;
    }
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);
}