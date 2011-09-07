#include<cstdio>
#include<string>
using namespace std;

class myownclass{
public:
	int a;
	int b;
	myownclass(int a,int b): a(a),b(b){}
//private:	// Complie error
	myownclass(const myownclass &x){
		printf("CC is called.\n");
		a = x.a;
		b = x.b;
	}
};

void testCC(myownclass x){
	printf("%d %d\n",x.a,x.b);
}

myownclass& testMyownclass() {	
	printf("address of function testMyownclass() = %x\n",&testMyownclass);
	myownclass x(1,2);
	myownclass y(8,9);
	printf("%x %x\n",&x,&y);
	x = y;
	printf("%x %x\n\n",&x,&y);
	testCC(x);
	return x;
}

void testString(){
	printf("address of function testString() = %x\n",&testString);

	string s("abc");
	printf("%x %x\n",&s,s.c_str());
	
	string ps("xyz");
	s = ps;
	printf("%x %x\n%x %x\n\n",&s,s.c_str(),&ps,ps.c_str());
}

myownclass testNoRef(myownclass x){
	printf("address of param : %x\n",&x);
	return x;
}

myownclass& testWithRef(myownclass &x){
	printf("address of param : %x\n",&x);
	return x;
}

void testRef(){
	myownclass x(5,6);
	printf("address of original varible : %x\n",&x);
	printf("without ref :\n");
	myownclass p = testNoRef(x);
	printf("with ref :\n");
	myownclass q = testWithRef(x);
	printf("address of p(without ref) : %x, q(with ref) : %x\n\n",&p,&q);
}

int main(){
	myownclass* k = new myownclass(3,4);
	myownclass l(3,4);
	printf("address of k = %x, l = %x\n",k, &l);
	testRef();
	myownclass tmp = testMyownclass();
	testString();
	return 0;
}
