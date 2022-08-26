/*

Program Number 19
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function


*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	const char* fifopath = "dog";
	const char* fifopath1 = "cat";
	int fifo = mknod(fifopath, S_IFIFO, 0666);
	int fifo1 = mkfifo(fifopath1, 0666);
	perror(fifopath);
	printf("fifo = %d\n",fifo);
	perror(fifopath1);
    printf("fifo = %d\n",fifo1);
	return 0;
}
