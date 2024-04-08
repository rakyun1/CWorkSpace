#include <stdio.h>

void p(int num);
void function_without_return();
int add(int num, int num2);

int mainFunction(void)
{
    int num = 2;
    num = add(num, 3);
    p(num);
    return 0;
}

void p(int num)
{
    printf("num은 %d입니다\n", num);
}


void function_without_return()
{
    printf("반환이 없는 함수");
}

int add(int num, int num2)
{
    return num + num2;
}