#ifndef __ADJACENT_LIST_GRAPH_H__
#define __ADJACENT_LIST_GRAPH_H__

#include "DoubleLinkedList.h"

typedef struct _adjacent_list_graph {
    int numberOfVertex;
    int numberOfEdge;
    List * adjList;
} ALGraph;

typedef ALGraph Graph;

void GInit(Graph * pGraph, int numberOfVertex);
void GDestroy(Graph * pGraph);
void GAddEdge(Graph * pGraph, int from, int to);
int GDeleteEdge(Graph * pGraph, int from, int to);
int GIsConnected(Graph * pGraph, int from, int to);

#endif // !__ADJACENT_LIST
