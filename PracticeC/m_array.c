#include <stdio.h>

int main_m_array(void)
{
    int arr[2][5] = {{1,2,3,4,5}, {6,7,8,9,10}};

    int xSize = sizeof(arr[0]) / 4;
    int ySize = (sizeof(arr) / 4) / xSize;


    for (int i = 0; i < ySize; i++)
    {
        for (int j = 0; j < xSize; j++)
        {
            printf("[%d]", arr[i][j]);
        }
        printf("\n");
    }
    
    printf("%d\n", xSize);
    printf("%d\n", ySize);
    


    return 0;
}