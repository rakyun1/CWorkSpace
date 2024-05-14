#include "Chaining.h"


HashTable* CHT_CreateHashTable(int TableSize)
{
    HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
    HT->Table = (List*)malloc(sizeof(Node) * TableSize);

    // memset() 함수를 통해 HT->Table의 값을 0으로 초기화 하고 있다.
    // HT->Table은 노드로 이루어져 2개의 변수를 갖지만 0으로 초기화 함으로 그 모든 변수들이 0으로 초기화 된다.
    memset(HT->Table, 0, sizeof(List) * TableSize);

    HT->TableSize = TableSize;
    
    return HT;
}

Node* CHT_CreateNode(KeyType Key, ValueType Value)
{
    Node* NewNode = (Node*)malloc(sizeof (Node));

    NewNode->Key = (char*)malloc(sizeof(char) * (strlen(Key) + 1));
    // Key와 Value 모두 char* 형이다. 그러므로 값을 넣어줄 때 strcpy() 함수를 사용해서 넣어줘야 한다.
    // 이렇게 하지 않을 경우 NewNode->Key는 Key 포인터가 가르키는 곳을 가르키게 된다. 그러면 Key가 바뀌거나 할당이 해제되면
    // 똑같이 값이 사라지게 된다.
    strcpy(NewNode->Key, Key);

    NewNode->Value = (char*)malloc(sizeof(char) * (strlen(Value) + 1));
    strcpy(NewNode->Value, Value);
    NewNode->Next = NULL;

    return NewNode;
}

void CHT_DestroyHashTable(HashTable* HT)
{
    int i = 0;
    /* 각 링크드 리스트를 자유 저장소에서 제거 */
    for ( i = 0; i < HT->TableSize; i++)
    {
        List L = HT->Table[i];

        CHT_DestroyList(L);
    }

    /* 해시 테이블을 자유 저장소에서 제거 */
    free(HT->Table);
    free(HT);

}

void CHT_DestroyNode(Node* TheNode)
{
    free(TheNode->Key);
    free(TheNode->Value);
    free(TheNode);
}

void CHT_Set(HashTable* HT, KeyType Key, ValueType Value)
{
    int Address = CHT_Hash(Key, strlen(Key), HT->TableSize);
    Node* NewNode = CHT_CreateNode(Key, Value);

    /* 해쉬 값으로 나온 주소가 비어있을 경우 */
    if (HT->Table[Address] == NULL)
    {
        HT->Table[Address] = NewNode;
    }
    /* 해쉬 값으로 나온 주소에 이미 다른 값이 있는 경우 ㄴ*/
    else
    {
        // 그 주소의 리스트를 가져와서 현재 삽입하려는 노드의 Next에 넣는다.
        // 그러면 현재 삽입하려는 노드가 Head 노드가 되므로 Tail을 찾아서 값을 넣어줄 필요가 없다.
        List L = HT->Table[Address];
        NewNode->Next = L;
        HT->Table[Address] = NewNode;

        printf("Collision occured : Key(%s), Address(%d)\n", Key, Address);
    }
}

ValueType CHT_Get(HashTable* HT, KeyType Key)
{
    int Address = CHT_Hash(Key, strlen(Key), HT->TableSize);

    List TheList = HT->Table[Address];

    List Target = NULL;

    if (TheList == NULL)
    {
        return NULL;
    }

    /* while문을 돌면서 현재 해싱한 주소에 있는 리스트 안에서 같은 Key를 가지고 있는 노드가 있는지 확인한다.*/
    while (1)
    {
        if (strcmp(TheList->Key, Key) == 0)
        {
            Target = TheList;
            break;
        }
        
        if (TheList->Next == NULL)
        {
            break;
        }
        else
            TheList = TheList->Next;
        
    }

    return Target->Value;
}

void CHT_DestroyList(List L)
{
    if (L == NULL)
    {
        return;
    }
    
    if (L->Next != NULL)
    {
        CHT_DestroyList(L->Next);
    }
    
    CHT_DestroyNode(L);
}

int CHT_Hash(KeyType Key, int KeyLength, int TableSize)
{
    int i = 0;
    int HashValue = 0;

    for ( i = 0; i < KeyLength; i++)
    {
        HashValue = (HashValue << 3) + Key[i];
    }
    
    HashValue = HashValue % TableSize;

    return HashValue;
}