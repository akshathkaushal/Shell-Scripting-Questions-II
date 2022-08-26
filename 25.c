/*

Program Number 25
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv


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

	struct msqid_ds msq;
	msgctl(msgid, IPC_STAT, &msq);

	struct ipc_perm ipc = msq.msg_perm;

	printf("Access mode = %d\n", ipc.mode);
	printf("Access uid = %d\n", ipc.uid);
	printf("Access gid = %d\n", ipc.gid);
	printf("Time of last sent = %ld and recieved = %ld\n", msq.msg_stime, msq.msg_rtime);
	printf("Size of message queue(in bytes) = %ld\n", msq.msg_cbytes);
	printf("Number of messages = %ld\n", msq.msg_qnum);
	printf("Maximum size(in bytes) = %ld\n", msq.msg_qbytes);
	printf("PID of last sent message = %d\n", msq.msg_lspid);
	printf("PID of last recieved message = %d\n", msq.msg_lrpid);
    return 0;
}
