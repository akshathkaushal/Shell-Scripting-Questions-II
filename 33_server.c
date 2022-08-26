/*

Program Number 33
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to communicate between two machines using socket.


*/
#include<unistd.h>
#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>

#define PORT 8080

int main(int argc, char const *argv[]){

	int server_fd, new_socket, recv;
	struct sockaddr_in address;
	int opt=1;
	int addrlen = sizeof(address);

	char buffer[1024]={0};
	char* hello = "Server says hello";

	if((server_fd = socket(AF_INET, SOCK_STREAM, 0))==0){
		perror("Socket failure!");
		exit(EXIT_FAILURE);
	}

	if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | 
		SO_REUSEPORT, &opt, sizeof(opt))){
		perror("setsocketopt");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if(bind(server_fd, (struct sockaddr*)&address, sizeof(address))<0){
		perror("Binding failed!");
		exit(EXIT_FAILURE);
	}

	if(listen(server_fd, 3)<0){
		perror("Listen");
		exit(EXIT_FAILURE);
	}

	if((new_socket = accept(server_fd, (struct sockaddr*)&address, 
		(socklen_t*)&addrlen))<0){
		perror("Accept");
		exit(EXIT_FAILURE);
	}

	recv = read(new_socket, buffer, 1024);
	printf("Client: %s\n", recv);
	send(new_socket, hello, strlen(hello), 0);
	printf("Message sent!\n");
	return 0;
}
