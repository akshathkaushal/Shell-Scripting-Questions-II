/*

Program Number 24
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to create a message queue and print the key and message queue id.


*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
	key_t k;
	int msgid;
	k = ftok("progfile", 65);
	msgid = msgget(k, 0666 | IPC_CREAT);
	printf("key = %d, message id = %d\n", k, msgid);
	return 0;
}

