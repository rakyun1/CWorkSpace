#include "BoyerMoore.h"

int BoyerMoore(char* Text, int TextSize, int Start, char* Pattern, int PatternSize)
{
    int BCT[128];
    int* Suffix = (int*)calloc(PatternSize + 1, sizeof(int));
    int* GST = (int*)calloc(PatternSize + 1, sizeof(int));
    int i = Start;
    int j = 0;

    int Position = -1;

    BuildBCT(Pattern, PatternSize, BCT);
    BuildGST(Pattern, PatternSize, Suffix, GST);

    while (i <= TextSize - PatternSize)
    {
        // j는 패턴의 오른쪽부터 왼쪽을 가르키는 포인터
        j = PatternSize - 1;

        /* 만약 패턴의 j와 본문의 i + j가 같다면 j를 다음 문자로 넘긴다. */
        while (j >= 0 && Pattern[j] == Text[i + j])
        {
            j--;
        }

        /* j가 패턴 내에서 더 이상 갈 곳이 없다는건 본문에서 문자를 찾았다는 뜻이다. */
        if (j < 0)
        {
            Position = i;
            break;
        }
        else
        {
            /*
                아직 비교해야할 패턴의 문자가 남았다면, 착한 접미부 테이블의 값과 나쁜 단어 테이블의 값 중에서
                더 큰 값으로 i를 초기화 한다.
            */
            i += Max(GST[j + 1], j - BCT[Text[i + j]]);
        }

    }

    free(Suffix);
    free(GST);

    return Position;
}

void BuildGST(char* Pattern, int PatternSize, int* Suffix, int* GST)
{
    /* case 1 */
    int i = PatternSize;
    int j = PatternSize + 1;

    Suffix[i] = j;

    while (i > 0)
    {
        while (j <= PatternSize && Pattern[i - 1] != Pattern[j - 1])
        {
            if (GST[j] == 0)
            {
                GST[j] = j - i;
            }
            
            j = Suffix[j];
        }
        
        i--;
        j--;

        Suffix[i] = j;
    }

    /* case 2 */
    j = Suffix[0];

    for ( i = 0; i <= PatternSize; i++)
    {
        if (GST[i] == 0)
        {
            GST[i] = j;
        }
        
        if (i == j)
        {
            j = Suffix[j];
        }
        
    }
    
}

void BuildBCT(char* Pattern, int PatternSize, int* BCT)
{
    int i;
    int j;

    for ( i = 0; i < 128; i++)
    {
        BCT[i] = -1;
    }

    for ( j = 0; j < PatternSize; j++)
    {
        BCT[Pattern[j]] = j;
    }
    
}

int Max(int A, int B)
{
    if (A > B)
    {
        return A;
    }
    else
    {
        return B;
    }
    
}