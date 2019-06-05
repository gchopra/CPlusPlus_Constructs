#include<iostream>
using namespace std;

class Base{
	public:
		void nonVirtual(){cout<<"Base::nonVirtual"<<endl;}
		virtual void Virtual(){cout<<"Base::Virtual"<<endl;}
};


class Derived:public Base{
	public:
		void nonVirtual(){cout<<"Derived::nonVirtual"<<endl;}
		virtual void Virtual(){cout<<"Derived::Virtual"<<endl;}
};

int main(){
	Base b;
	Derived d;

	Base *base_ptr; //pointer is of type base class

	//static follows
	base_ptr = &b;
	base_ptr->nonVirtual(); //static binding decided on type of pointer  -- prints Base::nonVirtual
	base_ptr = &d;
	base_ptr->nonVirtual(); //static binding decided on type of pointer  -- prints Base::nonVirtual

	//dynamic follows
	base_ptr = &b;
	base_ptr->Virtual(); //dynamic binding decided on type of object  -- prints Base::Virtual
	base_ptr = &d;
	base_ptr->Virtual(); //dynamic binding decided on type of object  -- prints Derived::Virtual
}
