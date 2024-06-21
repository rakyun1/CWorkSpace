#include <stdio.h>
#include <stdlib.h>
int maxValue;

void bruteForce(int **block, int blockSize,  int depth);
void moveLeft(int **block, int blockSize);
void moveRight(int **block, int blockSize);
void moveOver(int **block, int blockSize);
void moveUnder(int **block, int blockSize);
void free_2d_array(int** arr, int size);
void copyArray(int **block, int **block_copy, int blockSize);

void printArray(int **block, int blockSize, int moveWay);

int main(void)
{
    int blockSize;
    scanf("%d", &blockSize);
    
    int **block = (int **)malloc(blockSize * sizeof(int*));
    for (int i = 0; i < blockSize; i++) {
		block[i] = (int *)malloc(blockSize * sizeof(int));
	}

    for (int i = 0; i < blockSize; i++) {
        for (int j = 0; j < blockSize; j++) {
            scanf("%d", &block[i][j]);
        }
    }

    
    /* for (int i = 0; i < blockSize; i++) { */
    /*     for (int j = 0; j < blockSize; j++) { */
    /*         printf("%d ", block[i][j]); */
    /*     } */
    /*     printf("\n"); */
    /* } */

    maxValue = 0;
    bruteForce(block, blockSize, 0);

    printf("answer : %d\n", maxValue);
    
    free_2d_array(block, blockSize);
   
    return 0;
}

void bruteForce(int **block, int blockSize, int depth){
    if (depth == 5) return;
    
    int **block_copy = (int **)malloc(blockSize * sizeof(int*));
    for (int i = 0; i < blockSize; i++) {
        block_copy[i] = (int *)malloc(blockSize * sizeof(int));
        for (int j = 0; j < blockSize; j++) {
            block_copy[i][j] = block[i][j];
        }
    }

    moveLeft(block_copy, blockSize);
    bruteForce(block_copy, blockSize, depth + 1);
    copyArray(block, block_copy, blockSize);

    moveRight(block_copy, blockSize);
    bruteForce(block_copy, blockSize, depth + 1);
    copyArray(block, block_copy, blockSize);

    moveOver(block_copy, blockSize);
    bruteForce(block_copy, blockSize, depth + 1);
    copyArray(block, block_copy, blockSize);

    moveUnder(block_copy, blockSize);
    bruteForce(block_copy, blockSize, depth + 1);
    copyArray(block, block_copy, blockSize);

    free_2d_array(block_copy, blockSize);
}

void moveLeft(int **block, int blockSize){
    for (int i = 0; i < blockSize; i++) {
        int lowIndex = 0;
        while (lowIndex < blockSize - 1) {
            if (block[i][lowIndex] == block[i][lowIndex + 1]){
                    block[i][lowIndex] = block[i][lowIndex] + block[i][lowIndex + 1];
                    block[i][lowIndex + 1] = 0;
                    lowIndex++;
            }

            lowIndex++;
        }
        
        lowIndex = 0;
        while (lowIndex < blockSize) {
            if (block[i][lowIndex] == 0) {
                
                int findIndex = lowIndex + 1;
                while (findIndex < blockSize) {
                    if (block[i][findIndex] != 0){
                        block[i][lowIndex] = block[i][findIndex];
                        block[i][findIndex] = 0;

                        break;
                    }     

                    findIndex++;
                }
            }

            lowIndex++;
        }
    }

    printArray(block, blockSize, 1);
}

// moveRight 동작이 이상함 디버깅 해야 할듯
void moveRight(int **block, int blockSize){
    for (int i = 0; i < blockSize; i++) {
        int lowIndex = blockSize - 1;
        while (lowIndex > 0) {
            if (block[i][lowIndex] == block[i][lowIndex - 1]){
                    block[i][lowIndex] = block[i][lowIndex] + block[i][lowIndex - 1];
                    block[i][lowIndex - 1] = 0;
                    lowIndex--;
            }

            lowIndex--;
        }
        
        lowIndex = blockSize - 1;
        while (lowIndex > 0) {
            if (block[i][lowIndex] == 0) {
                int findIndex = lowIndex - 1;
                
                while (findIndex < blockSize) {
                    if (block[i][findIndex] != 0){
                        block[i][lowIndex] = block[i][findIndex];
                        block[i][findIndex] = 0;

                        break;
                    }     

                    findIndex--;
                }
            }

            lowIndex--;
        }
    }

    printArray(block, blockSize, 2);
}

void moveOver(int **block, int blockSize){

}

void moveUnder(int **block, int blockSize){

}


void copyArray(int **block, int **block_copy, int blockSize){
    for (int i = 0; i < blockSize; i++) {
        for (int j = 0; j < blockSize; j++) {
            block_copy[i][j] = block[i][j];
        }
    }
}

void free_2d_array(int** arr, int size) {
    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);
}

void printArray(int **block, int blockSize, int moveWay){
    if (moveWay == 1) printf("================왼쪽으로 이동===============\n");
    if (moveWay == 2) printf("================오른쪽으로 이동===============\n");
    if (moveWay == 3) printf("================위쪽으로 이동===============\n");
    if (moveWay == 4) printf("================아래쪽으로 이동===============\n");
    

    for (int i = 0; i < blockSize; i++) {
        for (int j = 0; j < blockSize; j++) {
            printf("%d ", block[i][j]);
        }
        printf("\n");
    }
}

