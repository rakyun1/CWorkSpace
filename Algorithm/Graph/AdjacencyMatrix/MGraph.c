#include <stdio.h>
#include <string.h>

int main(void)
{
    int nodeCount, edgeCount, i, j, start, end, value;
    
    printf("정점의 개수를 입력하세요\n");
    scanf("%d", &nodeCount);

    printf("간선의 개수를 입력하세요\n");
    scanf("%d", &edgeCount);
    
    int matrix[nodeCount][nodeCount];
    memset(matrix, 0, sizeof(matrix));


    for ( i = 0; i < edgeCount; i++)
    {
        printf("\n\n간선의 정보를 입력하세요\n\n");
        printf("시작 노드 : ");
        scanf("%d", &start);
        printf("\n");

        printf("도착 노드 : ");
        scanf("%d", &end);
        printf("\n");

        printf("가중치 : ");
        scanf("%d", &value);
        printf("\n");

        matrix[start - 1][end - 1] = value;
        matrix[end - 1][start - 1] = value;
    }
    
    for ( i = 0; i < nodeCount; i++)
    {
        for ( j = 0; j < nodeCount; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
}