#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PriorityQueue.h"

#define NUMBER_OF_VERTEX 6

typedef struct _edge {
    int v1;
    int v2;
    int weight;
} Edge;

int isAllVisit(int * visitInfo) {
    for (int i=0; i<NUMBER_OF_VERTEX; i++) {
        if (visitInfo[i] != 1) {
            return 0;
        }
    }

    return 1;
}

int IsConnectedWithoutEdge(int (*graph)[NUMBER_OF_VERTEX], int * visitInfo, int visit, int dest) {
    if (visitInfo[visit]) {
        return 0;
    }

    if (visit == dest) {
        return 1;
    }

    int res = 0;

    visitInfo[visit] = 1;

    for (int to=0; to<NUMBER_OF_VERTEX; to++) {
        if (graph[visit][to] && !visitInfo[to]) {
            res |= IsConnectedWithoutEdge(graph, visitInfo, to, dest);
        }

        if (res) {
            break;
        }
    }

    return res;
}

int edgeCompareFunc(void * p1, void * p2) {
    Edge * e1 = p1;
    Edge * e2 = p2;
    return (e1->weight) - (e2->weight);
}

void MakeMSTWithKruskal(int (*graph)[NUMBER_OF_VERTEX]) {
    PriorityQueue pq;
    QInit(&pq, edgeCompareFunc);

    int edgeCount = 0;
    // 간선 정보를 가중치가 큰 것을 우선순위로 하여 우선순위 큐에 모두 넣습니다.
    for (int i=0; i<NUMBER_OF_VERTEX; i++) {
        for (int j=i+1; j<NUMBER_OF_VERTEX; j++) {
            if (graph[i][j]) {
                Edge * edge = (Edge *) malloc(sizeof(Edge));
                edge->v1 = i;
                edge->v2 = j;
                edge->weight = graph[i][j];
                Enqueue(&pq, edge);
                edgeCount += 1;
            }
        }
    }

    //연결된 간선의 개수 + 1 == 정점의 개수가 될 때가지 다음을 반복합니다.
    //1. 우선 순위 큐에서 간선을 하나 빼옵니다.
    //2. 해당 간선을 제거합니다.
    //3. 그래프에서, 제거된 간선을 가진 두 정점이 연결될 수 있나 확인합니다.
    //4. 연결 될 수 없으면 다시 연결합니다.(이 때는 우선순위 큐에 넣지 않습니다.)
    while (edgeCount >= NUMBER_OF_VERTEX) {
        Edge * edge = (Edge *)Dequeue(&pq);
        int v1 = edge->v1;
        int v2 = edge->v2;
        int weight = edge->weight;

        graph[v1][v2] = 0;
        graph[v2][v1] = 0;
        edgeCount -= 1;

        int visitInfo[NUMBER_OF_VERTEX];
        memset(visitInfo, 0, sizeof(visitInfo));

        if (!IsConnectedWithoutEdge(graph, visitInfo, v1, v2)) {
            graph[v1][v2] = weight;
            graph[v2][v1] = weight;
            edgeCount += 1; 
        }
    }

    QDestory(&pq);
}

void ShowGraph(int (*graph)[NUMBER_OF_VERTEX]) {
    for (int i=0; i<NUMBER_OF_VERTEX; i++) {
        printf("정점 %d : ", i);

        for (int j=0; j<NUMBER_OF_VERTEX; j++) {
            if (graph[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    printf("\n");
}

int main () {
    int graph[NUMBER_OF_VERTEX][NUMBER_OF_VERTEX] = {
        {  0,  9, 12,  8,  0, 11 },
        {  9,  0,  2,  0,  0,  0 },
        { 12,  2,  0,  6,  7,  0 },
        {  8,  0,  6,  0,  3,  4 },
        {  0,  0,  7,  3,  0, 13 },
        { 11,  0,  0,  4, 13,  0 }
    };
    ShowGraph(graph);

    MakeMSTWithKruskal(graph);
    ShowGraph(graph);
    return 0;
}