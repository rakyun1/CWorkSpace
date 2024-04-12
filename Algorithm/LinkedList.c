#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
    int data;
    struct tagNode* nextNode;
} Node;

Node* SLL_CreateNode(int NewData);
void SLL_AppendNode(Node** Head, Node* NewNode);
Node* SLL_GetNodeAt(Node* Head, int Location);
void SLL_DistroyNode(Node* Node);
void SLL_RemoveNode(Node** Head, Node* Remove);

int main(void)
{
    Node* List = NULL;
    Node* NewNode = NULL;

    NewNode = SLL_CreateNode(11);
    SLL_AppendNode(&List, NewNode);


    NewNode = SLL_CreateNode(112);
    SLL_AppendNode(&List, NewNode);

    printf("Head :: %d\n", List->data);

    Node* MyNode = NULL;
    MyNode = SLL_GetNodeAt(List, 1);
    
    printf("탐색 된 노드의 데이터 :: %d\n", MyNode->data);

    SLL_RemoveNode(&List, MyNode);
    SLL_DistroyNode(MyNode);
    

    return 0;
}

Node* SLL_CreateNode(int NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->data = NewData;
    NewNode->nextNode = NULL;
    return NewNode;
}

void SLL_DistroyNode(Node* Node)
{
    free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
    if ((*Head) == NULL)
    {
        *Head = NewNode;
    } 
    else 
    {
        Node* Tail = (*Head);
        while( Tail->nextNode != NULL)
        {
            Tail = Tail->nextNode;
        }
        Tail->nextNode = NewNode;
    }
}


Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->nextNode;
    }
    return Current;
}

void SLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->nextNode;
    }
    else
    {
        Node* Current = *Head;
        while(Current != NULL && Current->nextNode != Remove)
        {
            Current = Current->nextNode;
        }

        if (Current != NULL)
        {
            Current->nextNode = Remove->nextNode;
        }
        
    }
}
