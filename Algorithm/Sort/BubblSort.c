#include <stdio.h>
#include <stdbool.h>

void BubbleSort(int DataSet[], int length)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    int ishaveChange;

    for ( i = 0; i < length - 1; i++)
    {
        ishaveChange = false;
        for ( j = 0; j < length - (i + 1); j++)
        {
            if (DataSet[j] > DataSet[j + 1])
            {
                temp = DataSet[j];
                DataSet[j] = DataSet[j + 1];
                DataSet[j + 1] = temp;
                ishaveChange = true;
            }
            
        }
        
        if (!ishaveChange)
        {
            break;
        }
            
    }
    
}

int main(void)
{
    int DataSet[] = {6, 4, 2, 3, 1, 5};
    int length = sizeof(DataSet) / sizeof(DataSet[0]);
    int i = 0;
    
    BubbleSort(DataSet, length);
    
    for ( i = 0; i < length; i++)
    {
        printf("%d번째 값 :: %d\n", i, DataSet[i]);
    }
    
}