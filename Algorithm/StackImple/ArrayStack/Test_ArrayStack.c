#include "ArrayStack.h"

int main(void)
{
    int i = 0;
    ArrayStack* Stack = NULL;

    AS_CreateStack(&Stack, 10);

    AS_Push(&Stack, 3);
    AS_Push(&Stack, 37);
    AS_Push(&Stack, 11);
    AS_Push(&Stack, 12);

    printf("Capacity :: %d, Size :: %d, Top :: %d \n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

    for ( i = 0; i < 4; i++)
    {
        if (AS_IsEmpty(Stack))
        {
            break;
        }
        printf("Popped :: %d, ", AS_Pop(&Stack));
        printf("현재 스택 용량 :: %d\n", Stack->Capacity);
        if (!AS_IsEmpty(Stack))
        {
            printf("Current Top :: %d\n", AS_Top(Stack));
        }
        else
            printf("Stack Is Empty. \n");
    }

    // if (AS_IsFull(Stack))
    // {
    //     printf("스택 용량이 꽉 찼습니다.\n");
    //     printf("%d\n", Stack->Capacity);
    // }
    // else
    // {
    //     printf("스택 용량이 아직 남아있습니다.\n");
    // }    

    // for ( i = 0; i < Stack->Capacity; i++)
    // {
    //     AS_Push(&Stack, i);
    //     printf("스택에 %d를 푸시함\n", i);
    //     printf("스택의 Top :: %d\n", AS_Top(Stack));
    // }
    
    // if (AS_IsFull(Stack))
    // {
    //     printf("스택 용량이 꽉 찼습니다.\n");
    //     printf("현재 스택의 용량 :: %d\n", Stack->Capacity);
    // }
    // else
    // {
    //     printf("스택 용량이 아직 남아있습니다.\n");
    // }    

    // AS_Push(&Stack, 100);
    // printf("스택의 Top :: %d\n", AS_Top(Stack));
    // printf("현재 스택의 용량 :: %d\n", Stack->Capacity);


    // printf("스택 개수 :: %d\n", AS_GetSize(Stack));

    AS_DestroyStack(Stack);
    return 0;
    
}