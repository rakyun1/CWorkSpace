#include <stdio.h>
#define MAX 10000


int main_file(void)
{
    // fputs, fgets
    char line[MAX];
    // FILE * file = fopen("c:\\test1.txt", "wb"); 
    // if (file == NULL)
    // {
    //     printf("파일 열기 실패\n");
    //     return 1;
    // }

    // fputs("fputs를 이용해서 글을 적어볼게요\n", file);
    // fputs("잘 적히는지 확인해주세요\n", file);

    // // 파일을 열고 닫을 때 파일에 적힌 데이터가 저장되는데 fclose();를 안하고
    // // 프로그램에 문제가 생기면 데이터가 저장되어 있지 않으므로 데이터가 손실 될 수 있다.
    // fclose(file);


    // 파일 읽기
    // FILE * file = fopen("c:\\test1.txt", "rb");

    // if (file == NULL)
    // {
    //     printf("파일 열기 실패\n");
    //     return 1;
    // }
    // while (fgets(line, MAX, file))
    // {
    //     printf("%s", line);
    // }

    // 파일 경로와 이름 설정
    // FILE *file = fopen("/Users/rock/Desktop/newFile.txt", "rb");
    // if (file == NULL) {
    //     printf("파일을 생성할 수 없습니다.\n");
    //     return 1;
    // }
    // // fputs("C언어를 사용해서 만든 파일\n", file);
    // // fputs("잘 나오는지 테스트\n", file);
    
    // while (fgets(line, MAX, file))
    // {
    //     printf("%s", line);
    // }

    int num[6] = {0,0,0,0,0,0};
    int bonus = 0;
    char str1[MAX];
    char str2[MAX];
    // FILE * file = fopen("/Users/rock/Desktop/lottoFile.txt", "wb");
    // if (file == NULL) {
    //     printf("파일을 생성할 수 없습니다.\n");
    //     return 1;
    // }

    // fprintf(file, "%s %d %d %d %d %d %d\n", "추첨번호 ", 1,2,3,4,5,6);
    // fprintf(file, "%s %d\n", "보너스 번호 ", 7);
    
    FILE * file = fopen("/Users/rock/Desktop/lottoFile.txt", "rb");

    if (file == NULL) {
        printf("파일을 생성할 수 없습니다.\n");
        return 1;
    }
    fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
    printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1],num[2], num[3], num[4], num[5]);

    fscanf(file, "%s %d", str2, &bonus);
    printf("%s %d\n", str2, bonus);

    // 파일 닫기
    fclose(file);
    return 0;
}