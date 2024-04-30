#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int ElemenType;

typedef struct tagHeapNode
{
    ElemenType Data;
} HeapNode;

typedef struct tagHeap
{
    HeapNode* Nodes;
    int Capacity;
    int UsedSize;
} Heap;

Heap* HEAP_Create(int InitialSize);
void HEAP_Destroy(Heap* H);
void HEAP_Insert(Heap* H, ElemenType NewData);
void HEAP_DeleteMin(Heap* H, HeapNode* Root);
int HEAP_GetParent(int index);
int HEAP_GetLeftChild(int index);
void HEAP_SwapNodes(Heap* H, int index1, int index2);
void HEAP_PrintNodes(Heap* H);

#endif