#include <stdio.h>
#include <stdlib.h>

#include "AMGraph.h"

void showGraphInfo(Graph * pGraph, char * vertexData) {

    int size = pGraph->numberOfVertex;

    for (int i=0; i<size; i++) {

        printf("%d번째 정점 : %c\n", i, vertexData[i]);
        printf("%d번째 연결된 정점들 : ", i);

        for (int j=0; j<size; j++) {
            if (GIsConnected(pGraph, i, j)) {
                printf("%c ", vertexData[j]);
            }
        }
        printf("\n\n");
    }
    printf("\n");
}

int main() {
    char vertexData[] = "ABCDE";
    int size = sizeof(vertexData) / sizeof(vertexData[0]) - 1;

    Graph graph;
    GInit(&graph, size);

    GAddEdge( &graph, 0, 1 );  // A - B
    GAddEdge( &graph, 0, 3 );  // A - D
    GAddEdge( &graph, 1, 2 );  // B - C
    GAddEdge( &graph, 2, 3 );  // C - D
    GAddEdge( &graph, 3, 4 );  // D - E
    GAddEdge( &graph, 4, 0 );  // E - A

    showGraphInfo(&graph, vertexData);

    GDeleteEdge(&graph, 4, 0 );

    showGraphInfo(&graph, vertexData);

    GDestroy(&graph);
    return 0;
}