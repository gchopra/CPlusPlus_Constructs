#include<iostream>
using namespace std;

/*
 * Multiple Inheritance Situation
 *
 * Base1-----------------------\
 *  A(),B()						\
 *                            Derived
 * 								/
 * Base2-----------------------/
 *  A(),C()
*/

class Base1{
public:
	void A(){cout<<"A from Base1"<<endl;}
	void B(){cout<<"B"<<endl;}
};

class Base2{
public:
	void A(){cout<<"A from Base2"<<endl;}
	void C(){cout<<"C"<<endl;}
};

class Derived_ambiguous: public Base1, public Base2{

};

class Derived_unambiguous: public Base1, public Base2{
public:
	using Base1::A;
};


int main(){
	Derived_ambiguous d_ambi;
	Derived_unambiguous d_unambi;

	//d_ambi.A();//error: request for member 'A' is ambiguous
	d_unambi.A();//A from Base1

	//explicit call still possible
	d_unambi.Base2::A();//A from Base2

	d_ambi.B();//prints B
	d_unambi.B();//print B

	d_ambi.C();//prints C
	d_unambi.C();//prints C

}
