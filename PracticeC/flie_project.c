#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int main_file(void)
{
    char line[MAX];
    char contents[MAX]; 
    char password[20];
    char c;

    printf(" '비밀일기'에 오신 것을 환영합니다\n");
    printf("비밀번호를 입력하세요 : ");
    
    int i = 0;
    while (1)
    {
        // getchar()와 getch()의 차이는 ? 
        // getchar()는 엔터를 입력해야 터미널에 입력 된 값이 프로그램으로 이동
        // getch()는 엔터를 입력하지 않아도 터미널에 입력 되는 값들이 프로그램으로 이동
        c = _getch();
        if (c == 13)
        {
            password[i] = '\0';
            break;
        }
        else
        {
            printf("*");
            password[i] = c;
        }
        i++;
        
    }
    printf("\n\n ====== 비밀번호 확인 중... ======\n\n");
    if (strcmp(password, "fkrdbs") == 0)
    {
        printf("=== 비밀번호 확인 완료 ===\n\n");
        char *flieName = "/Users/rock/Desktop/secretDiary.txt";
        FILE * file = fopen(flieName, "a+b");
        if (file == NULL)
        {
            printf("파일 열기 실패\n");
            return 1;
        }

        while(fgets(line, MAX, file) != NULL)
        {
            printf("%s\n", line);
        }

        printf("\n\n 내용을 계속 작성하세요 ! 종료하시려면 EXIT를 입력하세요 \n\n");
        while(1)
        {
            scanf("%[^\n]", contents);  // 줄바꿈(\n)이 나오기 전까지 읽음
            getchar();

            if (strcmp(contents, "EXIT") == 0)
            {
                printf("비밀일기 입력을 종료합니다.\n\n");
            }
            fputs(contents, file);
            fputs("\n", file);
            
        }
        fclose(file);
    }
    else
    {
        printf("=== 비밀번호가 틀렸어요 === \n\n");
    }
    return 0;
}
