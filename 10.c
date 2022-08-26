/*

Program Number 10
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:

Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE

*/
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

void sig_handler(int signum)
{
        printf ("signal caught: %d\n", signum);
}
int main ()
{
        struct sigaction sg;
        memset(&sg, 0, sizeof (sa));
        sg.sa_handler = &sig_handler;
		sigaction(SIGINT, &sg, NULL);
        while (1);
}

