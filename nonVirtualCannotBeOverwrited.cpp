#include<cstdio>

class A{
public:
	void nonVirtualFunc(){
		printf("non virtual function in A\n");
	}
	virtual void virtualFunc(){
		printf("virtual function in A\n");
	}
};

class B : public A{
public:
	void nonVirtualFunc(){
		printf("non virtual function in B : A\n");
	}
	virtual void virtualFunc(){
		printf("virtual function in B : A\n");
	}
};

int main(){
	B x;
	printf("Call by B's referrence.\n");
	x.nonVirtualFunc();
	x.virtualFunc();
	x.A::nonVirtualFunc();
	x.A::virtualFunc();
	printf("\n");

	A* px = &x;
	printf("Call by A's pointer.\n");
	px->nonVirtualFunc();
	px->virtualFunc();
	px->A::nonVirtualFunc();
	px->A::virtualFunc();
}
