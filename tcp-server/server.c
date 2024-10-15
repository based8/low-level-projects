#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

int main()
{
	struct sockaddr_in servaddr, client;
	int sockfd, connfd;
	socklen_t clilen = sizeof(client);

	bzero((char *) &servaddr, sizeof(struct sockaddr_in));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(8001);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) { 
		perror("Failed to create socket\n");
	} else {
		printf("Socket created\n");
	}

	if (bind(sockfd,(struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
		perror("Failed to bind socket.\n");
	} else {
		printf("Socket bound to address\n");
	}

	if (listen(sockfd, 5) < 0){
		perror("Failed to listen.\n");
	} else {
		printf("Socket listening ...\n");
	}
	

	connfd = accept(sockfd, (struct sockaddr *) &client, &clilen);
	if (connfd < 0){ 
		perror("Error with accepting connection\n");
	} else {
		printf("Connection accepted!\n");
		close(connfd);
		close(sockfd);
	}
}	
