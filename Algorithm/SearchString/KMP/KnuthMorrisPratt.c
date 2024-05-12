#include "KnuthMorrisPratt.h"
#include <stdlib.h>

void Preprocess(char* Pattern, int PatternSize, int* Border)
{
    int i = 0;
    int j = -1;

    /*
        경계를 나타내는 Border 변수의 0번째는 -1로 한다.
        그 이유는 최대 경계를 기록해야 하는데 0번째는 접두부가 아예 존재하지 않으므로 -1을 준다.
        접두부가 존재하나 경계가 존재하지 않는 경우 0으로 초기화 한다.
    */
    Border[0] = -1;

    /*
        i는 경계의 현재 부분과 패턴의 현재 부분의 인덱스이다.
        j는 접두부를 가르킨다.
        만약 현재 패턴이 패턴의 접두부와 같다면 현재 패턴을 ++하면서 접두부도 ++해준다.
        다음 접두부를 검사하기 위함이다. 그리고 경계의 배열에 현재 부분에 j를 넣어주면서,
        접두부와 현재 패턴이 같은 만큼 값이 들어가게 된다.
    */
    while (i < PatternSize)
    {
        while (j > -1 && Pattern[i] != Pattern[j])
        {
            j = Border[j];
        }

        i++;
        j++;
        Border[i] = j; 
        
    }
    
}


int KnuthMorrisPratt(char* Text, int TextSize, int Start, char* Pattern, int PatternSize)
{
    int i = Start;
    int j = 0;
    int Position = -1;
    
    int* Border = (int*)calloc(PatternSize + 1, sizeof(int));

    /* 경계 배열을 만든다. */
    Preprocess(Pattern, PatternSize, Border);


    while (i < TextSize)
    {
        /*
            본문의 i와 패턴의 j가 불일치 할 경우
            j에 최대 경계 너비를 대입한다.
        */
        while (j >= 0 && Text[i] != Pattern[j])
        {
            j = Border[j];
        }
        
        i++;
        j++;

        /* 
            j가 패턴의 사이즈와 같다는 것은 일치하는 문자열을 찾았다는 뜻이므로,
            Position을 정하고 while문을 멈춘다.
        */
        if (j == PatternSize)
        {
            Position = i - j;
            break;
        }
        
    }
    
    free(Border);
    return Position;
}