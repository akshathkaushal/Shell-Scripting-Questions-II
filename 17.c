/*

Program Number 17
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl


*/
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>

int main()
{
	int fd[2];
	if(pipe(fd) < 0)
	{
		exit(1);
	}
	if(!fork())
	{
		close(1);
		close(fd[0]);
		dup2(fd[1], 1);
		execlp("ls","ls","-l",NULL);
		return(0);
	}
	else
	{
		wait(0);
		close(0);
		close(fd[1]);
		dup2(fd[0], 0);
		execlp("wc","wc",NULL);
	}
}
