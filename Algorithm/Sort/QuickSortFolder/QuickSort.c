#include <stdio.h>

void Swap(int* A, int* B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

int Partition(int DataSet[], int Left, int Right)
{
    // 앞의 3개의 값 중에서 중간 값으로 피봇을 설정
    int First = Left;
    int Pivot = DataSet[First];

    while (Left < Right)
    {
        while (DataSet[Left] <= Pivot)
        {
            ++Left;
        }

        while (DataSet[Right] > Pivot)
        {
            --Right;
        }
        
        if (Left < Right)
        {
            Swap(&DataSet[Left], &DataSet[Right]);
        }
        
    }

    Swap(&DataSet[First], &DataSet[Right]); // 기준이 되는 피봇의 주소 값과, 왼쪽 데이터 집합의 오른쪽 끝 요소를 교환한다.
                                            // 왼쪽 데이터 집합은 모두 피봇 보다 크기가 작기에 왼쪽 데이터의 가장 오른쪽 자리가 피봇의 자리이다.

    return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
    // 재귀 함수 대신 순환문 사용
    if (Left < Right)
    {
        int index = Partition(DataSet, Left, Right);

        QuickSort(DataSet, Left, index - 1); // Partition 함수에서 Right 변수를 리턴하는데 이는 왼쪽 정렬의 오른쪽 끝 인덱스이고 Left = 0 부터 Right까지만 왼쪽 데이터 집합으로 나누어 재귀 함수를 호출한다.
        QuickSort(DataSet, index + 1, Right);
    }
    
}


int main(void)
{
    int DataSet[] = {6, 4, 2, 3, 1, 5};
    int Length = sizeof DataSet / sizeof DataSet[0];

    int i = 0;

    QuickSort(DataSet, 0, Length - 1);

    for ( i = 0; i < Length; i++)
    {
        printf("%d ", DataSet[i]);
    }
    printf("\n");
    
    return 0;
}
