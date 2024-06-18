#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Move {
	int moveCount;
	char moveWay;
} MoveInfo;


int getMoveCount(MoveInfo **board, int boardSize, int currentY, int currentX);

int main() {
	int boardSize, 
    goormY, goormX, 
    playerY, playerX,
    goormCount, playerCount;
	
	scanf("%d", &boardSize);
	scanf("%d", &goormY);
	scanf("%d", &goormX);
	scanf("%d", &playerY);
	scanf("%d", &playerX);
	
	MoveInfo **board = (MoveInfo **)malloc(boardSize * sizeof(MoveInfo *));
	for (int i = 0; i < boardSize; i++) {
		board[i] = (MoveInfo *)malloc(boardSize * sizeof(MoveInfo));
	}
    
    char *input = (char*)malloc(3 * sizeof(char));
	

	for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            scanf("%s", input);
            board[i][j].moveCount = atoi(input);
            board[i][j].moveWay = input[strlen(input) - 1];
        }
	}

    goormCount = getMoveCount(board, boardSize, goormY - 1, goormX - 1);

    playerCount = getMoveCount(board, boardSize, playerY - 1, playerX - 1);

	if (goormCount > playerCount) {
        printf("goorm %d\n", goormCount);
    }
    else {
        printf("player %d\n", playerCount);
    }
	
	return 0;
}


int getMoveCount(MoveInfo **board, int boardSize, int currentY, int currentX)
{
    int moveCount;
    int visited[boardSize][boardSize];
    int moveWay[2];

    memset(visited, 0, sizeof(int) * boardSize * boardSize);
    // for (int i = 0; i < boardSize; i++) {
    //     for (int j = 0; j < boardSize; j++) {
    //         visited[i][j] = 0;
    //     }
    // }

    
    int isEnd = 1;
    int result = 0;

    while (isEnd) {
        moveCount = board[currentY][currentX].moveCount;

        if (board[currentY][currentX].moveWay == 'U')
        {
            moveWay[0] = -1;
            moveWay[1] = 0;
        }
        else if (board[currentY][currentX].moveWay == 'D')
        {
            moveWay[0] = 1;
            moveWay[1] = 0;
        }
        else if (board[currentY][currentX].moveWay == 'R')
        {
            moveWay[0] = 0;
            moveWay[1] = 1;
        }
        else
        {
            moveWay[0] = 0;
            moveWay[1] = -1;
        }

        while(moveCount > 0)
        {
            visited[currentY][currentX] = 1;

            currentY += moveWay[0];
            currentX += moveWay[1];

            result++;
            
            moveCount--;

            if (currentY >= boardSize) currentY = 0;
            else if (currentY < 0) currentY = boardSize - 1;
            else if (currentX >= boardSize) currentX = 0;
            else if (currentX < 0) currentX = boardSize - 1;

            if (visited[currentY][currentX] == 1)
            {
                isEnd = 0;
                break;
            }
            
        }
    }    

    return result;
}