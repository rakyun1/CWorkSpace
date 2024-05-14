#include "Heap.h"


Heap* HEAP_Create(int InitialSize)
{
    Heap* NewHeap = (Heap*)malloc(sizeof(Heap));
    NewHeap->Capacity = InitialSize;
    NewHeap->UsedSize = 0;
    NewHeap->Nodes = (HeapNode*)malloc(sizeof(HeapNode) * InitialSize);

    printf("size : %d\n", sizeof(HeapNode));

    return NewHeap;
}

void HEAP_Destroy(Heap* H)
{
    free(H->Nodes);
    free(H);
}

void HEAP_Insert(Heap* H, ElemenType NewData)
{
    // 힙의 사용된 사이즈를 보면, 그 다음에 들어가야 하는 인덱스를 알 수 있다.
    // 힙에서 처음 삽입이 일어날 때 트리의 가장 하단의 최 우측에 들어가기에 UsedSize를 현재 포지션으로 잡는 것이다.
    int CurrentPosition = H->UsedSize;
    int ParentPosition = HEAP_GetParent(CurrentPosition);

    // 아래의 코드는 배열로 힙을 구현하는 것이기 때문에 용량이 꽉차면 용량을 늘려주는 작업을 하는 것이다.
    if (H->UsedSize == H->Capacity)
    {
        H->Capacity *= 2;
        H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }

    H->Nodes[CurrentPosition].Data = NewData;

    // 힙에서 삽입이 일어날 때 위 코드를 보면 알 수 있지만 처음에 넣을 때 부터 올바른 자리에 찾아가서 데이터를 넣는 것이 아니기에
    // 힙의 규칙이 깨질 수 있다. 그래서 힙의 규칙을 다시 맞춰주기 위해 후속조치를 해야 한다.
    // while문을 힙의 Nodes의 CurrentPosition이 ParentPosition 보다 작으면 
    // 자식은 부모 노드보다 작아야 한다는 힙의 규칙을 만족하기에 while문을 멈춘다. 
    while (CurrentPosition > 0 && H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data)
    {
        // while문 안에 들어왔다는 것은 조건을 만족하고 있지 못하다는 뜻이다.
        // 그렇기에 현재 포지션의 값이 부모의 포지션의 값보다 작다는 뜻인데, Swap() 함수를 통해
        // 두 노드의 위치를 바꾸어준다.
        HEAP_SwapNodes(H, CurrentPosition, ParentPosition);

        CurrentPosition = ParentPosition;
        ParentPosition = HEAP_GetParent(CurrentPosition);
    }
    
    // 삽입이 일어났으므로 사용된 사이즈를 +1 해준다.
    H->UsedSize++;
}

void HEAP_SwapNodes(Heap* H, int index1, int index2)
{
    int CopySize = sizeof(HeapNode);
    HeapNode* Temp = (HeapNode*)malloc(CopySize);

    // memcpy() 함수를 통해 Temp라는 변수에 Nodes[index1] 노드를 저장하고
    // Nodes[index1]에 Nodes[index2]를 넣은 후에
    // Nodes[index2]에 Temp를 넣고 Temp에 할당 된 메모리를 해제한다.
    memcpy(Temp, &H->Nodes[index1], CopySize);
    memcpy(&H->Nodes[index1], &H->Nodes[index2], CopySize);
    memcpy(&H->Nodes[index2], Temp, CopySize);

    free(Temp);
}

void HEAP_DeleteMin(Heap* H, HeapNode* Root)
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    // memcpy() 함수를 사용해 Root에 힙의 루트 노드를 복사하고
    memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
    // memset() 함수를 사용해 힙의 루트 노드를 0으로 초기화
    memset(&H->Nodes[0], 0, sizeof(HeapNode));

    // 힙의 사용된 사이즈를 줄이고, 힙의 루트 노드와 힙의 가장 최하단 최우측에 있는 값을
    // 힙의 루트 노드로 가지고 옴
    H->UsedSize--;
    HEAP_SwapNodes(H, 0, H->UsedSize);

    // 루트 노드의 왼쪽 자식과 오른쪽 자식의 인덱스를 설정
    LeftPosition = HEAP_GetLeftChild(0);
    RightPosition = LeftPosition + 1;

    while (1)
    {
        int SelectedChild = 0;

        // 왼쪽 자식이 현재 사용된 힙의 크기 보다 크다는 뜻은
        // 더 이상 갈 곳이 없다는 뜻이기에 while문을 종료
        if (LeftPosition >= H->UsedSize)
            break;
        
        // 오른쪽 자식이 현재 사용된 힙의 크기 보다 크다면
        // 오른쪽 자식은 더 이상 없기에 신경 쓸 필요가 없어
        // 왼쪽 자식만 신경 씀
        if (RightPosition >= H->UsedSize)
        {
            SelectedChild = LeftPosition;
        }
        else
        {
            // 왼쪽 자식과 오른쪽 자식 중에서 더 작은 값으로 SelectedChild를 변경
            if (H->Nodes[LeftPosition].Data > H->Nodes[RightPosition].Data)
                SelectedChild = RightPosition;
            else
                SelectedChild = LeftPosition;           
        }
        
        // 현재 선택된 자식 즉 왼쪽 자식과 오른쪽 자식 중에 더 작은 값이
        // 부모의 값보다 작다면 위치를 교환 후에 부모의 값을 선택된 자식의 값으로 변경함
        // 이제 선택된 자식이 루트 노드가 되었고, SelectedChild에는 부모의 값이 들어와 있음
        // 그럼 부모의 값을 기준으로 다시 왼쪽 자식과 오른쪽 자식을 비교해야 하기에
        // ParentPosition = SelectedChild; 이 코드를 실행함
        if (H->Nodes[SelectedChild].Data < H->Nodes[ParentPosition].Data)
        {
            HEAP_SwapNodes(H, ParentPosition, SelectedChild);
            ParentPosition = SelectedChild;
        }
        else
            break;
        
        LeftPosition = HEAP_GetLeftChild(ParentPosition);
        RightPosition = LeftPosition + 1;
    }

    if (H->UsedSize < (H->Capacity / 2))
    {
        H->Capacity /= 2;
        H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }
    
}

int HEAP_GetParent(int index)
{
    return (int) ((index - 1) / 2);
}
int HEAP_GetLeftChild(int index)
{
    return (2 * index) + 1;
}
void HEAP_PrintNodes(Heap* H)
{
    int i = 0;
    for ( i = 0; i < H->UsedSize; i++)
    {
        printf("%d ", H->Nodes[i].Data);
    }
    printf("\n");
    
}