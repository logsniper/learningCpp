#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int array[]={1,1,2,2,3,3,4,4};
	int* p = unique(array,array+8);
	printf("%d\n",*p);
	for(int i=0;i<8;++i)
		printf("%d ",array[i]);
	printf("\n");
	return 0;
}
