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
	int fd;
	char * myfifo = "myfifo";
	mkfifo(myfifo, 0666);
	char pp1[100], pp2[100];
	fd = open(myfifo, O_WRONLY);
	printf("Enter Messsage to 20b.c:\n");
    scanf("%[^\n]", pp2);
	write(fd, pp2, strlen(pp2)+1);
	close(fd);

	fd = open(myfifo, O_RDONLY);
	read(fd, pp1, sizeof(pp1));
	printf("User2: %s\n", pp1);
	close(fd);
	return 0;
}

