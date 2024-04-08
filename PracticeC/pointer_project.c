#define _CRT_SECURE_NO_WARNINGS // visual studio scanf 오류 무시


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int level;
int arrayFish[6];
int * cursor;

void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int main_pointer_project(void)
{
    long startTime = 0;
    long totalElapsedTime = 0;
    long prevElapsedTime = 0;

    int num;
    initData();

    cursor = arrayFish;

    startTime = clock();
    // printf("%ld 시작시간 \n" , startTime);
    while (1)
    {
        printfFishes();
        printf("몇 번 어항에 물을 주시겠어요 ?");
        scanf("%d", &num);
		system("cls");

        if (num < 1 || num > 6)
        {
            printf("\n 입력값이 잘못되었습니다.\n");
            continue;
        }

        // printf("%ld\n", CLOCKS_PER_SEC);
        totalElapsedTime = (clock() - startTime) /  1000;
        printf("총 경과 시간 : %ld 초 \n", totalElapsedTime);

        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);
        
        decreaseWater(prevElapsedTime);

        if (cursor[num - 1] <= 0)
        {
            printf("%d 번 물고기는 이미 죽었습니다 ... 물을 주지 않습니다 \n", num);
        } else if (cursor[num - 1] + 1 <= 100)
        {
            printf("%d 번 어항에 물을 줍니다 \n\n", num);
            cursor[num - 1] += 1;
        }
        
        if (totalElapsedTime / 20 > level - 1)
        {
            level++;
            printf(" *** 축 레벨업 ! 기존 %d 레벨에서 %d 레벨로 업그레이드 ***\n\n", level - 1, level);
            if (level == 5)
            {
                printf("\n\n 축하합니다. 최고 레벨을 달성하셨습니다. 게임을 종료합니다. \n\n");
                exit(0);
            }
        }
        
        if (checkFishAlive() == 0)
        {
            printf("물고기가 모두 죽었습니다. \n");
            exit(0);
        } else {
            printf("물고기가 아직 살아 있어요 \n");
        }

        prevElapsedTime = totalElapsedTime;
        

    }
    

    return 0;
}

void initData()
{
    level = 1;
    for (int i = 0; i < 6; i++)
    {
        arrayFish[i] = 100;
    }
    
}


void printfFishes()
{
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번 \n", 1, 2, 3, 4, 5, 6);
    for (int i = 0; i < 6; i++)
    {
        printf(" %4d ", arrayFish[i]);
    }
    printf("\n\n");
}

void decreaseWater(long elapsedTime)
{
    for (int i = 0; i < 6; i++)
    {
        arrayFish[i] -= (level * 2 * (int)elapsedTime);
        if (arrayFish[i] < 0)
        {
            arrayFish[i] = 0;
        }
        
    }
    
}

int checkFishAlive()
{
    for (int i = 0; i < 6; i++)
    {
        if (arrayFish[i] > 0)
        {
            return 1;
        }
    }
    return 0;
}