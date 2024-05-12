#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compareChars(const void* a, const void* b) {
    char arg1 = *(const char*)a;
    char arg2 = *(const char*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main(void)
{
    int wordCount, i, j;

    char* fristWord = (char*)malloc(11);

    scanf("%d", &wordCount);

    scanf("%s", fristWord);
    int wordLength = strlen(fristWord);
    qsort(fristWord, wordLength, sizeof(char), compareChars);

    char* words[wordCount - 1];

    for (int i = 0; i < wordCount - 1; i++)
    {
        words[i] = (char*)malloc(11);
        scanf("%s", words[i]);
        wordLength = strlen(words[i]);

        qsort(words[i], wordLength, sizeof(char), compareChars);
    }

    int answer = 0;

    for (i = 0; i < wordCount - 1; i++)
    {
        if (strcmp(fristWord, words[i]) == 0)
        {
            answer++;
        }
        
    }

    char* temp = (char*)malloc(wordLength + 2);
    wordLength = strlen(fristWord);

    for (i = 0; i < wordLength; i++)
    {
        strcpy(temp, fristWord);
        temp[wordLength] = fristWord[i];
        temp[wordLength + 1] = '\0';

        qsort(temp, wordLength + 1, sizeof(char), compareChars);

        for (int j = 0; j < wordCount - 1; j++)
        {
            if (strcmp(temp, words[j]) == 0)
            {
                answer++;
            }
            
        }
    }
    
    for (i = 0; i < wordLength; i++)
    {
        strcpy(temp, fristWord);
        for (int k = i; k < wordLength; k++)
        {
            temp[k] = temp[k + 1];
        }

        // printf("\ntemp :: %s\n", temp);
        for (int j = 0; j < wordCount - 1; j++)
        {
            if (strcmp(temp, words[j]) == 0)
            {
                answer++;
            }
            
        }
    }



    printf("%d\n", answer);
    // for (int i = 0; i < wordCount - 1; i++)
    // {
    //     printf("%s ", words[i]);
    // }
    // printf("\n");
    



    return 0;
}
