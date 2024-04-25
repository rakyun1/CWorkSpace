#include <stdlib.h>
#include <stdio.h>

void slice(int* source, int start, int end, int* dest)
{
    int j = 0;
    for (int i = start; i <= end; i++)
    {
        dest[j++] = source[i];
    }
    
}

int compare(const void* a, const void* b)
{    
    return (*(int*)a - *(int*)b);
}

int main(void)
{
    int arr[] = {1, 5, 2, 6, 3, 7, 4};
    int commands[3][3] = {
        {2, 5, 3}, 
        {4, 4, 1}, 
        {1, 7, 3}
    };
    int answer[] = {0, 0, 0};
    
    for (int i = 0; i < sizeof commands / sizeof commands[0]; i++)
    {
        int start = commands[i][0] - 1;
        int end = commands[i][1] - 1;
        int number = commands[i][2] - 1;
        int length = end - start + 1;

        int* slicedArr = (int*)malloc(sizeof(int) * length);

        slice(arr, start, end, slicedArr);

        qsort(slicedArr, length, sizeof(int), compare);

        printf("\n============정렬 된 배열 =============\n");
        for (int i = 0; i <= end - start; i++)
        {
            printf("%d\n", slicedArr[i]);
        }
        printf("\n\n");

        answer[i] = slicedArr[number];

        free(slicedArr);
    }
    

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", answer[i]);
    }
    
    return 0;
}
