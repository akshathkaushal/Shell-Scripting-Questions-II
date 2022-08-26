/*

Program Number 18
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:

Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2

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
	int fd1[2];
	int fd2[2];
	if(pipe(fd1) < 0 || pipe(fd2) < 0)
		exit(1);

	if(!fork())
	{
		close(1);
		dup(fd1[1]);
		close(fd1[0]);
		close(fd2[0]);
		close(fd2[1]);
		execl("/bin/ls","ls","-Rl",NULL);
	}
	else
	{
		if(!fork())
		{
			close(0);
			dup(fd1[0]);
			close(1);
			dup(fd2[1]);
			close(fd1[1]);
			close(fd2[0]);
			execl("/bin/grep","grep","^d",NULL);
		}
		else
		{
			close(0);
			dup(fd2[0]);
			close(fd1[0]);
			close(fd1[1]);
			close(fd2[1]);
			execl("/usr/bin/wc","wc",NULL);
		}
	}
	return 0;
}
