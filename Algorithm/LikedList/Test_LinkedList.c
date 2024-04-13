#include "LinkedList.h"

int main(void)
{
    int i = 0;
    int Count = 0;
    Node* List = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;

    /* 노드 5개 추가 */
    for ( i = 0; i < 5; i++)
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }
    
    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);

    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);

    /* 리스트 출력 */
    Count = SLL_GetNodeCount(List);
    for ( i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] :: %d\n", i, Current->Data);
    }
    



    return 0;
}