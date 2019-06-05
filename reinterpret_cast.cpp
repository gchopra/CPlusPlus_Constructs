#include<iostream>
using namespace std;

/*unrelated classes A and B*/
class A{};
class B{};

int main(){

	A * ptrA; //pointer of type A
	B * ptrB; //pointer of type B

	//ptrA = ptrB;// error: cannot convert 'B*' to 'A*' in assignment
	ptrA = reinterpret_cast<A*>(ptrB);//GOOD -- but risky

}

