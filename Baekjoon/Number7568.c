#include <stdio.h>
#include <string.h>

typedef struct personInfo
{
    int weight;
    int height;
} personInfo;

int main(void)
{
    
    int personCount, i, j;

    scanf("%d", &personCount);

    personInfo persons[personCount];
    int answer[personCount];

    memset(persons, 0, sizeof(personInfo) * personCount);
    memset(answer, 0, sizeof(int) * personCount);

    for ( i = 0; i < personCount; i++)
    {
        int weight = 0;
        int height = 0;

        scanf("%d", &weight);
        scanf("%d", &height);

        persons[i] = (personInfo){weight, height};
    }

    for ( i = 0; i < personCount; i++)
    {
        int currentW = persons[i].weight;
        int currentH = persons[i].height;

        for ( j = 0; j < personCount; j++)
        {
            if (i != j)
            {
                int nextW = persons[j].weight;
                int nextH = persons[j].height;

                if (currentW < nextW && currentH < nextH)
                {
                    answer[i]++;
                }
                
            }
            
        }
        
    }

    for ( i = 0; i < personCount; i++)
    {
        printf("%d ", answer[i] + 1);
    }
    printf("\n");

    return 0;
}


