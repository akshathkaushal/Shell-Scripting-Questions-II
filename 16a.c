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
	int fd1[2];
	int fd2[2];
	
	char buf1[7];
	char buf2[7];
	
	pipe(fd1);
	pipe(fd2);
	
	if(!fork())
	{
		close(fd1[0]);
		printf("Enter Messsage for parent:");
		scanf("%[^\n]", buf1);
		write(fd1[1],buf1,sizeof(buf1));
		close(fd2[1]);
		read(fd2[0],buf2,sizeof(buf2));
		printf("Read from parent: %s\n",buf2);
	}
	else
	{
		close(fd1[1]);
		read(fd1[0],buf1,sizeof(buf1));
		printf("Read from child: %s\n",buf1);
		printf("Enter message for child:");
		scanf("%[^\n]",buf2);
		close(fd2[0]);
		write(fd2[1],buf2,sizeof(buf2));
	}
	wait(0);
}
