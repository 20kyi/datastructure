#include <stdlib.h>
#include <assert.h>

#include "ALGraph.h"

void GInit(Graph * pGraph, int numberOfVertex) {
    pGraph->numberOfEdge = 0;
    pGraph->numberOfVertex = numberOfVertex;
    pGraph->adjList = (List *) malloc( sizeof(List) * numberOfVertex );

    for (int i=0; i<numberOfVertex; i++) {
        LInit( &(pGraph->adjList[i]) );
    }
}

void GDestroy(Graph * pGraph) {
    if (pGraph->adjList == NULL) {
        return;
    }

    int numberOfVertex = pGraph->numberOfVertex;

    for (int i=0; i<numberOfVertex; i++) {
        LDestroy( &(pGraph->adjList[i]) );
    }

    free(pGraph->adjList);
}

void GAddEdge(Graph * pGraph, Vertex * from, Vertex * to) {

    int fromV = from->where;
    int toV = to->where;

    LInsertTail(&(pGraph->adjList[fromV]), to); 
    LInsertTail(&(pGraph->adjList[toV]), from);

    pGraph->numberOfEdge += 1; 
}

void GShowVertexInfo(Graph * pGraph, int where, ShowVertex show) {
    assert(where < pGraph->numberOfVertex);
    List * connectedVertexList = &(pGraph->adjList[where]);
    int size = LSize(connectedVertexList);
        
    for (int j=0; j<size; j++) {
        Vertex * v = (Vertex *) LGet(connectedVertexList, j);
        show(*v);
    }    
}