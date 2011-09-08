#include <iostream>
using namespace std;

class elem{
    int v;
public:
    elem(int _v = 0):v(_v){}
    int getV()const{ return v;}
    void setV(int _v) { v = _v;}
};

class A{
    const elem e;

public:
    A(int _v = 0):e(_v){}
    void f() const{
        cout<<"f() "<<e.getV()<<endl;
    }

    void g() {
        cout<<"g() "<<e.getV()<<endl;
    }
};

int main(){
    A a(1);
    a.f();
    a.g();
    const A b;
    b.f();
//    b.g(); // compile error because g() is not const function
}
