/*

Program Number 7
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a simple program to print the created thread ids.


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

	pthread_t mythread;
	pthread_create(&mythread, NULL, create_thread, NULL);
	
	pthread_join(mythread, NULL);

	return 0;
}
