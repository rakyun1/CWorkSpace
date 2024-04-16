#include "CircularDoublyLinkedList.h"

int main(void)
{
    int i = 0;
    int Count = 0;
    Node* List = NULL;
    Node* NewNode = NULL;
    Node* Current = NULL;

    /* 노드 5개 추가 */
    for ( i = 0; i < 5; i++)
    {
        NewNode = CDLL_CreateNode(i);
        CDLL_AppendNode(&List, NewNode);
    }

    Count = CDLL_GetNodeCount(List);
    printf("현재 노드 개수 :: %d\n", Count);
    for ( i = 0; i < Count; i++)
    {
        Current = CDLL_GetNodeAt(List, i);
        printf("List[%d] :: %d\n", i, Current->Data);
    }
        
}