#include<iostream>
using namespace std;

class singletonCandyBox {
	static int candyCount; //Total candy fixed
	int getCandy;

	//make constructor private
	singletonCandyBox(int gc=0):getCandy(gc){
		cout<<"constructor:Candy Box opened"<<endl;
		cout<<"constructor:Candy in the box="<<candyCount<<endl;
		cout<<"constructor:Candy being taken="<<getCandy<<endl;

	}
	static singletonCandyBox *boxOpen; //static box opener
public:

	//destructor is public
	~singletonCandyBox(){
		cout<<"destructor:closing candybox"<<endl;
	}

	//static function to access static box opener
	static const singletonCandyBox& openCandyBox(int gc = 0){
		if(!boxOpen){
			boxOpen = new singletonCandyBox(gc);
			cout<<"got access to box opener"<<endl;
		}
		return *boxOpen;
	}
	void takeCandy(int num) const {
		candyCount -= num;
		cout<<"taking away this much candy="<<num<<endl;
		cout<<"remaining candy="<<candyCount<<endl;
	}
};

int singletonCandyBox::candyCount = 100; // Global candy count
singletonCandyBox *singletonCandyBox::boxOpen = 0; // by default box is closed

int main(){
	singletonCandyBox::openCandyBox().takeCandy(0);
	singletonCandyBox::openCandyBox().takeCandy(10);
	singletonCandyBox::openCandyBox().takeCandy(20);
	singletonCandyBox::openCandyBox().~singletonCandyBox();
	return 0;
}
