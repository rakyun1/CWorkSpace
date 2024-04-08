#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct 
{
    char * exerciseName;
    int setCount;
    int maxVolume;
} EXERCISE_INFO;

void printExerciseInfo(int infoIndex);
int checkNumber(int exerciseArea);
char * exerciseKind[] = {"하체", "등", "가슴", "팔", "어깨"};
EXERCISE_INFO infoArray[100];

int main_exercise(void)
{
    char exerciseKindName[1000];
    int maxVolume;
    int setCount;
    int exerciseArea;
    
    int infoIndex = 0;
    printf("======= 오늘 진행한 운동 부위는 ? ==========\n\n");
    printf("1. 하체 \n2. 등\n3. 가슴\n4. 팔\n5. 어깨\n");
    printf("숫자 입력 : ");
    scanf("%d", &exerciseArea);

    if(checkNumber(exerciseArea))
    {
        printf("\n\n오늘은 %s 운동을 진행하셨군요 ! \n", exerciseKind[exerciseArea - 1]);
        while (1)
        {
            int check;
            printf("운동 종목의 이름과 세트 수 및 최고 중량을 입력해주세요\n\n");
            printf("운동 종목 이름: ");
            getchar();
            fgets(exerciseKindName, sizeof(exerciseKindName), stdin);
            char *newline = strchr(exerciseKindName, '\n'); // inputString은 fgets()로 입력 받은 문자열
            if (newline) {
                *newline = '\0'; // 개행 문자를 널 문자로 대체
            }
            printf("\n세트 수 : ");
            scanf("%d", &setCount);
            printf("\n최고 중량 : ");
            scanf("%d", &maxVolume);
            printf("\n%s을(를) %d 세트만큼 진행하였고, 최고 중량은 %dkg이 맞나요 ? \n",exerciseKindName, setCount, maxVolume);
            printf("\n네 : 1 || 아니요 : 2\n");
            scanf("%d", &check);
            if (check == 1)
            {
                EXERCISE_INFO info = {exerciseKindName, setCount, maxVolume};
                infoArray[infoIndex] = info;
                infoIndex++;
                printf("\n더 작성하시겠습니까 ? \n");
                printf("\n네 : 1 || 아니요 : 2\n");
                scanf("%d", &check);
                if (check == 1)
                {
                    continue;
                }
                else
                {
                    printExerciseInfo(infoIndex);
                    printf("\n=====입력을 종료합니다.======\n");
                    break;
                }
            }
            else
            { 
                printf("\n다시 입력을 받습니다 \n");
                continue;
            }
        }
        
        
        
    }
    else
    {
        printf("잘못된 입력이 들어왔습니다. 프로그램을 종료합니다.\n");
    }
    



    return 0;
}

int checkNumber(int exerciseArea)
{
    bool isContains = false;
    for (int i = 1; i < 6; i++)
    {
        if (exerciseArea == i)
        {
            isContains = true;
        }
        
    }
    return isContains;
}

void printExerciseInfo(int infoIndex)
{

    printf("\n\n ============== 입력 내용을 확인합니다. ============\n\n");
    for (int i = 0; i < infoIndex; i++)
    {
        EXERCISE_INFO e = infoArray[i];
        printf("\n\n운동 종목 이름  : %s\n", e.exerciseName);
        printf("세트 수  : %d\n", e.setCount);
        printf("최고 중량  : %d\n", e.maxVolume);
    }
    
}