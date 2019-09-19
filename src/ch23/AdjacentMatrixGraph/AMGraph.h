#ifndef __ADJACENT_MATRIX_GRAPH_H__
#define __ADJACENT_MATRIX_GRAPH_H__

typedef void * VData;

typedef struct _vertex {
    int where;
    VData data;
} Vertex;

typedef void ShowVertex(Vertex v);

typedef struct _adjacent_matrix_graph {
    int numberOfVertex;
    int numberOfEdge;
    Vertex ** matrix;
} AMGraph;

typedef AMGraph Graph;

void GInit(Graph * pGraph, int numberOfVertex);
void GDestroy(Graph * pGraph);
void GAddEdge(Graph * pGraph, Vertex * from, Vertex * to);
void GShowVertexInfo(Graph * pGraph, int where, ShowVertex show);

#endif // !__ADJACENT_LIST
