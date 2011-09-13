#include <iostream>
using namespace std;

class A{
public:
    A(){}
    A(const A& other){
        cout<<"copy constructor in A\n";
    }
    A operator=(const A& other) const{
        cout<<"assignment operator in A\n";
    }
};

int main(){
    A a;
    A b = a;
    b = a;
    return 0;
}
/**
 * Solution: Which function will be called depends on whether the left value exists or not.
 */
