#include<iostream>
using namespace std;

class base{};
class derived_PUBLIC: public base{}; //public inheritance
class derived_PRIVATE: private base{}; //private inheritance

//functions defined as below
void f_base(const base& b){}; //function taking base type object
void f_dpublic(const derived_PUBLIC& dpub){}; //function taking derived public object
void f_dprivate(const derived_PRIVATE& dpriv){}; // function taking derived private object


int main(){

base b;
derived_PUBLIC dPublic;
derived_PRIVATE dPrivate;

//showing public inheritance
f_base(b); //GOOD: because b is of type base
f_base(dPublic); // GOOD: dPublic type object is converted to base type
f_dpublic(dPublic); // GOOD: dPublic type object

//showing private inheritance
f_dprivate(dPrivate); // GOOD: dPrivate type object
//f_base(dPrivate); // ERROR!! because dPrivate is not of type base

return 0;
}
