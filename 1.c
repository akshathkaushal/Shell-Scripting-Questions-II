/*

Program Number 1
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:

Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/time.h>
#include<string.h>
#include<signal.h>

#define sec 10
#define usec 10

void proceed();

int main(){
	
	struct itimerval initial;

	initial.it_value.tv_sec = sec;
	initial.it_value.tv_usec = usec;

	memcpy(&(initial.it_interval), &(initial.it_value), sizeof(initial.it_value));	

	int ret = setitimer(ITIMER_VIRTUAL, &initial, 0);

 	if(signal(SIGALRM, (void (*)(int)) proceed) == SIG_ERR) {
		printf("Error\n");
	}	

	while(1)
		pause();

	


	//return 0;
}

void proceed(){ // handler
	printf("The timer went off\n");
	return ;
}

