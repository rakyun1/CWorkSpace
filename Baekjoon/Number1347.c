#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int map[150][150];

int map[20][20];

/* way == 0 :: 아래쪽, way == 1 :: 왼쪽, way == 2 :: 오른쪽, way == 3 :: 위쪽*/
int way = 0;

// int currentPoint[2] = {75,75};
int currentPoint[2] = {10,10};

void move(char currentQuery)
{  

    // printf("\ncurrent Way :: %d", way);

    if (currentQuery == 'R')
    {
        if (way == 0)
        {
            way = 1;
        }
        else if (way == 1)
        {
            way = 3;
        }
        else if (way == 2)
        {
            way = 0;
        }
        else if (way == 3)
        {
            way = 2;
        }
        
    }

    if (currentQuery == 'L')
    {
        if (way == 0)
        {
            way = 2;
        }
        else if (way == 1)
        {
            way = 0;
        }
        else if (way == 2)
        {
            way = 3;
        }
        else if (way == 3)
        {
            way = 1;
        }
        
    }

    if (currentQuery == 'F')
    {
        if (way == 0)
        {
            currentPoint[0] += 1;
        }
        
        if (way == 1)
        {
            currentPoint[1] -= 1;
        }
        
        if (way == 2)
        {
            currentPoint[1] += 1;
        }
        
        if (way == 3)
        {
            currentPoint[0] -= 1;
        }    

        map[currentPoint[0]][currentPoint[1]] = 0;
    }

    // printf("\ncurrent Way :: %d\n", way);
}


int main(void)
{
    int inputCount, i, length;
    char* query = (char*)malloc(sizeof(char) * 51);

    scanf("%d", &inputCount);
    
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            map[i][j] = 1;
        }

    }

    // map[75][75] = 0;
    map[10][10] = 0;

    scanf("%s", query);

    length = strlen(query);
    
    for (i = 0; i < length; i++)
    {
        move(query[i]);        
    }

    printf("\n\n-------------------------------------------------\n\n");
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}
