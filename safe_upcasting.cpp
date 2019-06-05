#include<iostream>
using namespace std;

class A {public: int dA;};
class B : public A {public: int dB;};

int main(){
	A a;//base class obj
	B b;//derived class obj

	a.dA=1;
	b.dA=2;
	b.dB=3;

	A *pa = &a;
	B *pb = &b;

	cout<<"pa->dA="<<pa->dA<<endl; // 1
	cout<<"pb->dA="<<pb->dA<<"  pb->dB="<<pb->dB<<endl; // 2 and 3

	pa = &b;
	cout<<"pa->dA="<<pa->dA<<endl;//2
	//cout<<"pa->dB"<<pa->dB<<endl; //ERROR: 'class A' has no member named 'dB'

	return 0;
}
