/*

Program Number 31
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore


*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<sys/msg.h>

union semun {
	int val;
	struct semid_ds* buf;
	unsigned short int* array;
};

int main(void){

	int semid, key;
	union semun arg;
	
	key = ftok(".", 'a');
	semid = semget(key, 2, IPC_CREAT|0744); // 1 here indicates the number of semaphores created
	arg.val=1; // tells if it is a binary semaphore or counting semaphore
	semctl(semid, 0, SETVAL, arg); // 1 indicates the index of semaphore in the semaphore array

	int fd = open("ticketnumber.txt", O_WRONLY);
	int buf;
	int size_ticketno = read(0, &buf, sizeof(int));
	size_ticketno = size_ticketno-48;
	write(fd, &buf, sizeof(int)); 
	write(1, &buf, sizeof(int));
	close(fd);


	return 0;
}

