#include <stdio.h>
#include <stdlib.h>

#include "AMGraph.h"

void showVertex(Vertex v) {
    int where = v.where;
    char * pData = (char *) v.data;

    printf("{ %d : %c } ", where, *pData);
}

void showGraphInfo(Graph * pGraph, Vertex * vetexList) {
    int size = pGraph->numberOfVertex;

    for (int i=0; i<size; i++) {
        printf("%d 번째 정점 : ", i);
        showVertex(vetexList[i]);
        printf("\n");

        printf("%d 번째 정점과 연결된 정점들 정보 : ", i);
        GShowVertexInfo(pGraph, i, showVertex);
        printf("\n\n");
    }
}

int main() {
    char vertexData[] = "ABCDE";
    int size = sizeof(vertexData) / sizeof(vertexData[0]) - 1;
    
    Vertex * vertexList = (Vertex *) malloc( sizeof(Vertex) * size );

    for (int i=0; i<size; i++) {
        vertexList[i].where = i;
        vertexList[i].data = &(vertexData[i]);
    }

    Graph graph;
    GInit(&graph, size);

    GAddEdge( &graph, &(vertexList[0]), &(vertexList[1]) );  // A - B
    GAddEdge( &graph, &(vertexList[0]), &(vertexList[3]) );  // A - D
    GAddEdge( &graph, &(vertexList[1]), &(vertexList[2]) );  // B - C
    GAddEdge( &graph, &(vertexList[2]), &(vertexList[3]) );  // C - D
    GAddEdge( &graph, &(vertexList[3]), &(vertexList[4]) );  // D - E
    GAddEdge( &graph, &(vertexList[4]), &(vertexList[0]) );  // E - A

    showGraphInfo(&graph, vertexList);

    GDestroy(&graph);
    free(vertexList);
    return 0;
}