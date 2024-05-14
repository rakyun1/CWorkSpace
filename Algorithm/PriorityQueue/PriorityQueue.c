#include "PriorityQueue.h"


PriorityQueue* PQ_Create(int InitialSize)
{
    PriorityQueue* NewPQ = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    NewPQ->Capacity = InitialSize;
    NewPQ->UsedSize = 0;
    NewPQ->Nodes = (PQNode*)malloc(sizeof(PQNode) * NewPQ->Capacity);

    return NewPQ;
}

// 동적 배열로 만들어진 경우 노드들이 연속적인 메모리 공간에 할당 되게 된다.
// 그런 경우 Nodes만 할당 해제 해도 모든 노드들이 할당 해제 된다.
void PQ_Destroy(PriorityQueue* PQ)
{
    free(PQ->Nodes);
    free(PQ);
}

void PQ_Enqueue(PriorityQueue* PQ, PQNode NewNode)
{
    int CurrentPosition = PQ->UsedSize;
    int ParentPosition = PQ_GetParent(CurrentPosition);

    if (PQ->UsedSize == PQ->Capacity)
    {
        if (PQ->Capacity == 0)
        {
            PQ->Capacity = 1;
        }
        
        PQ->Capacity *= 2;
        PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
    }

    PQ->Nodes[CurrentPosition] = NewNode;

    while (CurrentPosition > 0 && PQ->Nodes[CurrentPosition].Priority < PQ->Nodes[ParentPosition].Priority)
    {
        PQ_SwapNodes(PQ, CurrentPosition, ParentPosition);

        CurrentPosition = ParentPosition;
        ParentPosition = PQ_GetParent(CurrentPosition);
    }
    
    PQ->UsedSize++;
}

void PQ_SwapNodes(PriorityQueue* PQ, int index1, int index2)
{
    int CopySize = sizeof(PQNode);
    PQNode* Temp = (PQNode*)malloc(CopySize);

    memcpy(Temp, &PQ->Nodes[index1], CopySize);
    memcpy(&PQ->Nodes[index1], &PQ->Nodes[index2], CopySize);
    memcpy(&PQ->Nodes[index2], Temp, CopySize);

    free(Temp);
}

void PQ_Dequeue(PriorityQueue* PQ, PQNode* Root)
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    // 이 코드는 조금 이해가 가지 않는 부분이 있다. 나는 Dequeue 함수가 왜 void인지 의문이었는데
    // 삭제되는 값을 메인 함수에 있는 변수에 저장하기 때문에, 삭제되는 값을 리턴해줄 필요가 없었던 것이다.
    // 즉 메인 함수는 항상 삭제되는 값을 필드에 가지고 있다.
    // 이렇게 하지 않고 지역 변수로 노드를 하나 만들어서 거기에 값을 담고 리턴하는 방식으로 해도 될거 같은데 
    // 이렇게 한 이유가 있을까?
    memcpy(Root, &PQ->Nodes[0], sizeof(PQNode));
    memset(&PQ->Nodes[0], 0, sizeof(PQNode));

    PQ->UsedSize--;
    PQ_SwapNodes(PQ, 0, PQ->UsedSize);

    LeftPosition = PQ_GetLeftChild(0);
    RightPosition = LeftPosition + 1;

    while (1)
    {
        int SelectedChild = 0;

        if (LeftPosition >= PQ->UsedSize)
        {
            break;
        }
        
        if (RightPosition >= PQ->UsedSize)
        {
            SelectedChild = LeftPosition;
        }
        else
        {
            if (PQ->Nodes[LeftPosition].Priority > PQ->Nodes[RightPosition].Priority)
            {
                SelectedChild = RightPosition;
            }
            else
                SelectedChild = LeftPosition;
            
        }
        
        if (PQ->Nodes[SelectedChild].Priority < PQ->Nodes[ParentPosition].Priority)
        {
            PQ_SwapNodes(PQ, ParentPosition, SelectedChild);
            ParentPosition = SelectedChild;
        }
        else
            break;
        
        LeftPosition = PQ_GetLeftChild(ParentPosition);
        RightPosition = LeftPosition + 1;

    }
    
    if (PQ->UsedSize < (PQ->Capacity / 2))
    {
        PQ->Capacity /= 2;
        PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
    }
    
}

int PQ_GetParent(int Index)
{
    return (int) ((Index - 1)/ 2);
}

int PQ_GetLeftChild(int Index)
{
    return (2 * Index) + 1;
}

int PQ_IsEmpty(PriorityQueue* PQ)
{
    return (PQ->UsedSize == 0);
}