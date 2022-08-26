/*

Program Number 29
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to remove the message queue.


*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
    key_t key;
    int msgid;
	key = ftok("progfile", 65);
    msgid = msgget(key, 0666);
	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}

