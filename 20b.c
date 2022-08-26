/*

Program Number 20
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:

Write two programs so that both can communicate by FIFO -Use one way communication.

*/

// C program to implement one side of FIFO
// This side reads first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd1;
	char * myfifo = "myfifo";
	mkfifo(myfifo, 0666);
	char str1[100], str2[100];
	fd1 = open(myfifo,O_RDONLY);
	read(fd1, str1, 100);
	printf("User1: %s\n", str1);
	close(fd1);
	return 0;
}

