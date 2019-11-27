#include<iostream>
#include <cstdlib>
//#define NDEBUG //If NDEBUG is defined before cassert include ... the assertion would be removed compile time
#include <cassert>
using namespace std;

void handle_1(void){
	cout <<"handle_1"<<endl;
}

void handle_2(void){
	cout <<"handle_2"<<endl;
}

int main(){

	cout<< "testing assert"<<endl;
	int test_variable = 1;
	assert(test_variable == 1);//OK
	//assert(test_variable == 0);//Assertion `test_variable == 0' failed.

	atexit(handle_1);
	atexit(handle_2);
	exit(EXIT_SUCCESS);
//	If exit_code is 0 or EXIT_SUCCESS, status indicating successful termination is returned.
//	If exit_code is EXIT_FAILURE, status indicating unsuccessful termination is returned

}
