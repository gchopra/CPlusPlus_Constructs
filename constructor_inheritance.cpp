#include<iostream>
using namespace std;

/*
 * B is the base class
 * D is the derived class
 * This shows the sequence of inheritance with constructor and destructor
 * Class D will have objects that have instance of base in them
 */

class B{
protected:
	int data;
public:
	B(int d=0): data(d){cout<<"B::B(int):"<<data<<endl;}
	~B(){cout<<"B::~B():"<<data<<endl;}
};

class D:public B {
	int info;
public:
	D(int d, int i): B(d), info(i){//explicit construction of Base B
		cout << "D:D(int,int):"<<data<<" "<<info<<endl;
	}
	D(int i): info(i){ //default construction of base B -- if B didn't have default param data=0 , this would error out
		cout<<"D::D(int):"<<data<<" "<<info<<endl;
	}
	~D(){cout <<"D::~D()"<<data<<" "<<info<<endl;}
};

int main(){
	B b(10);
	D d1(20,30);
	D d2(40);
	return 0;
}
