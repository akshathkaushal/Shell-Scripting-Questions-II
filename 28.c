/*

Program Number 28
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to change the exiting message queue permission. (use msqid_ds structure)


*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
    key_t k;
    int msgid;
	k = ftok("progfile", 65);
    msgid = msgget(k, 0666);

    struct msqid_ds msq;
	msq.msg_perm.mode = 0766;
    printf("access mode = %d\n", ipc.mode);

	msgctl(msgid, IPC_SET, &msq);
    return 0;
}
