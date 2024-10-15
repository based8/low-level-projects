# A simple TCP server
Small tcp server you can compile. write. and play around with while compiling other things.

if you wanna write it yourself as a DIY project i have created a explanation for myself mainly but also for anyone looking to do the same

## Synopsis / Steps

### in <strings.h> 

bzero() will be used to write 0s to strings 

### in <netinet/in.h>

struct sockaddr_in will be used for creating the socket address 

### in <sys/socket.h>

socket() will be used for creating the socket file descriptor 

bind() will be used for binding the created socket with the socket address 

listen() will be used to to make the socket be happy to recieve incoming connections 

connect() will be used for connecting a socket with the server address 

accept() will be used to accept/ show the first connection 

### in <unistd.h>

close() will be used to delete the socket file descriptor 

## Server side:

a socket address for the server is created with the struct sockaddr. a socket file descriptor is then made with socket() and bound with the socket address using bind().
We then listen() and accept() the first connection

## Client side:

the server socket address is specified using the struct sockaddr. new client socket is created. then we connect() to the server address with our socket



