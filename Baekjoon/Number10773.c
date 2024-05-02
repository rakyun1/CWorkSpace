#include <stdio.h>

void initailize(int* order, int length)
{
    for (int i = 0; i < length; i++)
    {
        order[i] = 0;
    }
    
}

int main(void)
{
    int i, orderCount, nextOrder, sum = 0;
    int ptr = 0;

    scanf("%d", &orderCount);
    int order[orderCount];

    initailize(order, orderCount);

    for ( i = 0; i < orderCount; i++)
    {
        scanf("%d", &nextOrder);

        if (nextOrder == 0)
        {
            if (ptr != 0)
            {
                order[--ptr] = 0;
            }
            
        }
        else
        {
            order[ptr++] = nextOrder;
        }


        // printf("\n\n=============현재 order===========\n\n");
        // for ( int j = 0; j < orderCount; j++)
        // {
        //     printf("%d ", order[j]);
        // }
        // printf("\n현재 포인터 : %d\n", ptr);
    }
    
    for ( i = 0; i < orderCount; i++)
    {
        sum += order[i];
    }
    
    printf("%d\n", sum);

    return 0;
}
