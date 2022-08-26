/*

Program Number 32
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore


*/
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int main(void)
{
	int key, semid;
	struct sembuf buf = {0, -1, 0};
	key = ftok(".", 'a');
	semid = semget(key, 1, 0);
	printf("Before Critical Section: \n");
	semop(semid, &buf, 1);
	printf("Inside the Critical Section: \n");
	printf("press ENTER to unlock");
	getchar();
	buf.sem_op = 1;
	semop(semid, &buf, 1);
	semctl(semid, 0, IPC_RMID);
	return 0;
}
