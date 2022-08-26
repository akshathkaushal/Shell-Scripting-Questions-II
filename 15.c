/*

Program Number 15
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a simple program to send some data from parent to the child process.


*/
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>
#define MSGSIZE 12

int main()
{
	char inBuf[MSGSZ];
        int pd[2];
	char* msg = "Hello, World!";

        if (pipe(pd) < 0)
                exit(1);

        if(!fork()){
		read(pd[0], inBuf, MSGSIZE);
        	printf("%s\n", inBuf);
        }
        else
	       write(pd[1], msg, MSGSIZE);
        
        return 0;
}

