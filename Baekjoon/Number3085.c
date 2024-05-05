#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char color[4] = {'C', 'P', 'Z', 'Y'};
int boardSize, i, j;

int searchGaro(int** board, int count, int y, int x)
{
    if (x + 1 == boardSize - 1)
    {
        if (isCanChange() == 0)
        {
            return count;
        }
        else
        {
            
        }
    }
    
    if (board[y][x + 1] == board[y][x])
    {
        return countLongestAt(board, count + 1, y, x + 1);
    }
    else
    {
        if (isCanChange() == 0)
        {
            return count;
        }
        else
        {

        }
        
    }

}

int searchSero(int** board, int count, int y, int x)
{
    
    if (board[y + 1][x] == board[y][x])
    {
        return countLongestAt(board, count + 1, y, x + 1);
    }
    else
    {

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
            if (j != boardSize - 1 && board[i][j] == board[i][j + 1])
            {
                searchGaro(board, 1, i, j + 1);
            }
            if (i != boardSize - 1 && board[i][j] == board[i + 1][j])
            {
                searchSero(board, 1, i + 1, j);
            }
            
            
        }

    }

    // printf("\n");
    // for (i = 0; i < boardSize; i++)
    // {
    //     for ( j = 0; j < boardSize; j++)
    //     {
    //         printf("%d ", board[i][j]);
    //     }
    //     printf("\n");
    // }
    


    return 0;
}
