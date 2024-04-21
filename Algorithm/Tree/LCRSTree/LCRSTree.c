#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode(ElementType NewData)
{
    LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
    NewNode->LeftChild = NULL;
    NewNode->RightSibling = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void LCRS_DestroyNode(LCRSNode* Node)
{
    free(Node);
}

void LCRS_DestroyTree(LCRSNode* Root)
{
    if (Root->RightSibling != NULL)
    {
        LCRS_DestroyTree(Root->RightSibling);
    }
    if (Root->LeftChild != NULL)
    {
        LCRS_DestroyTree(Root->LeftChild);
    }
    
    Root->LeftChild = NULL;
    Root->RightSibling = NULL;

    LCRS_DestroyNode(Root);
    
}

void LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode)
{
    if (ParentNode->LeftChild == NULL)
    {
        ParentNode->LeftChild = ChildNode;
    }
    else
    {
        LCRSNode* Child = ParentNode->LeftChild;
        while (Child->RightSibling != NULL)
        {
            Child = Child->RightSibling;
        }
        Child->RightSibling = ChildNode;
    }
    
}

void LCRS_PrintTree(LCRSNode* Node, int Depth)
{
    int i = 0;
    for ( i = 0; i < Depth; i++)
    {
        printf(" ");
    }
    printf("%c\n", Node->Data);
    
    if (Node->LeftChild != NULL)
    {
        LCRS_PrintTree(Node->LeftChild, Depth + 1);
    }

    if (Node->RightSibling != NULL)
    {
        LCRS_PrintTree(Node->RightSibling, Depth);
    }
    
}

void LCRS_PrintNodesAtLevel(LCRSNode* Root, int Level, int currentLevel)
{
    // printf("현재 레벨 :: %d, 현재 노드 :: %c\n", currentLevel, Root->Data);
    
    if (Level == currentLevel)
    {
        printf("%c\n", Root->Data);
    }
    else
    {
        LCRSNode* Child = Root->LeftChild;
        while (1)
        {
            LCRS_PrintNodesAtLevel(Child, Level, currentLevel + 1);
            
            if (Child->RightSibling == NULL)
            {
                break;
            }
            else
            {
                Child = Child->RightSibling;
            }
        }
        
    }
    
}