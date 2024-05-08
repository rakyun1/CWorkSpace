#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int findMostAppearValue(int* arr, int length)
{
    int appearCount[length];
    int max[2];
    int isChanged = 0;

    memset(max, 0, sizeof(max));

    memset(appearCount, 0, sizeof(appearCount));
    appearCount[0] = 1;

    for (int i = 1; i < length; i++)
    {
        if (arr[i - 1] == arr[i])
        {
            appearCount[i] = appearCount[i - 1] + 1;
        }
        else
        {
            appearCount[i] = 1;
        }
        
    }

    // printf("\n\n 현재 appearCount \n\n");
    // for (int i = 0; i < length; i++)
    // {
    //     printf("%d ", appearCount[i]);
    // }
    // printf("\n");

    for (int i = 0; i < length; i++)
    {
        if (max[1] < appearCount[i])
        {
            max[1] = appearCount[i];
            max[0] = i;
            isChanged = 0;
        }
        else if (max[1] == appearCount[i] && isChanged == 0)
        {
            max[1] = appearCount[i];
            max[0] = i;
            isChanged = 1;
        }
        
        // printf("\n\n");
        // printf("max[0] :: %d \n", max[0]);
        // printf("max[1] :: %d \n", max[1]);
    }
    
    

    return arr[max[0]];
}

int abs(int x) {
    return (x < 0) ? -x : x;
}

int main(void)
{
    int numberCount, i, j;
    int total = 0;

    scanf("%d", &numberCount);

    int numbers[numberCount];

    for ( i = 0; i < numberCount; i++)
    {
        int input;
        scanf("%d", &input);

        numbers[i] = input;
        total += input;
    }

    qsort(numbers, numberCount, sizeof(int), compare);
    
    int firstAnswer = round((double)total / numberCount);

    // printf("\n\n");
    // for ( i = 0; i < numberCount; i++)
    // {
    //     printf("%d\n", numbers[i]);
    // }

    int mostAppearValue = findMostAppearValue(numbers, numberCount);

    printf("\n%d\n", firstAnswer);
    printf("%d\n", numbers[numberCount / 2]);
    printf("%d\n", mostAppearValue);
    printf("%d\n", abs(numbers[numberCount - 1] - numbers[0]));


    return 0;
}   