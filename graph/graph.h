#ifndef GRAPH_H 
#define GRAPH_H

#include<stdlib.h>
#include<stdio.h>
#define MAX 6

typedef struct graph *Graph;
typedef struct TipoVertex *Vertex;


struct TipoVertex{
  int value;
};

struct graph{
  int V;
  int E;
  int Matriz[MAX][MAX];
  int visitados[MAX];
};



Vertex VertexInitialize(int value);
Graph GraphInitialize();

void GraphInsertEdge(Graph G, int v1, int v2);
void ImprimeGraph(Graph G);
void bfs(Graph G, int start);

void DFS(Graph G);
void DFS_VISIT(Graph G,int v, int *cor, int *d, int *f, int *tempo);

#endif
