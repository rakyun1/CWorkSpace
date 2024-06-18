#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Move {
	int moveCount;
	char moveWay;
} MoveInfo;


int getMoveCount(struct Move **map, int boardSize, int currentY, int currentX);

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
	
	MoveInfo **map = (MoveInfo **)malloc(boardSize * sizeof(MoveInfo *));
	for (int i = 0; i < boardSize; i++) {
		map[i] = (MoveInfo *)malloc(boardSize * sizeof(MoveInfo));
	}
    
    char *input = (char*)malloc(3 * sizeof(char));
	

	for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            scanf("%s", input);
            map[i][j].moveCount = atoi(input);
            map[i][j].moveWay = input[strlen(input) - 1];
        }
	}

    goormCount = getMoveCount((MoveInfo **)map, boardSize, goormY - 1, goormX - 1);

    playerCount = getMoveCount((MoveInfo **)map, boardSize, playerY - 1, playerX - 1);

	if (goormCount > playerCount) {
        printf("goorm %d\n", goormCount);
    }
    else {
        printf("player %d\n", playerCount);
    }
	
	return 0;
}


int getMoveCount(struct Move **map, int boardSize, int currentY, int currentX)
{
    int moveCount; 
    char moveWay;
    int visited[boardSize][boardSize];

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            visited[i][j] = 0;
        }
    }

    

    int isEnd = 1;
    int result = 0;

    while (isEnd) {
        moveCount = map[currentY][currentX].moveCount;
        moveWay = map[currentY][currentX].moveWay; 

        if (moveWay == 'U')
        {
            
            while (moveCount > 0) {
                visited[currentY][currentX] = 1;

                result++;
                moveCount--;
                currentY--;

                if (currentY < 0) {
                    currentY = boardSize - 1;
                }

                if (visited[currentY][currentX] == 1) {
                    isEnd = 0;
                    break;
                }
            }
        }

        else if (moveWay == 'D')
        {
            while (moveCount > 0) {
                visited[currentY][currentX] = 1;

                currentY++;
                result++;
                moveCount--;

                if (currentY >= boardSize) {
                    currentY = 0;
                }

                if (visited[currentY][currentX] == 1) {
                    isEnd = 0;
                    break;
                }
            }
        }

        else if (moveWay == 'L')
        {
            while (moveCount > 0) {
                visited[currentY][currentX] = 1;

                currentX--;
                result++;
                moveCount--;

                if (currentX < 0) {
                    currentX = boardSize - 1;
                }

                if (visited[currentY][currentX] == 1) {
                    isEnd = 0;
                    break;
                }   
            }
        }

        else
        {
            while (moveCount > 0) {
                visited[currentY][currentX] = 1;

                currentX++;
                result++;
                moveCount--;

                if (currentX >= boardSize) {
                    currentX = 0;
                }

                if (visited[currentY][currentX] == 1) {
                    isEnd = 0;
                    break;
                }
            }
        }
    }    

    return result;
}
