#include "Makingchange.h"
#include <stdio.h>

void GetChange(int Price, int Pay, int CoinUnits[], int Change[], int Size)
{
    int i = 0;
    int ChangeAmount = Pay - Price;

    /* qsort() 함수로 CoinUnit[]에 있는 값들을 내림차순 정렬 후에 가장 큰 코인부터 사용함 */
    for ( i = 0; i < Size; i++)
    {
        Change[i] = CountCoins(ChangeAmount, CoinUnits[i]);

        ChangeAmount = ChangeAmount - (CoinUnits[i] * Change[i]);
    }
    
}

int CountCoins(int Amount, int CoinUnit)
{
    int CoinCount = 0;

    while (Amount >= CoinUnit)
    {
        CoinCount++;
        Amount = Amount - CoinUnit;
    }
    
    return CoinCount;
}

void PrintChange(int CoinUnits[], int Change[], int Size)
{
    int i = 0;
    for ( i = 0; i < Size; i++)
    {
        printf("%8d원 : %d개\n", CoinUnits[i], Change[i]);
    }
    
}