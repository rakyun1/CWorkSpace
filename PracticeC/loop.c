#include <stdio.h>

int mainLoop(void)
{
    printf("\n\n----------------------------------------------------------------------------------\n\n");

    // int a = 10;
    // printf("a는 %d\n", a += 1);
    // printf("a는 %d\n", a);
    
    int a = 10;
    // for (int i = 0; i < 100; i++)
    // {
    //     printf("for문 %d\n", a + i);
    // }

    // for (int i = 2; i < 10; i++)
    // {
    //         printf("------%d단-------\n\n", i);
    //     for (int j = 1; j < 10; j++)
    //     {
    //         printf("%d 곱하기 %d 는 :: %d\n", i,j,i*j);   
    //     }
    // }
    
    // for (int i = 5; i >= 0; i--)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         printf("*");
    //     }
    //     printf("\n");
    // }
    
    int floor;
    printf("몇 층으로 쌓겠느냐 ? ");
    scanf("%d", &floor);
    for (int i = 0; i < floor; i++)
    {
        for (int j = i; j < floor - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i * 2 + 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    
























    printf("\n\n----------------------------------------------------------------------------------\n\n");
    return 0;
}