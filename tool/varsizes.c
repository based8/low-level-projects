#include <stdio.h>

// Byte sizes of different data types

int main(int argc, char* argv){
    printf("Integer, %i bytes \n", sizeof(int));
    printf("Double, %i bytes \n", sizeof(double));
    printf("Char, %i bytes \n", sizeof(char));
    printf("Float, %i bytes \n", sizeof(float));
    printf("Pointer, %i bytes \n", sizeof(void *));
    printf("Int pointer %i bytes \n", sizeof(int *));
}
