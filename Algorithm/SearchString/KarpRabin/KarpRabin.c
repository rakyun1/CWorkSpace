#include "KarpRabin.h"


int KarpRabin(char* Text, int TextSize, int Start, char* Pattern, int PatternSize)
{
    int i,j = 0;
    /* 거듭제곱을 위한 함수 pow() 첫 번째 인자를 두 번째 인자 만큼 거듭제곱해라 */
    int Coefficient = pow(2, PatternSize - 1);

    int HashText = Hash(Text, PatternSize);
    int HashPattern = Hash(Pattern, PatternSize);

    /* 검색을 시작하는 Start에서 부터, 총 문서 길이에 타겟하는 문서의 길이를 뺀 만큼만 for문을 돈다. */
    for ( i = Start; i <= TextSize - PatternSize; i++)
    {
        /*
            맨 처음 Hash()를 진행하여 이미 모든 문자열에 대한 해시 값을 얻었으므로
            다음 부터는 ReHash()를 진행하여 이전의 있던 값을 빼고 다음에 들어오는 값 추가
        */
        HashText = ReHash(Text, i, PatternSize - 1, HashText, Coefficient);

        if (HashPattern == HashText)
        {
            for ( j = 0; j < PatternSize; j++)
            {
                if (Text[i + j] != Pattern[j])
                {
                    break;
                }
                
            }

            if (j >= PatternSize)
            {
                return i;
            }
        }
        
    }
    
    return -1;
}

int Hash(char* String, int Size)
{
    int i = 0;
    int HashValue = 0;

    for ( i = 0; i < Size; i++)
    {
        HashValue = String[i] + (HashValue * 2);
    }
    
    return HashValue;
}

int ReHash(char* String, int Start, int Size, int HashPrev, int Coefficient)
{
    if (Start == 0)
    {
        return HashPrev;
    }
    
    return String[Start + Size - 1] + 
            ( (HashPrev - Coefficient * String[Start - 1]) * 2);
}