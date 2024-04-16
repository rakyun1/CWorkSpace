#include "DoublyLinkedList.h"

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
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List, NewNode);
    }

    Count = DLL_GetNodeCount(List);
    for ( i = 0; i < Count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] :: %d\n", i, Current->Data);
    }

    printReverse(List);
    
    
}