#include<iostream>
using namespace std;

/*
userNodes is a class with multiple nodes representing users
printRequestingNode is a friend class to userNodes to print the userName and userID
pageCounter is a friend function to userNodes to print the number of pages from that class
 */
class userNodes{
	const char* _userName;
	int _userID;
	int _pages;
public:
	userNodes(const char* userName="dummy",int userID = 0,int pages=0): _userName(userName), _userID(userID), _pages(pages) {}
	friend class printRequestingNode;
	friend void pageCounter(userNodes&);
};

void pageCounter(userNodes& un){
	cout <<"user "<<un._userName<<" printing "<< un._pages <<" pages"<<endl;
}

class printRequestingNode{
public:
	void print(userNodes& unode){
		cout << "userName="<<unode._userName << endl;
		cout << "userID="<<unode._userID << endl;
	}
};

int main(){
	userNodes node1,node2("chopra",100,11),node3("gchop",144,15);
	printRequestingNode printer;

	printer.print(node1);
	printer.print(node2);
	printer.print(node3);

	pageCounter(node1);
	pageCounter(node3);
}
