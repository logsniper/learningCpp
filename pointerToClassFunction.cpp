#include<cstdio>

class A{
public:
    void func1(){ printf("func 1\n");}
    void func2(){ printf("func 2\n");}
};

int main(){
    A a[2];
    void (A::*fp)();
    fp = &A::func1;
    (a[0].*fp)();
    (a[1].*fp)();

    fp = &A::func2;
    (a[0].*fp)();
    (a[1].*fp)();
}
