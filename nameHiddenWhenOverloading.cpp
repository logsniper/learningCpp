#include <iostream>
using namespace std;

class base{
public:
    void f(){ cout<<"base::f()"<<endl; }
    void f(int){ cout<<"base::f(int)"<<endl; }
    void f(char){ cout<<"base::f(char)"<<endl; }
};

class child : public base{
public:
    void f(int){ cout<<"child::f(int)"<<endl; }
    void f(double){ cout<<"child::f(double)"<<endl; }
};

int main(){
    child c;
    c.f(1);
    c.f(0.1);
//    c.f();
    c.f('c');// cast char to int
}
