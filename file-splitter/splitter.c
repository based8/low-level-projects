#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main() {
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
        perror("could not read input into buffer");
        return 0;
    }

    fsize = lseek(ifd, 0, SEEK_END) - 3;
    printf("size of file is: %i bytes %i \n ", fsize);

	for (int i = 0; i < length; i++)
	{
		namebuff[4] = i + '0';
		if ((ofd[i] = open(namebuff, O_CREAT | O_RDWR )) == -1){
			perror("could not create file");
			continue;
		}
        char* strpart = malloc((fsize/length) * sizeof(char));
        if (!(memcpy(strpart, namebuff, sizeof(namebuff)))){
            perror("memory allocation failed");
            return 0;
        }

		printf("Opened fd: %d, path: %s \n",ofd[i], namebuff);
	}
	for (int i = 0; i < length; i++)
	{
		close(ofd[i]);
		printf("Closed fd: %i \n", ofd[i]);
	}
}

