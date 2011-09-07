#include<cstdio>

class A{
	int v;
public:
	A(const int v){
		this->v = v;
		printf("A's constructor called.\n");
	}
	int getV(){	return v; }
};

class B{
	int v;
public:
	B(const int v=0){
		this->v = v;
		printf("B's constructor called.\n");
	}
	int getV(){	return v; }
};

class C : public A,public B{
public:
	C() : A(10) {
		printf("C's constructor called.\n");
	}
	void print(){
		printf("A's param = %d,\nB's param = %d.\n",A::getV(),B::getV());
	}
};

int main(){
	C x;
	x.print();
}
