#include<vector>
#include<iostream>
using namespace std;

int main(){
	vector<int> a;
	vector<int> b;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	cout<<"sizeof a and b : "<<sizeof(a)<<" "<<sizeof(b)<<endl;
	cout<<"address of a and a[0] : "<<&a<<" "<<&(a[0])<<endl;
	b = a;
	cout<<"address of a[0] and b[0] : "<<&a[0]<<" "<<&b[0]<<endl;
	b[0] = 100;
	cout<<"address of a[0] and b[0] : "<<&a[0]<<" "<<&b[0]<<endl;
	a[6] = 12345;
	cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
	a.push_back(4);
	a.push_back(5);
	cout<<"address of a[0] and b[0] : "<<&a[0]<<" "<<&b[0]<<endl;
}
