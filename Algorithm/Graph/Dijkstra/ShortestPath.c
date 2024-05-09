#include "ShortestPath.h"

void Dijkstra(Graph* G, Vertex* StartVertex, Graph* ShortestPath)
{
    int i = 0;
    PQNode StartNode = {0, StartVertex};
    PriorityQueue* PQ = PQ_Create(10);

    Vertex* CurrentVertex = NULL;
    Edge* CurrentEdge = NULL;

    int* Weights = (int*)malloc(sizeof(int) * G->VertexCount);

    Vertex** ShortestPathVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
    Vertex** Fringes = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
    Vertex** Precedences = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);

    /* 최단 경로를 표시할 그래프 ShortestPath에 모든 정점 추가 */
    CurrentVertex = G->Vertices;
    while (CurrentVertex != NULL)
    {
        Vertex* NewVertex = CreateVertex(CurrentVertex->Data);
        AddVertex(ShortestPath, NewVertex);

        Fringes[i] = NULL;
        Precedences[i] = NULL;
        ShortestPathVertices[i] = NewVertex;
        Weights[i] = MAX_WEIGHT;
        CurrentVertex = CurrentVertex->Next;
        i++;
    }

    /* 우선순위 큐에 시작 노드 삽입 */
    PQ_Enqueue(PQ, StartNode);

    Weights[StartVertex->Index] = 0;

    /*
        우선순위 큐가 빌 때까지 선택된 정점과 간선으로 연결되어 있는 모든 정점을 추가하며
        최단 경로에 값 삽입
    */
    while (!PQ_IsEmpty(PQ))
    {
        
        PQNode Popped;

        /* 우선순위 큐에서 가중치가 가장 낮은 정점을 꺼냄 */
        PQ_Dequeue(PQ, &Popped);
        CurrentVertex = (Vertex*)Popped.Data;

        Fringes[CurrentVertex->Index] = CurrentVertex;

        /* 현재 정점의 간선을 조사하기 위함 */
        CurrentEdge = CurrentVertex->AdjacencyList;
        
        /* 현재 선택된 정점과 연결된 간선을 조사 */
        while (CurrentEdge != NULL)
        {
            Vertex* TargetVertex = CurrentEdge->Target;

            /* 
                현재 정점과 연결된 정점이 방문한적 없는 정점이고, 
                현재 정점을 거쳐 목표 정점으로 가는 경로가 기존에 알려진 목표 정점까지의
                경로보다 더 짧은지 확인
            */
            if (Fringes[TargetVertex->Index] == NULL && 
                Weights[CurrentVertex->Index] + CurrentEdge->Weight < 
                                            Weights[TargetVertex->Index])
            {
                PQNode NewNode = {CurrentEdge->Weight, TargetVertex};
                PQ_Enqueue(PQ,NewNode);

                Precedences[TargetVertex->Index] = CurrentEdge->From;
                Weights[TargetVertex->Index] = Weights[CurrentVertex->Index] +
                                               CurrentEdge->Weight;
            }

            CurrentEdge = CurrentEdge->Next;
            
        }
        
    }

    for ( i = 0; i < G->VertexCount; i++)
    {
        int FromIndex, ToIndex;

        if (Precedences[i] == NULL)
        {
            continue;
        }

        FromIndex = Precedences[i]->Index;
        ToIndex = i;

        AddEdge(ShortestPathVertices[FromIndex],
            CreateEdge(ShortestPathVertices[FromIndex],
                       ShortestPathVertices[ToIndex],
                       Weights[i]));
        
    }

    free(Fringes);
    free(Precedences);
    free(ShortestPathVertices);
    free(Weights);
    
    
    PQ_Destroy(PQ);
}