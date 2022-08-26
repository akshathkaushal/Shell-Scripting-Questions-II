/*

Program Number 9
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:

Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.

*/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
	signal(SIGINT, SIG_IGN);
	printf("SIGINT ignored\n");
	sleep(5);
	printf("SIGINT not being ignored\n");
	signal(SIGINT, SIG_DFL);
	while (1);
	return 0;
}

