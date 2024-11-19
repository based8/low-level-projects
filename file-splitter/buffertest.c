#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

int main() {
	int ifd;
	int ofd[3];
	int length = sizeof(ofd) / sizeof(int);
	char strbuff[1024];
        char strbuff2[1024];	
	char namebuff[64] = {'o','u','t','p'};

	if ((ifd = open("data/example.txt", O_RDONLY)) == -1){
		perror("could not open input file");
		return 0;
	}
	if ((read(ifd, strbuff, sizeof(strbuff))) == -1){
		perror("could not read input file");
		return 0;
	}
	printf("\n\n %s \n\n", strbuff);
	for (int i; i < length; i++)
	{
		namebuff[4] = i + '0';
		if ((ofd[i] = open(namebuff, O_CREAT | O_RDWR )) == -1){
			perror("could not create or open file");
			return 0;
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

