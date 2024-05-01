#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* croatia[9] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

bool checkCroatia(char* word)
{
    for (int i = 0; i < 8; i++)
    {
        if (strcmp(croatia[i], word) == 0)
        {
            return true;
        }

    }

    return false;
}

int main(void)
{
    

    char target[101];

    scanf("%s", target);
    
    int targetLength = strlen(target);

    int answer = 0;

    for (int i = 0; i < targetLength; i++)
    {
        char twoWord[3];
        if (i + 1 < targetLength)
        {
            twoWord[0] = target[i];
            twoWord[1] = target[i + 1];
            twoWord[2] = '\0';

            if (strcmp(twoWord, "dz") == 0 && i + 2 < targetLength)
            {
                twoWord[2] = target[i + 2];
                if (strcmp(twoWord, "dz=") == 0)
                {
                    answer++;
                    i += 2;
                }
                
            }
            else if(checkCroatia(twoWord))
            {
                answer++;
                i++;
            }
            else
            {
                answer++;
            }
        }
        else if (i < targetLength)
        {
            answer++;
        }
        
    }
    
    printf("%d\n", answer);
    return 0;
}
