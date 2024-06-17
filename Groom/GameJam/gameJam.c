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
    groomY, groomX, 
    playerY, playerX,
    groomCount, playerCount;
	
	scanf("%d", &boardSize);
	scanf("%d", &groomY);
	scanf("%d", &groomX);
	scanf("%d", &playerY);
	scanf("%d", &playerX);
	
	MoveInfo map[boardSize][boardSize];
	char *input = (char*)malloc(3 * sizeof(char));
	

	for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            scanf("%s", input);
            MoveInfo temp;
            temp.moveCount = atoi(input);
            temp.moveWay = input[strlen(input) - 1];
            map[i][j] = temp;
        }
	}

    groomCount = getMoveCount(map, boardSize, groomY, groomX);

    playerCount = getMoveCount(map, boardSize, playerY, playerX);

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            printf("%d, %c ", map[i][j].moveCount, map[i][j].moveWay );
        }
        printf("\n");
	}
	
	scanf("%s",input);
	return 0;
}


int getMoveCount(MoveInfo **map, int boardSize, int currentY, int currentX)
{
    int moveCount, moveWay;
    int visited[boardSize][boardSize];
    memset(visited, 0, sizeof(visited));

    int isEnd = 1;
    int result = 0;

    while (isEnd) {
        moveCount = map[currentY][currentX].moveCount;
        moveWay = map[currentY][currentX].moveWay; 

        if (moveWay == 'U')
        {
            
            while (moveCount > 0) {
                if (currentY < 0) {
                    currentY = boardSize - 1;
                }

                if (visited[currentY][currentX] == 1) {
                    isEnd = -1;
                    break;
                }
                else 
                {
                    result++;
                    moveCount--;
                    visited[currentY][currentX] = 1;
                    currentY--;
                }
            }
        }

        else if (moveWay == 'D')
        {
            while (moveCount > 0) {
                if (currentY >= boardSize) {
                    currentY = 0;
                }

                if (visited[currentY][currentX] == 1) {
                    isEnd = -1;
                    break;
                }
                else 
                {
                    result++;
                    moveCount--;
                    visited[currentY][currentX] = 1;
                    currentY++;
                }
            }
        }

        else if (moveWay == 'L')
        {
            while (moveCount > 0) {
                if (currentX < 0) {
                    currentX = boardSize - 1;
                }

                if (visited[currentY][currentX] == 1) {
                    isEnd = -1;
                    break;
                }
                else 
                {
                    result++;
                    moveCount--;
                    visited[currentY][currentX] = 1;
                    currentX--;
                }
            }
        }

        else
        {
            while (moveCount > 0) {
                if (currentX >= boardSize) {
                    currentX = 0;
                }

                if (visited[currentY][currentX] == 1) {
                    isEnd = -1;
                    break;
                }
                else 
                {
                    result++;
                    moveCount--;
                    visited[currentY][currentX] = 1;
                    currentX++;
                }
            }
        }
    }    

    return result;
}
