#include<cstdio>
class base{
public:
	virtual void f(){ printf("Base::f()\n"); }
};

class child : public base{
public:
	virtual void f(){ printf("Child::f()\n"); }
};

int main(){
	printf("Call by child's identifier :\n");
	child c;
	c.f();
	c.base::f();
	c.child::f();

	printf("Call by base's pointer :\n");
	base*p = &c;
	p->f();
	p->base::f();
	p->f();
}
