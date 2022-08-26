/*

Program Number 4
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.


*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
#include<sys/time.h>
#include<sys/resource.h>


unsigned long long rdtsc(){

	unsigned long long tm;
	__asm__ __volatile__ ("rdtsc":"=A" (tm));

	return tm;

}


int main(){

	long long int start = rdtsc();
	int i=0;

	while(i++<100){
		getppid();
	}
	long long int end = rdtsc();

	printf("Time taken = %lld\n", end-start);
	return 0;
}
