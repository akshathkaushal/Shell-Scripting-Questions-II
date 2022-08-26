/*

Program Number 3
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to set (any one) system resource limit. Use setrlimit system call


*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
#include<sys/time.h>
#include<sys/resource.h>

int main(){

	struct rlimit lim;
	lim.rlim_max = 5;
	int set = setrlimit(RLIMIT_LOCKS, &lim);

	printf("Limit set!\n");
	return 0;
}
