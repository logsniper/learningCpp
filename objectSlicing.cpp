#include <iostream>
using namespace std;

class A{
    int a;
public:
    virtual void gao(){ cout<<"A::gao()\n";}
};

class B : public A{
    int b;
public:
    operator A() const{cout<<"type convert from B to A\n";};
    virtual void gao(){ cout<<"B::gao()\n";}
};

void f(A a){
    cout<<"f(A a) : "<<sizeof(a)<<endl;
    a.gao();
}

void g(A& a){
    cout<<"g(A& a) : "<<sizeof(a)<<endl;
    a.gao();
}

void h(A* a){
    cout<<"h(A* a) : "<<sizeof(*a)<<endl;
    a->gao();
}

int main(){
    A a;
    B b;
    cout<<"sizeof A : "<<sizeof(a)<<endl;
    cout<<"sizeof B : "<<sizeof(b)<<endl;
    f(a);
    cout<<"object slicing will happen ...\n";
    f(b);
    cout<<"object slicing happened.\n";
    g(a);
    g(b);
    h(&a);
    h(&b);
}
