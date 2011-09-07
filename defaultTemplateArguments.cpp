#include <iostream>
using namespace std;

class NotBuiltIn{
	int v;
public:
	NotBuiltIn(int _v):v(_v){cout<<"NotBuiltIn() running.\n";}
	~NotBuiltIn(){cout<<"~NotBuiltIn() running.\n";}
	bool operator = (const int &_v) {
		v = _v;
	}
};

template<class T = int,int i = 0>
class A{
	T v;
public:
	A(T k):v(k){cout<<"A() running.i="<<i<<",v="<<v<<endl;}
	void print(){cout<<"value of template argument : "<<(i)<<endl;}// &i will make a compile error
	~A(){ cout<<"~A() running.i="<<i<<",v="<<v<<endl;}
};

int main(){
	int k = 0;
	NotBuiltIn nbi = 1;
//	"A a(k);" makes compile error, which means the default argument "T = int" in "template<class T = int>" is useless.
	A<int,10> a(k);
	A<int> b(2);
	a.print();
	b.print();
}
