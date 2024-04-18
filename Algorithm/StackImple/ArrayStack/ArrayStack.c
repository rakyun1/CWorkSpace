#include "ArrayStack.h"


void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

    (*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);

    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = 0;
}

void AS_DestroyStack(ArrayStack* Stack)
{
    free(Stack->Nodes);

    free(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data)
{
    int Position = Stack->Top;
    if(AS_IsFull(Stack))
    {
        int currentCapacity = Stack->Capacity;
        currentCapacity += currentCapacity * 0.3;
        Stack->Capacity = currentCapacity;

        printf("\n\n스택의 용량이 초과되었으므로 용량이 30프로 올라갑니다.\n\n");
    }

    Stack->Nodes[Position].Data = Data;
    Stack->Top++;
}

ElementType AS_Pop(ArrayStack* Stack)
{
    int Position = --(Stack->Top);
    
    if (Position < Stack->Capacity * 0.7)
    {
        Stack->Capacity -= Stack->Capacity * 0.3;

        printf("\n\n스택의 용량이 70프로 미만이므로 용량이 30프로 줄어듭니다.\n\n");
    }
    

    return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack)
{
    int Position = Stack->Top - 1;
    return Stack->Nodes[Position].Data;
}

int AS_GetSize(ArrayStack* Stack)
{
    return Stack->Top;
}
int AS_IsEmpty(ArrayStack* Stack)
{
    return (Stack->Top == 0);
}

int AS_IsFull(ArrayStack* Stack)
{
    if (Stack->Top == Stack->Capacity)
    {
        return 1;
    }
    return 0;
}