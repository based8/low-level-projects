#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char *argv) {
	int ifd;
	int ofd[3];
	int length = sizeof(ofd) / sizeof(int);
	char namebuff[64] = {'o','u','t','p'};
    char strbuff[1024];
    off_t fsize;    

	if ((ifd = open("data/example.txt", O_RDONLY)) == -1){
		perror("could not open input file");
		return 0;
	}
	if ((read(ifd, strbuff, sizeof(strbuff))) == -1){
		perror("could not read input file into buffer");
		return 0;
	}
    fsize = lseek(ifd, 0, SEEK_END) - 3;
    printf("size of file is: %i", fsize);
	printf("\n\n %s \n\n", strbuff);
    
	for (int i; i < length; i++)
	{
		namebuff[4] = i + '0';
		if ((ofd[i] = open(namebuff, O_CREAT | O_RDWR )) == -1){
			perror("could not create file");
			break;
		}
		printf("Opened fd: %d, path: ",ofd[i]);
		printf("%s \n", namebuff);
	}
	for (int i; i < length; i++)
	{
		close(ofd[i]);
		printf("Closed fd: %i \n", ofd[i]);
	}
}

