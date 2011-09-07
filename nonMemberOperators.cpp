#include <iostream>
#include <sstream>
using namespace std;

class A{
public:
	int a;
	int b;
};

istream& operator>>(istream& is,A &obj){
	is >> obj.a >> obj.b;
}

ostream& operator<<(ostream& os,A &obj){
	os << obj.a << " " << obj.b;
}

int main(){
	A x;
	x.a = 1;
	x.b = 2;
	stringstream stream("12 21");
	stream>>x;
	cout << x << endl;
}
