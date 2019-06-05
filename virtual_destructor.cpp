#include<iostream>
using namespace std;

//Non virtual destructor classes
class Base_nonVirtual{
public:
	Base_nonVirtual(){cout<<"Base_nonVirtual()"<<endl;}
	~Base_nonVirtual(){cout<<"~Base_nonVirtual()"<<endl;}
};
class Derived_nonVirtual : public Base_nonVirtual{
public:
	Derived_nonVirtual(){cout<<"Derived_nonVirtual()"<<endl;}
	~Derived_nonVirtual(){cout<<"~Derived_nonVirtual()"<<endl;}
};

//Virtual destructor classes
class Base_Virtual{
public:
	Base_Virtual(){cout<<"Base_Virtual()"<<endl;}
	virtual ~Base_Virtual(){cout<<"~Base_Virtual()"<<endl;} //virtual destructor
};

class Derived_Virtual : public Base_Virtual{
public:
	Derived_Virtual(){cout<<"Derived_Virtual()"<<endl;}
	~Derived_Virtual(){cout<<"~Derived_Virtual()"<<endl;}
};

int main(){

	cout<<"when base class destrucor is non-Virtual"<<endl;
	Base_nonVirtual *p = new Base_nonVirtual;	//Base_nonVirtual()
	Base_nonVirtual *q = new Derived_nonVirtual;	//Base_nonVirtual(), Derived_nonVirtual()
	delete p;	//~Base_nonVirtual()
	delete q;	//~Base_nonVirtual()

	cout<<"when base class destrucor is Virtual"<<endl;
	Base_Virtual *pVirtual = new Base_Virtual;	//Base_Virtual()
	Base_Virtual *qVirtual = new Derived_Virtual;	//Base_Virtual(),Derived_Virtual()
	delete pVirtual;	//~Base_Virtual()
	delete qVirtual;	//~Derived_Virtual(),~Base_Virtual()

	return 0;
}

