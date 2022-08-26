/*

Program Number 2
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
 Write a program to print the system resource limits. Use getrlimit system call.


*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
#include<sys/time.h>
#include<sys/resource.h>

int main(){

	struct rlimit lim;

	int ret = getrlimit(RLIMIT_LOCKS, &lim);
	//printf("softlimit: %d, hardlimit: %d\n", lim.rlim_cur, rlim_max);
	printf("Limit: %d\n",lim.rlim_cur); 
	return 0;
}
