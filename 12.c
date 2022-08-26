/*

Program Number 12
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:

Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.

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
	int pid = getpid();
        if(!fork())
        {
		printf("Before Orphan: child Process: %d, ppid = %d\n", getpid(), getppid());
		kill(pid, SIGKILL);
              	printf("After Orphan: child Process: %d, ppid = %d\n", getpid(), getppid());
        }
        else
        {
                printf("parent process: %d\n", getpid());
		while(1);
        }
        return 0;
}

