#include <stdio.h>

// Node* SLL_Transpose(Node** Head, int Target)
// {
//     Node* Current = (*Head); // Head 노드부터 탐색 시작
//     Node* PPrevious = NULL;
//     Node* Previous = NULL;
//     Node* Match = NULL;

//     while (Current != NULL)
//     {
//         if (Current->Data == Target)
//         {
//             Match = Current;
//             if (Previous != NULL) // 이전 노드가 NULL이라면 더 이상 앞으로 갈 수 없는 헤드 노드이기에 함수를 종료함
//             {
//                 if (PPrevious != NULL) 
//                 {
//                     PPrevious->NextNode = Current;
//                 }
//                 else // 현재 노드의 이전이전 노드가 없다는 뜻은 자신이 두 번째 노드라는 뜻
//                     (*Head) = Current; // 그러므로 앞의 노드와 자리가 바뀌어서 현재 노드가 헤드 노드가 됨
                
//                 // 이전 노드의 다음 노드를 현재 노드의 다음 노드로 변경하고 현재 노드의 다음 노드를 이전 노드로 변경
//                 // 현재 노드가 이전 노드보다 앞으로 가기 위함 
//                 Previous->NextNode = Current->NextNode;
//                 Current->NextNode  = Previous;
//             }
//             break;
            
//         }
//         else
//         {
//             if (Previous != NULL)
//             {
//                 PPrevious = Previous;
//             }
//             Previous = Current;
//             Current = Current->NextNode;
            
//         }
//     }
//     return Match;
// }

void SLL_Transpose(int* arr, int target, int Length)
{
    if (arr[0] == target)
    {
        return;
    }

    for (int i = 1; i < Length; i++)
    {
        if (arr[i] == target)
        {
            int temp = arr[i - 1];
            arr[i - 1] = target;
            arr[i] = temp;
        }
        
    }
    
}

int main(void)
{
    int arr[] = {6, 2, 3, 1, 5, 4, 7, 10};
    int target = 5;
    int Length = sizeof arr / sizeof arr[0];

    printf("\n\n================전위법 실행전 =================\n\n");
    for (int i = 0; i < Length; i++)
    {
        printf("arr[%d] :: %d\n", i, arr[i]);
    }
    
    SLL_Transpose(arr, target, Length);

    printf("\n\n================전위법 실행후, 타겟 = 5 =================\n\n");
    for (int i = 0; i < Length; i++)
    {
        printf("arr[%d] :: %d\n", i, arr[i]);
    }

    /* code */
    return 0;
}
