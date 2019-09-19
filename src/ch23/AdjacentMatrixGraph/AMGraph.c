#include <stdlib.h>
#include <assert.h>

#include "AMGraph.h"

void GInit(Graph * pGraph, int numberOfVertex) {
    pGraph->numberOfEdge = 0;
    pGraph->numberOfVertex = numberOfVertex;
    pGraph->matrix = (int **) malloc( sizeof(int *) * numberOfVertex ); 

    for (int i=0; i<numberOfVertex; i++) {
        pGraph->matrix[i] = ( int * ) malloc( sizeof(int) * numberOfVertex );

        for (int j=0; j<numberOfVertex; j++) {
            pGraph->matrix[i][j] -1;
        }
    }
}

void GDestroy(Graph * pGraph) {
    if (pGraph->matrix == NULL) {
        return;
    }

    int numberOfVertex = pGraph->numberOfVertex;

    for (int i=0; i<numberOfVertex; i++) {
        free(pGraph->matrix[i]);
    }

    free(pGraph->matrix);
}

void GAddEdge(Graph * pGraph, int from, int to) {
    if (GIsConnected(pGraph, from, to)) {
        return;
    }

    pGraph->matrix[from][to] = 1;
    pGraph->matrix[to][from] = 1;

    pGraph->numberOfEdge += 1; 
}

int GDeleteEdge(Graph * pGraph, int from, int to) {
    if (!GIsConnected(pGraph, from, to)) {
        return 0;
    }

    pGraph->matrix[from][to] = -1;
    pGraph->matrix[to][from] = -1;
    pGraph->numberOfEdge -= 1;
    return 1;
}

int GIsConnected(Graph * pGraph, int from, int to) {
    return (pGraph->matrix[from][to] != -1);
}