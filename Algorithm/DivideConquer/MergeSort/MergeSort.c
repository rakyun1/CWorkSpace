#include <stdio.h>
#include <stdlib.h>

void MergeSort(int DataSet[], int StartIndex, int EndIndex);
void Merge(int DataSet[], int StartIndex, int MiddleIndex, int EndIndex);

void MergeSort(int DataSet[], int StartIndex, int EndIndex)
{
    int MiddleIndex;

    if (EndIndex - StartIndex < 1)
    {
        return;
    }

    MiddleIndex = (StartIndex + EndIndex) / 2;
    
    /* 
        각 부분 집합에 대해 새로 배열을 만들지 않고 원래의 배열을 가르키는 인덱스만 변화시켜
        재귀 호출을 하고 있다.
    */
    MergeSort(DataSet, StartIndex, MiddleIndex);
    MergeSort(DataSet, MiddleIndex + 1, EndIndex);

    Merge(DataSet, StartIndex, MiddleIndex, EndIndex);
}

void Merge(int DataSet[], int StartIndex, int MiddleIndex, int EndIndex)
{
    int i;
    int LeftIndex = StartIndex;
    int RightIndex = MiddleIndex + 1;
    int DestIndex = 0;

    int* Destination = (int*)malloc(sizeof(int) * (EndIndex - StartIndex + 1));

    /* 
        왼쪽 데이터 집합을 가르키는 포인터 LeftIndex와
        오른쪽 데이터 집합을 가르키는 포인터 RightIndex가
        각자의 데이터 집합의 끝에 도달했다면 whlie문을 종료한다.
        데이터 집합의 끝에 도달했다는 의미는 각 부분 집합에 대해 정렬이 끝났다는 의미이다. 
    */
    while (LeftIndex <= MiddleIndex && RightIndex <= EndIndex)
    {
        /* 왼쪽 데이터 집합의 값이 작다면 병합 배열에 왼쪽 데이터 집합의 값을 넣고 반대라면 오른쪽 데이터 집합의 값을 넣는다. */
        if (DataSet[LeftIndex] < DataSet[RightIndex])
        {
            Destination[DestIndex] = DataSet[LeftIndex];
            LeftIndex++;
        }
        else
        {
            Destination[DestIndex] = DataSet[RightIndex];
            RightIndex++;
        }

        DestIndex++;
    }
    
    /* 왼쪽 데이터 집합이나 오른쪽 데이터 집합 중에 한 집합은 하나의 원소가 남아있을 텐데 그 남은 원소를 병합 배열에 넣는 과정이다. */
    while (LeftIndex <= MiddleIndex)
    {
        Destination[DestIndex++] = DataSet[LeftIndex++];
    }
    while (RightIndex <= EndIndex)
    {
        Destination[DestIndex++] = DataSet[RightIndex++];
    }

    DestIndex = 0;
    for ( i = StartIndex; i <= EndIndex; i++)
    {
        DataSet[i] = Destination[DestIndex++];
    }
    
    free(Destination);
}

int main(void)
{
    int DataSet[] = {334, 6, 4, 2, 3, 1, 5, 117, 12, 34};
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    printf("\n\n================== 정렬 전 =====================\n\n");
    for ( i = 0; i < Length; i++)
    {
        printf("%d ", DataSet[i]);
    }
    printf("\n");

    MergeSort(DataSet, 0, Length - 1);

    printf("\n\n================== 정렬 후 =====================\n\n");
    for ( i = 0; i < Length; i++)
    {
        printf("%d ", DataSet[i]);
    }
    printf("\n");
     

    return 0;
}
