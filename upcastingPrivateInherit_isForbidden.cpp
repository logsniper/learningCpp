#include <cstdio>

class A{
public:
    void f(){ printf("A::f()\n"); }
};

class B : private A{
public:
    // Without "using B::f;" ,b.f() is invalid.
    // However, g(b) is always invalid.
    operator A() const{ printf("type conversion from B to A.\n");return A(); }
    using B::f;
};

void g(A a){
    a.f();
}

int main(){
    A a;
    g(a);
    B b;
    b.f();
//    g(b);
}
