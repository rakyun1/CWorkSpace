#include <stdio.h>
#include <stdlib.h>



int checkWord(char* word)
{
    for (int i = 0; i < sizeof word / sizeof word[0]; i++)
    {
        printf("%c ", word[i]);
    }
    printf("\n");



    return 0;

}

int main(void)
{
    int answer = 0;
    int wordCount;
    scanf("%d", &wordCount);

    char* word = (char*)malloc(sizeof(char) * 101);

    for (size_t i = 0; i < wordCount; i++)
    {
        scanf("%s", word);
        if (checkWord(word))
        {
            answer++;
        }
        
    }
    
    return 0;
}
