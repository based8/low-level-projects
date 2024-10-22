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
	char namebuff[64] = {'o','u','t','p','x','.','t','x','t'};
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

    int split = 0;

	for (int i = 0; i < length; i++)
	{
		namebuff[4] = i + '0';
		if ((ofd[i] = open(namebuff, O_CREAT | O_RDWR , S_IRWXU)) == -1){
			perror("could not create file");
			continue;
		}
		printf("Opened fd: %i \n",ofd[i]);

        char* strpart = malloc(10 * sizeof(char));
        if (!(memcpy(strpart, strbuff + split,(fsize/length) * sizeof(char)))){
            perror("memory allocation failed");
            return 0;
        }
        printf("\n \" %s \" \n\n", strpart);
        if ((write(ofd[i], strpart, sizeof(char) * (fsize/length))) == -1){
            perror("could not write to file");
		    printf("CONTINUING!!\n");
            continue;
        }
        split += fsize/length;
        free(strpart);
		close(ofd[i]);
  	}
}

