#include <stdio.h>
#include <string.h>

void Backtracking(int map[10][10]);
int isComplete(int map[10][10]);
int checkGaro(int map[10][10]);
int checkSero(int map[10][10]);
int checkSquare(int map[10][10]);

int main(void)
{   
    int i, j;
    int map[10][10];
    for ( i = 0; i < 10; i++)
    {
        for ( j = 0; j < 10; j++)
        {
            map[i][j] = 0;
        }
        
    }

    Backtracking(map);

    return 0;
}

void Backtracking(int map[10][10])
{   
    if(isComplete(map)) 
    {
        return;
    }

    int i, j;
    for ( i = 0; i < 10; i++)
    {
        for ( j = 0; j < 10; j++)
        {
            if (map[i][j] == 0)
            {
                for (int k = 1; k <= 10; k++)
                {
                    map[i][j] = k;
                    if (checkSero(map) && checkGaro(map) && checkSquare(map))
                    {
                        Backtracking(map);
                    }
                    map[i][j] = 0;
                }
            }
        }
        
    }
}

int isComplete(int map[10][10])
{
    return 0;
}

int checkGaro(int map[10][10])
{

    return 0;
}

int checkSero(int map[10][10])
{

    return 0;
}

int checkSquare(int map[10][10])
{

    return 0;
}