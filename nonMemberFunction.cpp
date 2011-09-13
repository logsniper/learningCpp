#include <iostream>
using namespace std;

class A{
public:
    int k;
};

void print(A &a, int t){
    cout<< (a.k+t) << endl;
}

ostream& operator<< (ostream &os,A &a){
    cout<< a.k;
}

int main(){
    A a;
    a.k = 2;
    cout << a << endl;
//    a.print(3);
}
