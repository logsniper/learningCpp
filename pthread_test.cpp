#ifndef _THREAD_TEST_H_
#define _THREAD_TEST_H_

#include<pthread.h>
#include<cstdio>
#include<unistd.h>
#include<new>
#define LOOP_NUM 100000000

void* subThread(void* pmutex);
int THREAD_NUM;

void testPthread(){
    scanf("%d",&THREAD_NUM);
    pthread_t *threads = new pthread_t[THREAD_NUM];
    pthread_attr_t attr;
    void *status;
    int *index = new int[THREAD_NUM];

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
    for(int i=0;i<THREAD_NUM;++i){
         index[i] = i;
         int ret = pthread_create(&threads[i],&attr,subThread,(void*)&index[i]);
         printf("pthread_create returns %d\n",ret);
    }
    for(int i=0;i<THREAD_NUM;++i){
        pthread_join(threads[i],&status);
    }
    pthread_attr_destroy(&attr);
    delete []threads;
    delete []index;
}

void* subThread(void* param){
    int idx = *(int*)param;
    printf("Entering subThread No.%d.\n",idx);
    int k;
    for(int i=0;i<LOOP_NUM;++i) k = i*i;
    printf("Exiting from subThread No.%d.\n",idx);
    pthread_exit(NULL);
}

int main(){
    testPthread();
    return 0;
}

#endif
