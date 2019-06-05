#include<iostream>
using namespace std;

class level_1{
public:
	void A() {cout <<"level_1::A()"<<endl;}
	virtual void B() {cout <<"level_1::B()"<<endl;}//virtual
	void C() {cout <<"level_1::C()"<<endl;}
};

class level_2 : public level_1{
public:
	void A() {cout <<"level_2::A()"<<endl;}
	void B() {cout <<"level_2::B()"<<endl;} //Remains virtual
	virtual void C() {cout <<"level_2::C()"<<endl;} //virtual
};

class level_3 : public level_2{
public:
	void A() {cout <<"level_3::A()"<<endl;}
	void B() {cout <<"level_3::B()"<<endl;} //Remains virtual
	void C() {cout <<"level_3::C()"<<endl;} //Remains virtual
};

int main(){
//	level_1 *p = new level_3;
//	level_2 *q = p; // ERROR: invalid conversion from 'level_1*' to 'level_2*'

	level_2 *p = new level_3;
	level_1 *q = p; //UPCAST level_2 type to level_1 type

/*
	p is type level_2 -------> pointing to level_3
	q is type level_1 -------> pointing to level_3
*/
	p->A();//prints-->level_2::A()
	p->B();//prints-->level_3::B()
	p->C();//prints-->level_3::C()

	q->A();//prints-->level_1::A()
	q->B();//prints-->level_3::B()
	q->C();//prints-->level_1::C()

	return 0;
}


