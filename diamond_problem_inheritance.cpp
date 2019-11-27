#include<iostream>
using namespace std;

/*
 * Multiple Inheritance Situation
 *
 *      /------Base1------------------------\
 *     /         A(),B()				 	 \
 *   Root                                  Derived
 * 	   \							     	 /
 *      \------Base2------------------------/
 *              A(),C()
*/

class Root {
	int root_variable=100;
public:
	Root(){ cout << "Default Root constructor"<<endl; }
	Root(int r) : root_variable(r) {cout << "Root constructor Root("<<r<<")"<< endl; }
	void get_root(){cout<<"root_variable="<<root_variable<<endl;}
};

//-------------------------------------------
//----------Non virtual inheritance
//-------------------------------------------

class Base1: public Root {
public:
	Base1(){ cout << "Default Base1 constructor"<<endl; }
	Base1(int x):Root(x){cout << "Base1 constructor Base1("<<x<<")"<<endl;}
};

class Base2: public Root {
public:
	Base2(){ cout << "Default Base2 constructor"<<endl; }
	Base2(int x):Root(x){cout << "Base2 constructor Base2("<<x<<")"<<endl;}
};

class Derived:public Base1, public Base2{
public:
	Derived(){ cout << "Default Derived constructor"<<endl; }
	Derived(int x,int y):Base1(x),Base2(y){cout << "Derived constructor Derived("<<x<<","<<y<<")"<<endl;}
};

//---------------------------------------------
//---------------Virtual Inheritance
//---------------------------------------------

class Base1_virtual: virtual public Root {
public:
	Base1_virtual(){ cout << "Default Base1_virtual constructor"<<endl; }
	Base1_virtual(int x):Root(x){cout << "Base1_virtual constructor Base1_virtual("<<x<<")"<<endl;}
};

class Base2_virtual: virtual public Root  {
public:
	Base2_virtual(){ cout << "Default Base2_virtual constructor"<<endl; }
	Base2_virtual(int x):Root(x){cout << "Base2_virtual constructor Base2_virtual("<<x<<")"<<endl;}
};

class Derived_virtual:public Base1_virtual, public Base2_virtual{
public:
	Derived_virtual(){ cout << "Default Derived_virtual constructor"<<endl; }
	Derived_virtual(int x,int y):Base1_virtual(x),Base2_virtual(y){cout << "Derived_virtual constructor Derived_virtual("<<x<<","<<y<<")"<<endl;}
};


int main() {
	cout <<"******non-virtual derived default*******"<<endl;
	Derived d;
	//d.get_root();//error: request for member 'get_root' is ambiguous

	cout <<"******non-virtual derived & initialized*******"<<endl;
	Derived d1(1,2);

	cout <<"********virtual derived default**********"<<endl;
	Derived_virtual d_virt;
	d_virt.get_root();

	cout <<"********virtual derived & initialized**********"<<endl;
	Derived_virtual d1_virt(1,2);
	d_virt.get_root();
}
