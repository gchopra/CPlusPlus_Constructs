#include<iostream>
using namespace std;

/*
 * when binding is static -- the function it calls depends on the type of pointer
 * static == statically known during compile time
 * in case of dynamic binding -- the function it calls depends on the pointed object instead of the pointer type
 * dynamic == dynamically known during runtime
 * Virtual function causes dynamic binding
*/

class Base{
	public:
		void funcA(){cout<< "Base::funcA"<<endl;}
		virtual void funcB(){cout<< "Base::funcB"<<endl;} //virtual function
};

class Derived: public Base{
	public:
		void funcA(){cout<< "Derived::funcA"<<endl;}
		virtual void funcB(){cout<< "Derived::funcB"<<endl;} //virtual function
};

int main(){

	Base b;
	Derived d;

	//doing pointer based assignments
	Base *b_ptr = &b;
	Base *d_ptr = &d; //UPCAST

	//doing reference based assignments
	Base &b_ref = b;
	Base &d_ref = d; //UPCAST

	//call functions using objects
	b.funcA();
	b.funcB();
	d.funcA();
	d.funcB();

	//call functions using pointers
	b_ptr->funcA(); //static binding --> prints "Base::funcA" as pointer type is "Base"
	b_ptr->funcB(); //dynamic binding --> prints "Base::funcB" as pointed object is b of type "Base"
	d_ptr->funcA(); //static binding --> prints "Base::funcA" as pointer type is "Base"
	d_ptr->funcB(); //dynamic binding --> prints "Derived::funcB" as pointed object is d of type "Derived"

	//call functions using reference
	b_ref.funcA(); //static binding --> prints "Base::funcA" as pointer type is "Base"
	b_ref.funcB(); //dynamic binding --> prints "Base::funcB" as pointed object is b of type "Base"
	d_ref.funcA(); //static binding --> prints "Base::funcA" as pointer type is "Base"
	d_ref.funcB(); //dynamic binding --> prints "Derived::funcB" as pointed object is d of type "Derived"

	return 0;
}
