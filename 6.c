/*

Program Number 6
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:

Write a simple program to create three threads.

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<pthread.h>

void* create_thread(void* p){

	printf("Thread id is %d\n", pthread_self());
	pthread_exit(NULL);

	return NULL;
}


int main(){

	pthread_t mythread1;
	pthread_create(&mythread1, NULL, create_thread, NULL);
	
	pthread_join(mythread1, NULL);


	pthread_t mythread2;
	pthread_create(&mythread2, NULL, create_thread, NULL);
	
	pthread_join(mythread2, NULL);

	pthread_t mythread3;
	pthread_create(&mythread3, NULL, create_thread, NULL);
	
	pthread_join(mythread3, NULL);


	return 0;
}
