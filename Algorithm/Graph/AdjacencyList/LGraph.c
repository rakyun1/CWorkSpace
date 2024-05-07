#include "LGraph.h"


Graph* CreateGraph()
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->Vertices = NULL;
    graph->VertexCount = 0;

    return graph;
}
void DestroyGraph(Graph* G)
{
    /* 그래프에 남아있는 모든 정점을 할당 해제 */
    while (G->Vertices != NULL)
    {
        Vertex* Vertices = G->Vertices->Next;
        DestroyVertex(G->Vertices);
        G->Vertices = Vertices;
    }
    
    free(G);
}

Vertex* CreateVertex(ElementType Data)
{
    Vertex* V = (Vertex*)malloc(sizeof(Vertex));

    V->Data = Data;
    V->Next = NULL;
    V->AdjacencyList = NULL;
    V->Visited = NotVisited; // 이넘은 내부적으로 정수로 처리된다. 그래서 이렇게 선언하면 1이라는 값이 들어가는데,
                             // 좀 더 읽기 쉽도록 이름을 정해놓은 것이다.
    V->Index = -1;

    return V;
}
void DestroyVertex(Vertex* V)
{
    /* 정점을 제거하기 전에, 정점에 연결되어 있는 모든 간선을 제거한 후에 정점을 제거 */
    while (V->AdjacencyList != NULL)
    {
        Edge* Edge = V->AdjacencyList->Next;

        DestroyEdge(V->AdjacencyList);

        V->AdjacencyList = Edge;
    }
    free(V);
}

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight)
{
    Edge* E = (Edge*)malloc(sizeof(Edge));
    E->From = From;
    E->Target = Target;
    E->Next = NULL;
    E->Weight = Weight;

    return E;
}
void DestroyEdge(Edge* E)
{
    free(E);
}

void AddVertex(Graph* G, Vertex* V)
{
    /* 
        그래프가 가지고 있는 정점리스트의 테일 부분을 찾아서 현재의 정점을 삽입 
        테일을 필드로 가지고 있으면 삽입하는데 시간이 많이 줄어들것 같음
    */
    Vertex* VertexList = G->Vertices;

    if (VertexList == NULL)
    {
        G->Vertices = V;
    }
    else{
        while (VertexList->Next != NULL)
        {
            VertexList = VertexList->Next;
        }
        VertexList->Next = V;
    }
    
    V->Index = G->VertexCount++;
}
void AddEdge(Vertex* V, Edge* E)
{
    /* 정점 삽입과 마찬가지로, 정점에 연결되어 있는 간선의 테일 부분에 새로운 간선을 추가 */
    if (V->AdjacencyList == NULL)
    {
        V->AdjacencyList = E;
    }
    else
    {
        Edge* AdjacencyList = V->AdjacencyList;
        
        while (AdjacencyList->Next != NULL)
        {
            AdjacencyList = AdjacencyList->Next;    
        }

        AdjacencyList->Next = E;
    }
    
}
void PrintGraph(Graph* G)
{
    Vertex* V = NULL;
    Edge* E = NULL;

    if ((V = G->Vertices) == NULL)
    {
        return;
    }

    while (V != NULL)
    {
        printf("%c : ", V->Data);
        if ((E = V->AdjacencyList) == NULL)
        {
            V = V->Next;
            printf("\n");
            continue;
        }
        while (E != NULL)
        {
            printf("%c[%d] ", E->Target->Data, E->Weight);
            E = E->Next;
        }
        
        printf("\n");
        V = V->Next;
    }
    
    printf("\n");    
}