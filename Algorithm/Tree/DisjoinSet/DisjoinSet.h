#ifndef DISJOINSET_H
#define DISJOINSET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagDisjoinSet
{
    struct tagDisjoinSet* Parent;
    void* Data;
} DisjoinSet;

DisjoinSet* Ds_MakeSet(void* NewData);
void DS_UnionSet(DisjoinSet* Set1, DisjoinSet* Set2);
DisjoinSet* Ds_FindSet(DisjoinSet* Set);
void Ds_DestroySet(DisjoinSet* Set);

#endif