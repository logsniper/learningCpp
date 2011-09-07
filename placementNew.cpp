#include<cstdio>
#include<new>
#include<cstring>
#include<pthread.h>
#include<unistd.h>
class arr{
	char ch[12000000];
public:
	arr(){
		memcpy(ch,"xyzlmnabcdefg_____________________________________________________________________________________________________________________",16);
	}
};

void* testNewOp(void* p){
	printf("Come into thread.\n");
	int count = 0;
	while(1){
		try{
		p = new arr[20];
		} catch (...){
			printf("failed to new after %d times\n",count);
			break;
		}
		++ count;
		if(count > 200) break;
	}
}

int main(){
	char str[3][12] = {"12345678901","12345678901","12345678901"};
	arr* a = new(str[1]) arr;
	printf("%x %x %x %x\n",str[0],str[1],a,str[2]);
//	delete a;
	a->arr::~arr();
	for(int i=0;i<12;++i){
		str[1][i] = 'a'+i;
	}
	str[1][11] = '\0';
	printf("%s %s %s\n",str[0],str[1],str[2]);
	a = new(std::nothrow) arr;
	printf("new address of class arr = %x\n",a);
	printf("%s %s %s\n",str[0],str[1],str[2]);
	delete a;
//	a->arr::~arr();
	printf("%s %s %s\n",str[0],str[1],str[2]);

	pthread_t thread;
	pthread_create(&thread,NULL,testNewOp,NULL);
	pthread_exit(NULL);
}
