#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<int> array;
	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	const
	vector<int> &ref = array;
	for(vector<int>::const_iterator it=ref.begin();it!=ref.end();++it){
		cout<<*it<<endl;
	}
}
