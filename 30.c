/*

Program Number 30
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:

Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory

*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	key_t key = ftok("shmfile",65);
	int shmid = shmget(key, 1024, SHM_RDONLY);
	char *str = (char*) shmat(shmid, (void*)0 , 0);
	printf("Write data: ");
	scanf("%[^\n]", str);
	printf("Data written in shared memory: %s\n", str);
	shmdt(str);
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}
