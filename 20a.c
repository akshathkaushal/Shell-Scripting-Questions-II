/*

Program Number 20
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write two programs so that both can communicate by FIFO -Use one way communication.


*/
// C program to implement one side of FIFO
// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd;
	char * myfifo = "MyFifo";
	mkfifo(myfifo, 0666);
	char arr1[100], arr2[100];
	fd = open(myfifo, O_WRONLY);
	printf("Enter Messsage to 20b.c:\n");
    scanf("%[^\n]", arr2);
	write(fd, arr2, strlen(arr2)+1);
	close(fd);
	return 0;
}

