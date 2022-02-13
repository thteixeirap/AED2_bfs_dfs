#ifndef INCIDENCE_H 
#define INCIDENCE_H

#include<stdlib.h>
#include<stdio.h>
#define MAXInc 6
#define Edge 9

typedef struct graphInc *GraphInc;


struct graphInc{
  int V;
  int E;
  int Matriz[MAXInc][Edge];
  int visitados[MAXInc];
};

GraphInc GraphInitializeInc();

void GraphInsertEdgeInc(GraphInc G, int v1, int v2);
void ImprimeGraphInc(GraphInc G);
void bfsInc(GraphInc G, int start);

void DFSInc(GraphInc G);
void DFS_VISITInc(GraphInc G,int v, int *cor, int *d, int *f, int *tempo);

#endif
