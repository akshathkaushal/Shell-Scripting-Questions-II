/*

Program Number 8
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:

Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)

*/
#include<stdio.h> 
#include<signal.h>
#include<string.h>
#include<stdlib.h>
#include<sys/time.h>

void handle_sig(int sig) 
{
	signal(sig, handle_sig);
	printf("Caught signal %d\n", sig); 
}
void timer_handler(int sig)
{
	signal(sig, timer_handler);
        printf ("caught signal %d\n", sig);
}
int main()
{
	char* sig = (char*)malloc(10*sizeof(char));
	printf("Please type any one of the given signals to catch: SIGSEGV, SIGINT, SIGFPE, SIGALRM, SIGVTALRM, SIGPROF\n");
	scanf("%s", sig);
	if(!strcmp(sig, "SIGINT"))
	{
		signal(SIGINT, handle_sig);
	}
	else if(!strcmp(sig, "SIGSEGV"))
	{
		signal(SIGSEGV, handle_sig);
	}
	else if(!strcmp(sig, "SIGFPE"))
	{
		signal(SIGFPE, handle_sig);
	}
	struct sigaction sa;
        struct itimerval timer;

        memset(&sa, 0, sizeof (sa));
        sa.sa_handler = &timer_handler;

	if(!strcmp(sig, "SIGALRM"))
	{
        	sigaction(SIGALRM, &sa, NULL);
	}
	else if(!strcmp(sig, "SIGVTALRM"))
	{
		sigaction(SIGVTALRM, &sa, NULL);
	}
	else if(!strcmp(sig, "SIGPROF"))
	{
		sigaction(SIGPROF, &sa, NULL);
	}
	
        timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;

        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        setitimer(ITIMER_VIRTUAL, &timer, NULL);
	while(1);
	return 0; 
} 

