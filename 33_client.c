/*

Program Number 33
Name: Akshath Kaushal
Roll no. IMT2018501
Date: April 29, 2021

Description:
Write a program to communicate between two machines using socket.


*/
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define PORT 8080

int main(int argc, char const *argv[]){
	int sock=0, recv;
	struct sockaddr_in serv_addr;
	char* hello = "The client says hello!";
	char buffer[1024] = {0};
	if( (sock = socket(AF_INET, SOCK_STREAM, 0)) < 0 ){
		printf("Socket not created. Internal error.\n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){
		printf("IP address not valid\n");
		return -1;
	}

	if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
		printf("Connection failed!\n");
		return -1;
	}

	send(sock, hello, strlen(hello), 0);
	printf("Message sent!\n");
	recv = read(sock, buffer, 1024);
	printf("Server: %s\n", recv);
	return 0;
}
