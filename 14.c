/*

Program Number 14
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.


*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define MSGSZ 12
char* msg = "Hello, World!";

int main()
{
	char inbuf[MSGSZ];
	int pd[2];

	if (pipe(pd) < 0)
		exit(1);

	write(pd[1], msg, MSGSZ);
	read(pd[0], inbuf, MSGSZ);
	printf("%s\n", inbuf);
	return 0;
}

