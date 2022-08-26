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


int main(void){

	int ret, semid, key;
	int fd = open("ticketnumber.txt", O_RDWR|O_EXCL);
	while(1){
		key = ftok(".", 'a');
		struct sembuf buf = {0, -1, SEM_UNDO};
		semid = semget(key, 1, 0);
		printf("Sem id: %d\n", semid);
		printf("Waiting for seaphore...\n");
		ret = semop(semid, &buf, 1); // locking
		printf("Semaphore accquired!\n");

		/* critical section starts */
		printf("Inside the critical section!\n");

		int current_ticket_no;
		read(fd, &current_ticket_no, sizeof(int));
		current_ticket_no = current_ticket_no + 1;
		lseek(fd, 0, SEEK_SET);
		write(fd, &current_ticket_no, sizeof(int));

		/* critical section ends */
		
		char c = getchar();

		buf.sem_op = 1;
		ret = semop(semid, &buf, 1); // unlocking
		printf("Exited the critical section!\n");

		if(c==113) break;

	}
	close(fd);
	return 0;
}

