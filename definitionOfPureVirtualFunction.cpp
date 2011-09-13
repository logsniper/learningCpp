#include <iostream>
using namespace std;

class A{
public:
    virtual void f() = 0;
    virtual ~A() = 0;
};

void A::f(){
    cout<<"A::f()\n";
}

A::~A(){
    cout<<"A::~A()\n";
}

class B : public A{
public:
    void f(){
        cout<<"B::f()\n";
    }

};

int main(){
    B b;
    b.f();
    A* pa = &b;
    pa->f();
    pa->A::f();
    b.~B();
    b.f();
}
