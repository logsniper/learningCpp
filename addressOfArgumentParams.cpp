#include <cstdio>

class base1{
public:
    int a;
    base1(){
        printf("base1 constructed at %x\n",this);
    }
    base1(base1 &b){
        printf("base1 copy constructed at %x\n",this);
    }
};

class base2{
public:
    int a;
    base2(){
        printf("base2 constructed at %x\n",this);
    }
    base2(base2 &b){
        printf("base2 copy constructed at %x\n",this);
    }
};

class A{
    int a;
    int b;
public:
    int f(base1 aa,base2 bb){
        this->a = aa.a;
        this->b = bb.a;
        int c = this->a+this->b;
        printf("address in A::f(int,int) : %x %x %x %x\n",this,&aa,&bb,&c);
        return c;
    }
};

int main(){
    A x;
    base1 a ;
    base2 b ;
    printf("address of params : %x %x %x\n",&x,&a,&b);
    int c = x.f(a,b);
    printf("address of returned int = %x\n",&c);
}
