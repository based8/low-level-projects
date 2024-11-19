#include <stdio.h>
int *firstptr = NULL;
int *secondptr = NULL;

void firstfunc() 
{ 
    int a;
    firstptr = &a;
}
int main()
{
    int a;
    secondptr = &a;

    (main, firstfunc) ? printf("%p, %p,---> DOWN\n", main, firstfunc) : printf("%p, %p,---> UP\n", main, firstfunc);

    return 0;
}
