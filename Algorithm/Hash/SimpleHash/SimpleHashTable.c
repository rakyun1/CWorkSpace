#include "SimpleHashTable.h"


HashTable* SHT_CreateHashTable(int TableSize)
{
    HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
    // 테이블 사이즈만큼만 테이블에 저장공간을 할당해준다.
    HT->Table = (Node*)malloc(sizeof(Node) * TableSize);
    HT->TableSize = TableSize;
    
    return HT;
}

void SHT_Set(HashTable* HT, KeyType Key, ValueType Value)
{
    // 해쉬를 할 때에는 키와 테이블 사이즈로 값을 얻어낸다.
    int Address = SHT_Hash(Key, HT->TableSize);

    // Hash() 함수를 통해 알아낸 주소 값에 값을 저장해준다.
    HT->Table[Address].Key = Key;
    HT->Table[Address].Value = Value;

}

ValueType SHT_Get(HashTable* HT, KeyType Key)
{
    int Address = SHT_Hash(Key, HT->TableSize);

    return HT->Table[Address].Value;
}

void SHT_DestroyHashTable(HashTable* HT)
{
    free(HT->Table);
    free(HT);
}

int SHT_Hash(KeyType Key, int TableSize)
{
    return Key % TableSize;
}