#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char color[4] = {'C', 'P', 'Z', 'Y'};
int boardSize, i, j;


int isCanChange(int** board, int y, int x)
{
    if (y < boardSize - 1 && board[y + 1][x] == board[y][x])
    {
        return 1;
    }
    if (y > 0 && board[y - 1][x] == board[y][x])
    {
        return 1;
    }
    if (x < boardSize - 1 && board[y][x + 1] == board[y][x])
    {
        return 1;
    }
    if (x > 0 && board[y][x - 1] == board[y][x])
    {
        return 1;
    }
    
    return 0;
}

int searchGaro(int** board, int count, int y, int x, int changed)
{
    if (x >= boardSize - 1)
    {
        return count;
    }
    else
    {
        if (board[y][x] != board[y][x + 1] && changed == 0)
        {
            changed = 1;
            if (isCanChange(board, y, x) == 0)
            {
                return count;
            }
            else
            {
                searchGaro(board, count + 1, y, x + 1, changed);
            }
        }
        else
        {
            return searchGaro(board, count + 1, y, x + 1, changed);
        }

    }
    
}

int searchSero(int** board, int count, int y, int x, int changed)
{
    if (y == boardSize - 1)
    {
        return count;
    }
    else
    {
        if (board[y][x] != board[y + 1][x] && changed == 0)
        {
            changed = 1;
            if (isCanChange(board, y, x) == 0)
            {
                return count;
            }
            else
            {
                searchSero(board, count + 1, y  + 1, x, changed);
            }
        }
        else
        {
            return searchSero(board, count + 1, y + 1, x, changed);
        }

    }

}

int changeColorToNumber(char target)
{
    for ( i = 0; i < 4; i++)
    {
        if (color[i] == target)
        {
            return i + 1;
        }
        
    }

    return 0;
}

int main(void)
{   
    /* 
        dfs로 탐색하며 같은 색깔이 오른쪽, 아래쪽에 있을 경우 다시 타고 들어감
        만약 chaged 변수가 0이라면, 한 번 색을 교환 할 수 있으므로 내가 현재 탐색하고 있는 색과
        같은 색이 다음 색의 주변에 있는지 확인후에 있다면 교환하고 count++ 후에다시 dfs를 실행
    */
    int max = 0;
    char currentColor;
    scanf("%d", &boardSize);

    int board[boardSize][boardSize];
    memset(board, 0, sizeof(board));

    for (i = 0; i < boardSize; i++)
    {
        for ( j = 0; j < boardSize; j++)
        {
            scanf(" %c", &currentColor);
            board[i][j] = changeColorToNumber(currentColor);
        }

    }

    for (i = 0; i < boardSize; i++)
    {
        for ( j = 0; j < boardSize; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");

    }

    for (i = 0; i < boardSize; i++)
    {
        for ( j = 0; j < boardSize; j++)
        {
            int result;
            if (j != boardSize - 1)
            {
                result = searchGaro(board, 1, i, j + 1, 0);
            }
            if (i != boardSize - 1)
            {
                result = searchSero(board, 1, i + 1, j, 0);
            }
            if (max < result)
            {
                max = result;
            }
            
        }

    }
    printf("%d\n", max);

    return 0;
}
