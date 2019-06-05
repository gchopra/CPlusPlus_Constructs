#include<iostream>
using namespace std;

//PUBLIC inheritance chain
class Bpub{
public:
	Bpub(){ cout<<"Bpub ";}
	~Bpub() {cout << "~Bpub "<<endl;}
};

class Cpub{
public:
	Cpub(){ cout<<"Cpub ";}
	~Cpub() {cout << "~Cpub ";}
};

class Dpub: public Bpub{
	Cpub data;
public:
	Dpub(){ cout<<"Dpub "<<endl;}
	~Dpub() {cout << "~Dpub ";}
};


//PRIVATE inheritance chain
class Bpriv{
public:
	Bpriv(){ cout<<"Bpriv ";}
	~Bpriv() {cout << "~Bpriv "<<endl;}
};

class Cpriv: public Bpriv{
public:
	Cpriv(){ cout<<"Cpriv ";}
	~Cpriv() {cout << "~Cpriv ";}
};

class Dpriv: private Cpriv{
public:
	Cpriv data;
	Dpriv(){ cout<<"Dpriv "<<endl;}
	~Dpriv() {cout << "~Dpriv ";}
};


int main() {
	cout <<"Public object trace"<<endl;
	Dpub d1;

	cout <<"Private object trace"<<endl;
	Dpriv d2;
	return 0;
}
