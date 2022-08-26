/*

Program Number 11
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.


*/
#include<signal.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/wait.h>

int main ()
{
        struct sigaction sg;
        memset(&sg, 0, sizeof (sg));
        sg.sa_handler = SIG_IGN;
        sigaction(SIGINT, &sg, NULL);
	printf("SIGINT ignored\n");
	sleep(5);
	sg.sa_handler = SIG_DFL;
	sigaction(SIGINT, &sg, NULL);
	printf("SIGINT not being ignored\n");
        while (1);
}

