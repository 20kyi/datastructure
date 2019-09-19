#ifndef __ADJACENT_LIST_GRAPH_H__
#define __ADJACENT_LIST_GRAPH_H__

#include "DoubleLinkedList.h"

typedef void * VData;

typedef struct _vertex {
    int where;
    VData data;
} Vertex;

typedef void ShowVertex(Vertex v);

typedef struct _adjacent_list_graph {
    int numberOfVertex;
    int numberOfEdge;
    List * adjList;
} ALGraph;

typedef ALGraph Graph;

void GInit(Graph * pGraph, int numberOfVertex);
void GDestroy(Graph * pGraph);
void GAddEdge(Graph * pGraph, Vertex * from, Vertex * to);
int GDeleteEdge(Graph * pGraph, Vertex * from, Vertex * to);
void GShowVertexInfo(Graph * pGraph, int where, ShowVertex show);

#endif // !__ADJACENT_LIST
