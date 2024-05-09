#include "MST.h"

/*
    ***프림 알고리즘 과정*** 
    1. 그래프와 최소 신장 트리를 준비한다.
    2. 그래프에서 임의 정점을 시작 정점으로 선택하여 최소 신장 트리의 루트 노드로 삽입한다.
    3. 최소 신장 트리에 삽입되어 있는 정점들과 이 정점들의 모든 인접 정점 사이에 있는 간선의 가중치를 조사한다.
       간선 중에 가장 가중치가 작은 것을 골라 이 간선에 연결되어 있는 인접 정점을 최소 신장 트리에 삽입한다. 
       단, 새로 삽입되는 정점은 최소 신장 트리에 삽입 되어 있는 기존의 노드들과 사이클을 형성해서는 안 된다.
    4. 3의 과정을 반복하다가 최소 신장 트리가 그래프의 모든 정점을 연결하게 되면 알고리즘을 종료한다.
*/
void Prim(Graph* G, Vertex* StartVertex, Graph* MST)
{
    /* 초기화 및 준비 코드 */
    int i = 0;
    PQNode StartNode = {0, StartVertex};
    PriorityQueue* PQ = PQ_Create(10);

    Vertex* CurrentVertex = NULL;
    Edge* CurrentEdge = NULL;

    /* 정점의 개수만큼 동적으로 메모리를 할당해서 각 가중치를 저장하기 위함 */
    int* Weights = (int*)malloc(sizeof(int) * G->VertexCount);

    /* 순서대로 MST에 포함될 정점, 프린지 정점, 선행 정점이다.*/
    /* 프린지는 MST에 인접한 정점을 의미한다. */
    /* Precedences 즉 선행 정점은 나중에 MST에 간선을 추가할 때 정점과 정점을 연결해주기 위해 사용된다.*/
    Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
    Vertex** Fringes = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
    Vertex** Precedences = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);

    CurrentVertex = G->Vertices;
    while (CurrentVertex != NULL)
    {
        Vertex* NewVertex = CreateVertex(CurrentVertex->Data);
        AddVertex(MST, NewVertex);

        Fringes[i] = NULL;
        Precedences[i] = NULL;
        MSTVertices[i] = NewVertex;
        Weights[i] = MAX_WEIGHT;
        CurrentVertex = CurrentVertex->Next;
        i++;
    }

    PQ_Enqueue(PQ, StartNode);

    Weights[StartVertex->Index] = 0;

    /* 우선순위 큐가 빌 때까지 BFS 알고리즘 비슷하게 실행 */
    while (!PQ_IsEmpty(PQ))
    {
        PQNode Popped;

        PQ_Dequeue(PQ, &Popped);
        CurrentVertex = (Vertex*)Popped.Data;
        Fringes[CurrentVertex->Index] = CurrentVertex;

        /* 현재 정점에 연결되어 있는 모든 Edge에 대해 검사 */
        CurrentEdge = CurrentVertex->AdjacencyList;
        while (CurrentEdge != NULL)
        {
            Vertex* TargetVertex = CurrentEdge->Target;

            /* 간선의 목표 정점이 아직 MST에 포함되지 않았고, 현재 간선의 가중치가 기존에 저장된 간선의 가중치보다 큰 경우 */
            if (Fringes[TargetVertex->Index] == NULL && CurrentEdge->Weight < Weights[TargetVertex->Index])
            {
                PQNode NewNode = {CurrentEdge->Weight, TargetVertex};
                PQ_Enqueue(PQ,NewNode);

                Precedences[TargetVertex->Index] = CurrentEdge->From;
                Weights[TargetVertex->Index] = CurrentEdge->Weight;
            }

            CurrentEdge = CurrentEdge->Next;
            
        }

    }

    /* 
        모든 정점에 대해 선행 정점 배열을 검사하며, 선행 정점이 존재하는 경우 
        해당 정점과 현재 정점을 연결하는 간선을 MST에 추가한다.
        여기서 간선의 가중치는 Weights[]에서 가져온다.
    */
    for ( i = 0; i < G->VertexCount; i++)
    {
        int FromIndex, ToIndex;
        if (Precedences[i] == NULL)
        {
            continue;
        }

        /* 이전 정점의 인덱스를 저장해놓았으므로 꺼내서 사용한다 */
        FromIndex = Precedences[i]->Index;
        ToIndex = i;

        AddEdge(MSTVertices[FromIndex], CreateEdge(MSTVertices[FromIndex], MSTVertices[ToIndex], Weights[i]));

        AddEdge(MSTVertices[ToIndex], CreateEdge(MSTVertices[ToIndex], MSTVertices[FromIndex], Weights[i]));
    }
    
    free(Fringes);
    free(Precedences);
    free(MSTVertices);
    free(Weights);
    
    PQ_Destroy(PQ);
}

/*
    ***크루스칼 알고리즘 과정***
    1. 그래프 내의 모든 간선을 가중치의 오름차순으로 목록을 만든다.
    2. 1번에서 만든 간선의 목록을 차례대로 순회하면서 간선을 최소 신장 트리에 추가한다.
       단, 이 때 추가된 간선으로 인해 최소 신장 트리 내에 사이클이 형성 되면 안 된다.
*/
void Kruskal(Graph* G, Graph* MST)
{
    int i;
    Vertex* CurrentVertex = NULL;
    Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);

    DisjointSet** VertexSet = (DisjointSet**)malloc(sizeof(DisjointSet*) * G->VertexCount);

    PriorityQueue* PQ = PQ_Create(10);

    i = 0;
    CurrentVertex = G->Vertices;
    while (CurrentVertex != NULL)
    {
        Edge* CurrentEdge;
        VertexSet[i] = DS_MakeSet(CurrentVertex);
        MSTVertices[i] = CreateVertex(CurrentVertex->Data);
        AddVertex(MST, MSTVertices[i]);

        CurrentEdge = CurrentVertex->AdjacencyList;
        while (CurrentEdge != NULL)
        {
            PQNode NewNode = {CurrentEdge->Weight, CurrentEdge};
            PQ_Enqueue(PQ, NewNode);

            CurrentEdge = CurrentEdge->Next;
        }

        CurrentVertex = CurrentVertex->Next;
        i++;
        
    }

    while (!PQ_IsEmpty(PQ))
    {
        Edge* CurrentEdge;
        int FromIndex;
        int ToIndex;
        PQNode Popped;

        PQ_Dequeue(PQ, &Popped);
        CurrentEdge = (Edge*)Popped.Data;

        FromIndex = CurrentEdge->From->Index;
        ToIndex = CurrentEdge->Target->Index;

        if (DS_FindSet(VertexSet[FromIndex]) != DS_FindSet(VertexSet[ToIndex]))
        {
            AddEdge(MSTVertices[FromIndex], 
                    CreateEdge(MSTVertices[FromIndex],
                               MSTVertices[ToIndex],
                               CurrentEdge->Weight));

            AddEdge(MSTVertices[ToIndex], 
                    CreateEdge(MSTVertices[ToIndex],
                               MSTVertices[FromIndex],
                               CurrentEdge->Weight));

            DS_UnionSet(VertexSet[FromIndex], VertexSet[ToIndex]);
        }
        
    }

    for ( i = 0; i < G->VertexCount; i++)
    {
        DS_DestroySet(VertexSet[i]);
    }

    free(VertexSet);
    free(MSTVertices);
    
}