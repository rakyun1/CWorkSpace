#include "CircularDoublyLinkedList.h"

/* 노드 생성 */
Node* CDLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;
    NewNode->totalCount = 0;

    return NewNode;
}

/* 노드 소멸 */
void CDLL_DestroyNode(Node* Node)
{
    free(Node);
}

/* 노드 추가 */
void CDLL_AppendNode(Node** Head, Node* NewNode)
{
    if ((*Head) == NULL)
    {
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
        (*Head)->totalCount = 1;
    }
    else
    {
        Node* Tail = (*Head)->PrevNode;
        Tail->NextNode = NewNode;
        (*Head)->PrevNode = NewNode;
        NewNode->PrevNode = Tail;
        NewNode->NextNode = (*Head);
        (*Head)->totalCount++;
    }

}

/* 노드 제거 */
void CDLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        (*Head)->PrevNode->NextNode = Remove->NextNode;
        (*Head)->NextNode->PrevNode = Remove->PrevNode;

        *Head = Remove->NextNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
        
        (*Head)->totalCount--;
    }
    else
    {
        Node* Temp = Remove;

        Remove->NextNode->PrevNode = Temp->PrevNode;
        Remove->PrevNode->NextNode = Temp->NextNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;

        (*Head)->totalCount--;
    }
    
}

int CDLL_GetNodeCount(Node* Head)
{
    return Head->totalCount;
}

Node* CDLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while(Current != NULL && --Location >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}