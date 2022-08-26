/*

Program Number 23
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:

Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).

*/
#include<stdio.h>
#include<unistd.h>

int main()
{
	long PIPE_BUFF, OPEN_MAX;
	PIPE_BUFF = pathconf(".", _PC_PIPE_BUF);
	OPEN_MAX = sysconf(_SC_OPEN_MAX);
	printf("Pipe buffer = %ld  open_max = %ld\n", PIPE_BUFF, OPEN_MAX);
	return 0;
}
