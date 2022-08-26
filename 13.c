/*

Program Number 13
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:

Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

*/
#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main()
{
	int pid_ = 1
	kill(pid_, SIGSTOP);
	return 0;
}
