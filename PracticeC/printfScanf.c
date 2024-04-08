#include <stdio.h>

int mainPrintfScanf(void)
{
    printf("%s\n", "----------------------------------------------------------------------------------");
    printf("\n");
    // // 실수형 변수 예제
    // double f = 45.54242;
    // printf("나의 나이는 : ");
    // printf("%.4lf\n", f);

    // const int YEAR = 2000;
    // printf("태어난 연도는 : %d\n", YEAR);

    // int add = 3 + 7;
    // printf("%d\n", add);
    // printf("%d + %d = %d\n", 3, 7, 3 + 7);
    
    // int input;
    // printf("값을 입력하세요 : ");
    // scanf("%d", &input);
    // printf("입력값 : %d\n", input);
    
    // int one, two, three;
    // printf("3개의 정수를 입력하세요 : ");
    // scanf("%d %d %d", &one, &two, &three);
    // printf("첫 번째 : %d\n", one);
    // printf("두 번째 : %d\n", two);
    // printf("세 번째 : %d\n", three);

    // char c = 'A';
    // printf("%c\n", c);

    // char str[256];
    // printf("문자를 입력하세요 : ");
    // scanf(" %[^\n]", str);
    // printf("%s\n",str);

    // 프로젝트
    // 경찰관이 범죄자의 정보를 입수 (조서 작성)
    // 이름, 나이, 몸무게, 키, 범죄명을 입력 받아야 함
    char name[256];
    printf("이름이 뭡니까 ? ");
    scanf("%s", name);

    int age;
    printf("나이가 몇입니까 ? ");
    scanf("%d", &age);
    
    float weight;
    printf("몸무게가 몇입니까 ? ");
    scanf("%f", &weight);
    
    double height;
    printf("키가 몇입니까 ? ");
    scanf("%lf", &height);
    
    char crime[2];
    int size = sizeof(crime);
    printf("범죄명이 뭡니까 ? ");
    scanf("%s", crime);

    printf("\n\n-----범죄자 정보 -----\n\n");
    printf("이름 : %s\n", name);
    printf("나이 : %d\n", age);
    printf("몸무게 : %.2f\n", weight);
    printf("키 : %.2lf\n", height);
    printf("범죄명 : %s\n", crime);












    printf("\n");
    printf("%s\n", "----------------------------------------------------------------------------------");
    return 0;
}