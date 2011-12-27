#include <iostream>
using namespace std;

class A{
	static int count ;
public:
	A(){
		++ count;
		cout<<"A() --Constructor running. Count = "<<count<<endl;
	}
	~A(){
		-- count;
		cout<<"~A() --Destructor running. Count = "<<count<<endl;
	}
};

int A::count = 0;

int main(){
	A* p = new A[10];
	delete []p;
	cout<<" Done.\n";
}
