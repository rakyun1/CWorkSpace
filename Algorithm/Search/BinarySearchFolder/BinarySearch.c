#include <stdio.h>
#include <stdlib.h>
#include "Score.h"

Score* BinarySearch(Score ScoreList[], int size, double Target)
{
    int left, right, mid;

    left = 0;
    right = size - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (ScoreList[mid].score == Target)
        {
            return &(ScoreList[mid]);
        }
        else if (ScoreList[mid].score < Target)
        {
            left = mid + 1 ;
        }
        else
        {
            right = mid - 1;
        }
    }
    
    return NULL;
}

int CompareScore(const void* _elem1, const void* _elem2)
{
    Score* elem1 = (Score*)_elem1;
    Score* elem2 = (Score*)_elem2;
    if (elem1->score > elem2->score)
    {
        return 1;
    }
    else if (elem1->score < elem2->score)
    {
        return -1;
    }
    else
        return 0;
}

int main(void)
{
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;
    Score* found = NULL;
    qsort((void*)DataSet, Length, sizeof(Score), CompareScore);

    found = BinarySearch(DataSet, Length, 671.78);

    if (found == NULL)
    {
        printf("해당 점수의 학생을 찾을 수 없습니다.");
    }
    else
    {
        printf("found :: %d %f \n", found->number, found->score);   
    }

    return 0;
}
