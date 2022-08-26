/*

Program Number 21
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write two programs so that both can communicate by FIFO -Use two way communications.


*/
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

	char pp1[100], pp2[100];
	fd1 = open(myfifo,O_RDONLY);
	read(fd1, pp1, 100);
	printf("User1: %s\n", pp1);
	close(fd1);

	fd1 = open(myfifo,O_WRONLY);
	printf("Enter Messsage to 20a.c:");
    scanf("%[^\n]", pp2);
	write(fd1, pp2, strlen(pp2)+1);
	close(fd1);
	return 0;
}

