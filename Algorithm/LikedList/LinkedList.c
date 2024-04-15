#include "LinkedList.h"

/* 노드 생성 */
Node* SLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;
    return NewNode;
}

/* 노드 소멸 */
void SLL_DestroyNode(Node* Node)
{
    free(Node);
}

/* 노드 추가 */
void SLL_AppendNode(Node** Head, Node* NewNode)
{
    if ((*Head) == NULL)
    {
        *Head = NewNode;
    } 
    else 
    {
        Node* Tail = (*Head);
        while( Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
    }
}

/* 노드 삽입 */
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if (*Head == NULL)
    {
        *Head = NewHead;
    }
    else
    {
        NewHead->NextNode = *Head;
        (*Head) = NewHead;
    }
}

void SLL_InsertBefore(Node** Head, Node* Current, Node* NewNode)
{
    if (*Head == NULL || *Head == Current)
    {
        NewNode->NextNode = Current;
        *Head = NewNode;
    } else {
        Node* Temp = *Head;
        while(Temp != NULL && Temp->NextNode != Current)
        {
            Temp = Temp->NextNode;
        }
        if (Temp != NULL)
        {
            Temp->NextNode = NewNode;
            NewNode->NextNode = Current;
        }
        
    }
    
}

/* 노드 제거 */
void SLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
    }
    else
    {
        Node* Current = *Head;
        while(Current != NULL && Current->NextNode != Remove)
        {
            Current = Current->NextNode;
        }

        if (Current != NULL)
        {
            Current->NextNode = Remove->NextNode;
        }
    }
}

void SLL_DestroyALLNodes(Node** List)
{
    Node* Current = *List;
    if (Current->NextNode == NULL)
    {
        free(Current);
        return;
    }
    
    Node* Next = Current->NextNode;
    while(Next != NULL) {
        free(Current);
        Current = Next;
        Next = Next->NextNode;
    }
    free(Current);
    
}

/* 노드 탐색 */
Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }
    return Current;
}

/* 노드 수 세기 */
int SLL_GetNodeCount(Node* Head)
{
    Node* Current = Head;

    int count = 0;
    while(Current != NULL)
    {
        Current = Current->NextNode;
        count++;
    }
    return count;
}
