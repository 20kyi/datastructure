#include <stdlib.h>
#include <assert.h>

#include "AMGraph.h"

void GInit(Graph * pGraph, int numberOfVertex) {
    pGraph->numberOfEdge = 0;
    pGraph->numberOfVertex = numberOfVertex;
    pGraph->matrix = (Vertex **) malloc( sizeof(Vertex *) * numberOfVertex ); 

    for (int i=0; i<numberOfVertex; i++) {
        pGraph->matrix[i] = ( Vertex * ) malloc( sizeof(Vertex) * numberOfVertex );

        for (int j=0; j<numberOfVertex; j++) {
            pGraph->matrix[i][j].where = -1;
            pGraph->matrix[i][j].data = NULL;
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

void GAddEdge(Graph * pGraph, Vertex * from, Vertex * to) {

    int fromV = from->where;
    int toV = to->where;

    pGraph->matrix[fromV][toV] = *to;
    pGraph->matrix[toV][fromV] = *from;

    pGraph->numberOfEdge += 1; 
}

int GDeleteEdge(Graph * pGraph, Vertex * from, Vertex * to) {
    int fromV = from->where;
    int toV = to->where;

    if (pGraph->matrix[fromV][toV].where == -1) {
        return 0;
    }

    pGraph->matrix[fromV][toV].where = -1;
    pGraph->matrix[fromV][toV].data = NULL;
    pGraph->matrix[toV][fromV].where = -1;
    pGraph->matrix[toV][fromV].data = NULL;

    pGraph->numberOfEdge -= 1;
    return 1;
}

void GShowVertexInfo(Graph * pGraph, int where, ShowVertex show) {
    int size = pGraph->numberOfVertex;
    assert(where < size);
    
    Vertex * connectedVertexList = pGraph->matrix[where];
        
    for (int i=0; i<size; i++) {
        if ( connectedVertexList[i].where == -1 ) {
            continue;
        }
        
        show(connectedVertexList[i]);
    }    
}