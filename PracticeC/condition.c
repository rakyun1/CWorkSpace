#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int mainCondition(void) 
{
    printf("\n\n----------------------------------------------------------------------------------\n\n");
    // int age;
    // printf("나이를 입력하세요");
    // scanf("%d", &age);

    // if (age > 18)
    // {
    //     printf("삑 성인입니다.\n");
    // } else {
    //     printf("삑 학생입니다.\n");
    // }
    
    // for (int i = 0; i < 30; i++)
    // {
    //     if (i == 7)
    //     {
    //         printf("%d번 학생은 집에 가세요\n", i);
    //     } else if (i <= 10 && 1 >= 1){
    //         printf("%d번 학생은 조별 발표를 준비하세요\n", i);
    //     } else {
    //         break;
    //     }
        
    // }
    
    //가위 0 바위 1 보 2
    // srand(time(NULL));
    // int i = rand() % 3;
    // if (i == 0)
    // {
    //     printf("가위\n");
    // } else if (i == 1){
    //     printf("바위\n");
    // } else if (i == 2) {
    //     printf("보\n");
    // } else {
    //     printf("몰라연\n");
    // }
    

    // Up and Down

    srand(time(NULL));
    int num = rand() % 100 + 1;
    printf("숫자 : %d\n", num);

    int answer = 0;
    int chance = 5;
    while (1)
    {
        printf("남은 기회 %d 번\n", chance--);
        printf("숫자를 맞춰보세요 (1 ~ 100) : ");
        scanf("%d", &answer);

        if (answer > num)
        {
            printf("DOWN \n\n");
        } else if (answer < num)
        {
            printf("Up \n\n");
        } else if (answer == num)
        {
            printf("정답입니다 \n");
            break;
        } else {
            printf("알 수 없는 오류");
        }

        if (chance == 0)
        {
            printf("모든 기회를 사용하셨네요. 실패하셨습니다 \n");
            break;
        }
    }
    


    printf("\n\n----------------------------------------------------------------------------------\n\n");
    return 0;
}