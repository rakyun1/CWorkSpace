#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int mainArrayProject(void)
{
    srand(time(NULL));
    printf("\n\n ==== 아빠는 대머리 게임 ==== \n\n");
    int answer;
    int treatment = rand() % 4;

    // 전 판과 현재 판의 보여주는 병의 개수를 다르게 하여 정답률을 향상 시킴
    int cntShowBottle = 0;
    int prevCntShowBottle = 0;
    
    for (int i = 1; i <= 3; i++)
    {
        int bottle[4] = {0, 0, 0, 0};
        
        while (cntShowBottle == prevCntShowBottle)
        {
            cntShowBottle = rand() % 2 + 2;
        }
        prevCntShowBottle = cntShowBottle;
        int isIncluded = 0;
        printf(" > %d 번째 시도 : ", i);

        for (int j = 0; j < cntShowBottle; j++)
        {
            int randBottle = rand() % 4;
            if (bottle[randBottle] == 0)
            {
                bottle[randBottle] = 1;
                if (randBottle == treatment)
                {
                    isIncluded = 1;
                }
                
            } else {
                j--;
            }
        }

        for (int k = 0; k < 4; k++)
        {
            if (bottle[k] == 1)
            {
            printf("%d ", k + 1);
            }
        }
        printf("물약을 머리에 바릅니다\n\n");
        if (isIncluded == 1)
        {
            printf(" >> 성공 ! 머리가 났어요 ! \n");
        }
        else
        {
            printf(" >> 실패 ! 머리가 나지 않았어요.. ㅠㅜ\n");
        }
        
        printf("\n 계속 하려면 아무키나 누르세요 ...\n ");
        getchar();
    }
    
    printf("\n\n 발모제는 몇 번일까요 ? ");
    scanf("%d", &answer);
    if (answer == treatment + 1)
    {
        printf("정답입니다\n");
    }
    else
    {
        printf("땡 틀렸어요 정답은 %d입니다\n", treatment + 1);
    }
    
    return 0;
}