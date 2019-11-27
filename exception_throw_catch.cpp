#include<iostream>
using namespace std;

/*
The sequence of throw
A_thrower()  ----->  B() ------> main()
*/

class dumb_class{public:
	~dumb_class(){cout<<"dumb_class destructed"<<endl;}
	dumb_class(){cout<<"dumb_class constructed"<<endl;}
};

void A_thrower(){
	dumb_class dumb;
	//throw(5);//goes to caught integer
	//throw(1.5);//caught double
	throw dumb_class();//default catch
}

void B(){
	dumb_class dumb;
	try {A_thrower();}
	catch(int){cout<<"caught integer"<<endl;}
	catch(double){cout<<"caught double"<<endl;}
}

int main(){
	try {B();}
	catch(...){cout<<"Default catch"<<endl;} //ellipses to catch unmatched
}
