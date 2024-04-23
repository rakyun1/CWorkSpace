#include "DisjoinSet.h"

int main(void)
{
    int a = 1, b = 2, c = 3, d = 4;
    DisjoinSet* Set1 = Ds_MakeSet(&a);
    DisjoinSet* Set2 = Ds_MakeSet(&b);
    DisjoinSet* Set3 = Ds_MakeSet(&c);
    DisjoinSet* Set4 = Ds_MakeSet(&d);

    printf("Set1 == Set2 : %d\n", Ds_FindSet(Set1) == Ds_FindSet(Set2));

    DS_UnionSet(Set1, Set3);
    printf("Set1 == Set3 : %d\n", Ds_FindSet(Set1) == Ds_FindSet(Set3));

    DS_UnionSet(Set3, Set4);
    printf("Set3 == Set4 : %d\n", Ds_FindSet(Set3) == Ds_FindSet(Set4));

    return 0;
}
