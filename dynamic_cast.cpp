#include<iostream>
using namespace std;

class A {public: virtual void funct1(){};};//poly-morphic
class B: public A{};//poly-morphic
class C {public: virtual void funct2(){};};//un-related

int main(){
A a; A * pA;
B b; B * pB;
C c; C * pC;
void * pV;

//UPCAST --> Successful casting!
pB = &b;
pA = dynamic_cast<A*>(pB);
(pA == pB)?(cout<<"Successful casting!"<<endl) : (cout<<"bad casting"<<endl);

//DOWNCAST when object is of target type --> Successful casting!
pA = &b;
pB = dynamic_cast<B*>(pA); //object is of target type
(pA == pB)?(cout<<"Successful casting!"<<endl) : (cout<<"bad casting"<<endl);

//DOWNCAST when object not of target type --> bad casting
pA = &a;
pB = dynamic_cast<B*>(pA); //object not of target type
(pA == pB)?(cout<<"Successful casting!"<<endl) : (cout<<"bad casting"<<endl);

//unrelated casting --> bad casting
pA = (A*)&c;
pC = dynamic_cast<C*>(pA);
(pA == pB)?(cout<<"Successful casting!"<<endl) : (cout<<"bad casting"<<endl);

//cast to void --> Successful casting!
pA = &a;
pV = dynamic_cast<void*>(pA);
(pA == pV)?(cout<<"Successful casting!"<<endl) : (cout<<"bad casting"<<endl);

}
