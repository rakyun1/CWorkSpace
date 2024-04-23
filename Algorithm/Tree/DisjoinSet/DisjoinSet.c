#include "DisjoinSet.h"


DisjoinSet* Ds_MakeSet(void* NewData)
{
    DisjoinSet* NewNode = (DisjoinSet*)malloc(sizeof(DisjoinSet));
    NewNode->Data = NewData;
    NewNode->Parent = NULL;

    return NewNode;
}

void DS_UnionSet(DisjoinSet* Set1, DisjoinSet* Set2)
{
    Set2 = Ds_FindSet(Set2);
    Set2->Parent = Set1;
}

DisjoinSet* Ds_FindSet(DisjoinSet* Set)
{
    while (Set->Parent != NULL)
    {
        Set = Set->Parent;
    }

    return Set;
}

void Ds_DestroySet(DisjoinSet* Set)
{
    free(Set);
}