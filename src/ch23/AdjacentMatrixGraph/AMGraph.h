#ifndef __ADJACENT_MATRIX_GRAPH_H__
#define __ADJACENT_MATRIX_GRAPH_H__

typedef struct _adjacent_matrix_graph {
    int numberOfVertex;
    int numberOfEdge;
    int ** matrix;
} AMGraph;

typedef AMGraph Graph;

void GInit(Graph * pGraph, int numberOfVertex);
void GDestroy(Graph * pGraph);
void GAddEdge(Graph * pGraph, int from, int to);
int GDeleteEdge(Graph * pGraph, int from, int to);
int GIsConnected(Graph * pGraph, int from, int to);

#endif // !__ADJACENT_LIST
