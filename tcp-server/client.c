#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

int main()
{
	struct sockaddr_in servaddr;
	int conn;
	uint32_t buff[32];

	bzero((char *) &servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(8001);
	
	conn = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(conn, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0){
		printf("error while connecting to server\n");
	} else {
		printf("connected to server\n");

		close(conn);
	}
		
}
