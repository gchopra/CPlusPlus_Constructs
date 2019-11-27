#include<iostream>
using namespace std;


template<typename T>
T maximum(T a, T b){
	return (a > b) ? a : b;
}


//the above tempalte can't handle strings -- so we have a specialization for it
template<> //shows its specialization
char* maximum<char*>(char * a, char * b){
	return strcmp(a,b)>0 ? a : b;
}


int main(){

	int a_int = 10, b_int = 11;
	double a_double = 1.18, b_double = 1.13;
	char* a_str= str("aaa"),b_str = "aab";

	cout<<"integer maximum is="<< maximum(a_int,b_int) <<endl;//call the int max through template
	cout<<"double maximum is="<< maximum(a_double,b_double) <<endl; // call the double max through template
	cout<<"string maximum is="<< maximum(a_str,b_str) <<endl; // call the specialized str max through template
}
