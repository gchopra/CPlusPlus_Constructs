#include<iostream>
using namespace std;

/* Constant Casting Examples*/

void print(char * str){cout << str<<endl;}

class A {
	int __i;
public:
	A(int i):__i(i){} //need a default constructor for constant objects
	void set(int j){__i=j;}
	void printI() const {cout<<__i<<endl;} // const function fro const obj
};


int main(){


	//Example1=>constant string to non-constant string
	const char * c = "constant string";
	//print(c);//error: invalid conversion from 'const char*' to 'char*'
	print(const_cast<char*>(c));


	//Example2=>creating non-constant reference to an object
	const A constObject(10);
	constObject.printI();//OK as function is constant
	//constObject.set(100);//error: passing 'const A' as 'this' argument of 'void A::set(int)' discards qualifiers
	const_cast<A&>(constObject).set(100);//works because non-const reference
	constObject.printI();

}

