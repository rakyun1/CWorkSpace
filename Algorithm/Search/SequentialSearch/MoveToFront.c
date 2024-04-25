#include <stdio.h>

// Node* SLL_MoveToFront(Node** Head, int target)
// {
//     Node* Current = (*Head);
//     Node* Previous = NULL;
//     Node* Match = NULL;

//     while (Current != NULL)
//     {
//         if (Current->Data == target)
//         {
//             Match = Current;
//             if (Previous != NULL)
//             {
//                 Previous->NextNode = Current->NextNode;

//                 Current->NextNode = (*Head);
//                 (*Head) = Current;
//             }
//             break;
//         }
//         else
//         {
//             Previous = Current;
//             Current = Current->NextNode;
//         }
        
//     }
//     return Match;
// }

void SLL_MoveToFront(int* arr, int target, int Length)
{
    if (arr[0] == target)
    {
        return;
    }

    for (int i = 1; i < Length; i++)
    {
        if (arr[i] == target)
        {
            int temp = arr[0];
            arr[0] = target;
            arr[i] = temp;
        }
        
    }
    
}

int main(void)
{
    int arr[] = {6, 2, 3, 1, 5, 4, 7, 10};
    int target = 5;
    int Length = sizeof arr / sizeof arr[0];

    SLL_MoveToFront(arr, target, Length);

    for (int i = 0; i < Length; i++)
    {
        printf("arr[%d] :: %d\n", i, arr[i]);
    }
    
    return 0;
}
