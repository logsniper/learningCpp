#include <cstdio>

#define ADDR_BYTES 4
typedef long* ADDR_TYPE;

class base{
public:
    base(char c):id(c){ printf("base::base(), id = %c, *this = %x\n",c,*(ADDR_TYPE)this);}
    int k;
	char id;
    virtual void f(){printf("base::f() id=%c\n",id);}
    virtual void g(){printf("base::g() id=%c\n",id);}
    virtual void h(){printf("base::h() id=%c\n",id);}
};

class child : public base{
public:
    child(char c):base(c){ printf("child::child(), id = %c, *this = %x\n",c,*(ADDR_TYPE)this);}
    virtual void f(){printf("child::f()\n");}
    virtual void g(){printf("child::g()\n");}
    virtual void h(){printf("child::h()\n");}
};

int main(){
    base a('a'),b('b');
    child c('c');
    printf("addresses of base and base::k are %x and %x\n",&a,&a.k);
    printf("VTABLE addresses of different instances of base are %x and %x\n",*(ADDR_TYPE)&a,*(ADDR_TYPE)&b);
    ADDR_TYPE vptr = (ADDR_TYPE)(*(ADDR_TYPE)(&a));
    printf("%x %x %x\n",vptr,*vptr,(int*)*(int*)(&a));
    printf("address: base::f() at %x, 1st function in VTABLE at %x\n",&base::f,*vptr);
    printf("address: base::g() at %x, 2nd function in VTABLE at %x\n",&base::g,*(vptr+1));
    printf("address: base::h() at %x, 3rd function in VTABLE at %x\n",&base::h,*(vptr+2));

	a.f();a.g();a.h();

	typedef void(*function_pointer_type)(base* b);
	function_pointer_type fp = NULL;
	fp = (function_pointer_type)*(vptr+0);
	fp(&b);
	fp = (function_pointer_type)*(vptr+1);
	fp(&b);
	fp = (function_pointer_type)*(vptr+2);
	(*fp)(&b);
	printf("%x %x\n",fp,*fp);
}
