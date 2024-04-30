#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStack(int* stack, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", stack[i]);
    }
    
    printf("\n");
}

int pop(int* stack, int currentPtr)
{
    int poped = stack[currentPtr];
    stack[currentPtr] = 0;
    return poped;
}

void push(int* stack, int currentPtr, int pushNum)
{
    stack[currentPtr] = pushNum;
}

int main(void)
{
    
    int orderCount, i, pushNum, poped;
    int currentPtr = 0;

    scanf("%d", &orderCount);
    int stack[orderCount];
    for ( i = 0; i < orderCount; i++)
    {
        char order[6];
        scanf("%s", order);
        if (strcmp(order, "push") == 0)
        {
            scanf("%d", &pushNum);
            push(stack, currentPtr++, pushNum);
        }

        if (strcmp(order, "pop") == 0)
        {
            if (currentPtr == 0)
            {
                printf("-1\n");
            }
            else
            {
                poped = pop(stack, --currentPtr);
                printf("%d\n", poped);
            }
        
        }
        
        if (strcmp(order, "size") == 0)
        {
            printf("%d\n", currentPtr);
        }
        
        if (strcmp(order, "empty") == 0)
        {
            if (currentPtr == 0)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
            
        }

        if (strcmp(order, "top") == 0)
        {
            if (currentPtr == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", stack[currentPtr - 1]);
            }
            
        }
        
    }
    
    return 0;
}
