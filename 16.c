/*

Program Number 16
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to send and receive data from parent to child vice versa. Use two way
communication.


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
	char inBufchild[20];
	char inBufparent[20];
    int p1[2];
	int p2[2];
	char* msg = "Hello, child!";
	char* msgp = "Hello, parent";

    if(pipe(p1) < 0 || pipe(p2) < 0)
        exit(1);
    
    if(!fork())
    {
		close(p1[1]);
		read(p1[0], inBufchild, 20);
      	printf("%s\n", inBufchild);

		close(p2[0]);
		write(p2[1], msgp, 20);
		close(p2[1]);
    }
    else
    {
		close(p1[0]);
		write(p1[1], msg, 20);
		close(p1[1]);

		wait(NULL);

		close(p2[1]);
		read(p2[0], inBufparent, 20);
        printf("%s\n", inBufparent);
		close(p2[0]);
    }
    return 0;
}

