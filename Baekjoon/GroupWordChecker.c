#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isContains(char checkArr[], char word, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (checkArr[i] == word)
        {
            return true;
        }
        
    }

    return false;
}

bool checkWord(char* word, int length)
{
    char checkArr[length];
    int checkArrLength = 0;
    checkArr[checkArrLength++] = word[0];
    char pastWord = checkArr[0];

    for (int i = 1; i < length; i++)
    {
        if (word[i] == pastWord)
        {
            continue;
        }
        else if (isContains(checkArr, word[i], length))
        {
            return false;
        }
        checkArr[checkArrLength++] = word[i];
        pastWord = word[i];
    }

    return true;

}

int main(void)
{
    int answer = 0;
    int wordCount;
    scanf("%d", &wordCount);

    char* word = (char*)malloc(sizeof(char) * 101);

    for (int i = 0; i < wordCount; i++)
    {
        scanf("%s", word);
        int length = strlen(word);
        if (checkWord(word, length))
        {
            answer++;
        }
        
    }

    printf("%d\n", answer);
    
    return 0;
}
