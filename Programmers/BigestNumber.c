#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    int num1 = *((int *)a);
    int num2 = *((int *)b);

    // 두 숫자의 일의 자리를 비교하여 내림차순으로 정렬
    return (num2 % 10) - (num1 % 10);
}

char* solution(int numbers[], size_t numbers_len) 
{
    qsort(numbers, numbers_len, sizeof(int), compare);

    char* answer = (char*)malloc(1000000000);

    for (int i = 0; i < numbers_len; i++) {
        char temp[20]; // 숫자를 저장할 임시 문자열
        sprintf(temp, "%d", numbers[i]); // 숫자를 문자열로 변환하여 temp에 저장
        strcat(answer, temp); // temp에 있는 문자열을 answer에 추가
    }
    
    return answer;
}

int main(void)
{   
    // int numbers[] = {6, 10, 2};
    int numbers[] = {3, 30, 34, 5, 9};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    char* answer = solution(numbers, length);
    
    printf("%s\n", answer);
    return 0;
}
