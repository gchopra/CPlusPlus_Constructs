#include<iostream>
using namespace std;

//abstract base class -- ABC
class vehicles{
public:
	virtual void drive() = 0; //PVF
};

void vehicles::drive()	{cout<<"initializing vehicles"<<endl;} //body of PVF to be defined separate

class two_wheels: public vehicles{}; //ABC

class four_wheels: public vehicles{}; //ABC

class gas_car:public four_wheels{ //Concrete Class
public:
	void drive(){cout<<"driving gas car"<<endl;}
};

class electric_car: public four_wheels{ //Concrete Class
public:
	void drive(){cout<<"driving electric car"<<endl;}
};

class cruiser_bike: public two_wheels{ //concrete class
public:
	void drive(){cout<<"riding cruiser bike"<<endl;}
};

class sport_bike: public two_wheels{ //concrete class
public:
	void drive(){cout<<"riding sport bike"<<endl;}
};

int main(){
	vehicles *v[]={new gas_car,new electric_car, new cruiser_bike, new sport_bike};
	for (int i=0;i<sizeof(v)/sizeof(vehicles*);i++){
		v[i]->drive();
		//(*v[i]).drive(); --> same as above (.) vs "->"
	}
	return 0;
}

