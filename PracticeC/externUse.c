#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int global_var;

int main(void) 
{
    char s[] = "1230567890";
    printf("memset() 실행전 :: %s\n", s);

    memset(s, '*', strlen(s));
    printf("memset() 실행후 :: %s\n", s);
    return 0;
}