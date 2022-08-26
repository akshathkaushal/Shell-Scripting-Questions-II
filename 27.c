/*

Program Number 27
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag


*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buf {
    long mesg_type;
    char mesg_text[100];
} message;

int main()
{
    key_t k;
    int msgid;
    k = ftok("progfile", 65);
    msgid = msgget(k, 0666);
    printf("key = %d, message id = %d\n", k, msgid);
    msgrcv(msgid, &message, sizeof(message), 1, 0);
    printf("Data received: %s \n", message.mesg_text);
    return 0;
}
