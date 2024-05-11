#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int map[150][150];

int map[60][60];

/* way == 0 :: 아래쪽, way == 1 :: 왼쪽, way == 2 :: 오른쪽, way == 3 :: 위쪽*/
int way = 0;

// int currentPoint[2] = {75,75};
int currentPoint[2] = {30,30};

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
        else
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
        else
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
    
    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            map[i][j] = 1;
        }

    }

    // map[75][75] = 0;
    map[30][30] = 0;

    scanf("%s", query);

    length = strlen(query);
    
    for (i = 0; i < length; i++)
    {
        move(query[i]);        
    }



    int minY = 0;
    int minX = 0;
    int yLength = 0;
    int xLength = 0;

    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (map[i][j] == 0 && minY == 0 && minX == 0)
            {
                minY = i;
                minX = j;
            }
            else if (map[i][j] == 0 && (minY != 0 || minX != 0))
            {
                yLength = i - minY;
                int currentXLength = abs(j - minX);
                if (xLength < currentXLength)
                {
                    xLength = currentXLength;
                }
                
                if (minX > j)
                {
                    minX = j;
                }
                
            }
            
        }
    }

    char answer[yLength + 1][xLength + 1];
    for (i = 0; i < yLength + 1; i++)
    {
        for(int j = 0; j < xLength + 1; j++)
        {
            answer[i][j] = '#';
        }

    }



    for (i = minY; i < minY + yLength + 1; i++)
    {
        for(int j = minX; j < minX + xLength + 1; j++)
        {
            if (map[i][j] == 0)
            {
                answer[i - minY][j - minX] = '.';
            }
            
        }

    }

    for (i = 0; i < yLength + 1; i++)
    {
        for(int j = 0; j < xLength + 1; j++)
        {
            printf("%c", answer[i][j]);
        }
        printf("\n");

    }
    

    return 0;
}
