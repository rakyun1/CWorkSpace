#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    int num1 = *((int *)a);
    int num2 = *((int *)b);

    return num2 - num1;
}

int solution(int citations[], int Length)
{
    qsort(citations, Length, sizeof(int), compare);

    for (int i = 0; i < Length; i++)
    {
        int count = i + 1;
        int left = Length - count;
        if (count >= citations[i] && left <= citations[i])
        {
            return citations[i];
        }
        
    }
    
    return -1;
}

int main(void)
{
    // int citations[] = {3, 0, 6, 1, 5};
    // int citations[] = {0, 0, 0, 1, 0};

    int citations[] = {14, 12, 9, 3, 2, 1};

    int Length = sizeof citations / sizeof citations[0];

    int answer = solution(citations, Length);

    printf("%d\n", answer);
    return 0;
}
