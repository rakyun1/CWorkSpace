#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b)
{
    int num1 = *((int*) a);
    int num2 = *((int*) b);

    return num1 - num2;
}

int solution(int nums[], int Length)
{
    int count = 1;
    qsort(nums, Length, sizeof(int), compare);

    for (int i = 1; i < Length; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            count++;
        }
        
    }

    if (count > Length / 2)
    {
        return Length / 2;
    }
    

    return count;
}

int main(int argc, char const *argv[])
{
    // int nums[] = {3,1,2,3};
    // int nums[] = {3,3,3,2,2,4};
    // 223334
    int nums[] = {3,3,3,2,2,2};

    int Length = sizeof nums / sizeof nums[0];

    int answer = solution(nums, Length);

    printf("%d\n", answer);
    return 0;
}
