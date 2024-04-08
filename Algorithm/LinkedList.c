#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
    int data;
    struct tagNode* nextNode;
} Node;

int main(void)
{
    Node node = {1, NULL};

    Node* nodep;
    nodep = (Node*)malloc(10);
    nodep[0].data = 1;
    nodep->nextNode = NULL;

    printf("%d\n", sizeof(node));
    printf("%d\n", sizeof(nodep));

    return 0;
}
