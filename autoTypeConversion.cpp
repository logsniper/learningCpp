#include <cstdio>

class A{
public:
	A(int k) { printf("A(int %d)\n",k);}
	~A() { printf("~A()\n");}
	A(const A &a) {printf("A(const A &a)\n"); }
	void who(){ printf("who:A\n"); }
};

class B{
public:
	B() { printf("B()\n");}
	~B() { printf("~B()\n");}
	B(const B &b) {printf("B(const B &b)\n"); }
	operator A() const{ printf("Auto type conversion B->A\n");}
	void who(){ printf("who:B\n"); }
};

void f(A a){ printf("f(A a)\n");a.who(); }

int main(){
	A a(4);
	B b;
	B pb = b;
	f(a);
	f(b);
	A pa = b;
}
