#include<iostream>
using namespace std;

/* Static Casting Examples*/

//dependent classes
class A{};
class B: public A{};

//unrelated classes
class A_unrelated{};
class B_unrelated{};

//unrelated but with constructor
class B_unrelatedConstructor{};
class A_unrelatedConstructor{
public:
	A_unrelatedConstructor(){cout<<"default B_unrealtedCosnt constructor"<<endl;}
	A_unrelatedConstructor(const B_unrelatedConstructor&){cout<<"got a B type object(B&)"<<endl;}
};


//unrelated but with conversion
class A_unrelatedConversion{};
class B_unrelatedConversion{
public:
	operator A_unrelatedConversion(){cout<<"conversion of B_unrelatedConversion to A_unrelatedConversion"<<endl;}
	operator int(){cout<<"conversion of B_unrelatedConversion to int"<<endl;}
};


int main(){

//--------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
	/*For dependent Classes*/

	A a;
	B b;

	//1....up-cast -- information lost
	A *p = &b;
	p = static_cast<A*>(&b);

	//2....down-cast -- garbage created
	//B *q = &a;//error: invalid conversion from 'A*' to 'B*'
	B *q = static_cast<B*>(&a);//OK but risky


//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
	/*For unrelated classes*/

	A_unrelated a_unrel;
	B_unrelated b_unrel;

	//a_unrel = b_unrel;//error: no match for 'operator=' in 'a_unrel = b_unrel'
	//a_unrel = static_cast<A_unrelated>(b_unrel);//error: no matching function for call to 'A_unrelated::A_unrelated(B_unrelated&)'


//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

	/*For unrelated-with-Constructor classes*/

	A_unrelatedConstructor a_unrelConstruct;
	B_unrelatedConstructor b_unrelConstruct;

	a_unrelConstruct = b_unrelConstruct;//GOOD: got a B type object(B&)
	a_unrelConstruct = static_cast<A_unrelatedConstructor>(b_unrelConstruct);//GOOD got a B type object(B&)


//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
	/*For unrelated-with-Conversion classes*/

	A_unrelatedConversion a_conv;
	B_unrelatedConversion b_conv;
	int i=100;

	a_conv = b_conv;//GOOD: conversion of B_unrelatedConversion to A_unrelatedConversion
	a_conv = static_cast<A_unrelatedConversion>(b_conv);//GOOD: conversion of B_unrelatedConversion to A_unrelatedConversion
	//i = a_conv;//error: cannot convert 'A_unrelatedConversion' to 'int' in assignment
	//i = static_cast<A_unrelatedConversion>(a_conv);//error: cannot convert 'A_unrelatedConversion' to 'int' in assignment
	i = b_conv;//GOOD:conversion of B_unrelatedConversion to int
	i = static_cast<B_unrelatedConversion>(b_conv);//GOOD:conversion of B_unrelatedConversion to int
}
