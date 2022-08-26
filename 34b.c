/*

Program Number 34
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to create a concurrent server.
a. use fork
b. use pthread_create


*/
#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<pthread.h>
#define PORT 8080
void echo(int socket)
{
	printf("Closing client: %d\n", socket);
}
void *thread(void *vargp)
{
	int connfd = *(int *)vargp;
	pthread_detach(pthread_self());
	echo(connfd);
	close(connfd);
}
int main(int argc, char const *argv[])
{
        int server_fd, new_socket, valread;
        struct sockaddr_in address;
        int opt = 1;
        int addrlen = sizeof(address);
        char buffer[1024] = {0};
        char *hello = "Server says hello";
	pthread_t tid;

        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        {
                perror("socket failed");
                exit(EXIT_FAILURE);
        }

        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
        {
                perror("setsockopt");
                exit(EXIT_FAILURE);
        }
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons( PORT );

        if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
        {
                perror("bind failed");
                exit(EXIT_FAILURE);
        }
        if (listen(server_fd, 3) < 0)
        {
                perror("listen");
                exit(EXIT_FAILURE);
        }
	while(1)
	{
		if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        	{
                	perror("accept");
                	exit(EXIT_FAILURE);
        	}
		pthread_create(&tid, NULL, thread, (void*)&new_socket);
	}
}
