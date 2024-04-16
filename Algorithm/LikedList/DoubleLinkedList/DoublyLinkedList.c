#include "DoublyLinkedList.h"

/* 노드 생성 */
Node* DLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

/* 노드 소멸 */
void DLL_DestroyNode(Node* Node)
{
    free(Node);
}

/* 노드 추가 */
void DLL_AppendNode(Node** Head, Node* NewNode)
{
    if (*Head == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        Node* Tail = *Head;
        while(Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
    }
    
}

/* 노드 삽입 */
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
    if (Current->NextNode == NULL)
    {
        Current->NextNode = NewNode;
        NewNode->PrevNode = Current;
    }
    else
    {
        Current->NextNode->PrevNode = NewNode;
        NewNode->PrevNode = Current;
        NewNode->NextNode = Current->NextNode;
        Current->NextNode = NewNode;
    }
    
}

/* 노드 제거 */
void DLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
        if ((*Head) != NULL)
        {
            (*Head)->PrevNode = NULL;
        }
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else
    {
        Node* Temp = Remove;
        if (Remove->PrevNode != NULL)
        {
            Remove->PrevNode->NextNode = Temp->NextNode;
        }
        if (Remove->NextNode != NULL)
        {
            Remove->NextNode->PrevNode = Temp->PrevNode;
        }
        
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    
}

/* 노드 탐색 */
Node* DLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;
    while(Current != NULL && --Location >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

/* 노드 수 세기 */
int DLL_GetNodeCount(Node* Head)
{
    unsigned int Count = 0;
    Node* Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }
    
    return Count;
}

void PrintNode(Node* Node)
{
    if (Node->PrevNode == NULL)
    {
        printf("Prev :: NULL");
    }
    else
        printf("Prev :: %d\n", Node->PrevNode->Data);
    
    printf("Current :: %d\n", Node->Data);
    
    if (Node->NextNode == NULL)
    {
        printf("Next :: NULL");
    }
    else
        printf("Next :: %d\n", Node->NextNode->Data);
}

void printReverse(Node* Head)
{
    Node* Tail = Head;
    while (Tail->NextNode != NULL)
    {
        Tail = Tail->NextNode;
    }
    
    while (Tail->PrevNode != NULL)
    {
        printf("Node :: %d\n", Tail->Data);
        Tail = Tail->PrevNode;
    }
    
}