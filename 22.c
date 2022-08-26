/*

Program Number 22
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.


*/
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	fd_set rfds;
	struct timeval tv;
	int ret;

	FD_ZERO(&rfds);
	FD_SET(0, &rfds);

	tv.tv_sec = 10;
	tv.tv_usec = 0;

    char * myfifo = "myfifo";
	char arr2[100];
	int fd = open(myfifo, O_WRONLY);
    printf("Enter Messsage:\n");
    
    ret = select(fd, &rfds, NULL, NULL, &tv);
	close(fd);

	if(ret)
		printf("Data is available in 10 seconds\n");
	else
		printf("Data is not available in 10 seconds\n");

	close(fd);
	return 0;
} 
