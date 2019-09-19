#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

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

void GAddEdge(Graph * pGraph, int from, int to) {
    if (GIsConnected(pGraph, from, to)) {
        return;
    }
    
    int * pFrom = (int *) malloc( sizeof(int) );
    int * pTo = (int *) malloc( sizeof(int) );

    *pFrom = from;
    *pTo = to;

    LInsertTail(&(pGraph->adjList[from]), pTo); 
    LInsertTail(&(pGraph->adjList[to]), pFrom);

    pGraph->numberOfEdge += 1; 
}

int GDeleteEdge(Graph * pGraph, int from, int to) {
    List * connectedVertexList = &(pGraph->adjList[from]);
    int size = LSize(connectedVertexList);
    
    if (!GIsConnected(pGraph, from ,to)) {
        return 0;
    }

    for (int i=0; i<size; i++) {
        int vertex =  *((int *) LGet(connectedVertexList, i));
        
        if (vertex == to) {
            LRemoveIndex(connectedVertexList, i);
            break;
        }
    }

    connectedVertexList = &(pGraph->adjList[to]);
    size = LSize(connectedVertexList);

    for (int i=0; i<size; i++) {
        int vertex =  *((int *) LGet(connectedVertexList, i));
        
        if (vertex == from) {
            LRemoveIndex(connectedVertexList, i);
            break;
        }
    }

    pGraph->numberOfEdge -= 1;
    return 1;
}

int GIsConnected(Graph * pGraph, int from, int to) {
    List * connectedVertexList = &(pGraph->adjList[to]);
    int size = LSize(connectedVertexList);

    for (int i=0; i<size; i++) {
        int vertex = *((int *) LGet(connectedVertexList, i));
        
        if (vertex == from) {
            return 1;
        }
    }

    return 0;
}