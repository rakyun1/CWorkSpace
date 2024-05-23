#include "NQueens.h"

#include <stdio.h>
#include <stdlib.h>


void PrintSolution(int Columns[], int NumberOfQueens)
{
    int i = 0;
    int j = 0;

    for ( i = 0; i < NumberOfQueens; i++)
    {
        for ( j = 0; j < NumberOfQueens; j++)
        {
            if (Columns[i] == j)
            {
                printf("Q");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int IsThreatened(int Columns[], int NewRow)
{
    int CurrentRow = 0;
    int Threatened = 0;

    while (CurrentRow < NewRow)
    {
        if (Columns[NewRow] == Columns[CurrentRow] || abs(Columns[NewRow] - Columns[CurrentRow]) == abs(NewRow - CurrentRow))
        {
            Threatened = 1;
            break;
        }
        
        CurrentRow++;
    }
    
    return Threatened;
}

void FindSolutionForQueen(int Columns[], int Row, int NunberOfQueens, int* SolutionCount)
{
    if (IsThreatened(Columns, Row))
    {
        return;
    }

    if (Row == NunberOfQueens - 1)
    {
        printf("Solution #%d : \n", ++(*SolutionCount));
        PrintSolution(Columns, NunberOfQueens);
    }
    else
    {
        int i;
        for ( i = 0; i < NunberOfQueens; i++)
        {
            Columns[Row + 1] = i;
            FindSolutionForQueen(Columns, Row + 1, NunberOfQueens, SolutionCount);
        }   
    }
}