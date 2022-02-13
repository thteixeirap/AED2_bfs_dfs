#include "graph.h"
#include "fila.h"

Vertex VertexInitialize(int value){
  Vertex v = malloc (sizeof(Vertex));
  v->value = value;
  return v;
}

Graph GraphInitialize(){
  Graph G = malloc (sizeof(Graph));
  G->V = MAX;
  G->E = 0;
  int i,j;

  for(i=0; i<MAX; i++){
    G->visitados[i] = 0;
    for(j=0;j<MAX;j++){
      G->Matriz[i][j] = 0;
    } 
  }
  return G;
}

void GraphInsertEdge(Graph G, int v1, int v2){
  
 G->Matriz[v1][v2] = 1;
 G->Matriz[v2][v1] = 1;
  
  G->E ++;
}

void ImprimeGraph(Graph G){

  int i, j;
  printf("\n  ");
  for(int k=0;k<MAX;k++)
    printf(" %d",k);
  printf("\n");
  
  for (i = 0; i < MAX; i++) {
    printf("%d: ", i);
    for (j = 0; j < MAX; j++) {
      printf("%d ", G->Matriz[i][j]);
    }
    printf("\n");
  }
  
}

void bfs(Graph G, int start){
 
  Fila f;
  FFVazia(&f);//criei a lista
  Enfileira(&f,start);// Adiciono a posição inicial na lista

  G->visitados[start] = 1; // Coloro de Cinza
  int vis;

  while(isEmpty(&f) == 0){ // Enquanto tiver elemento na lista
  
    FImprime(&f);
    vis = Desenfileira(&f); //Desinfilera a cabeça
    printf("Visitado vetor [%d] | Desenfilera da Fila\n",vis); 
    printf("\n V   E");
    for(int i=0;i<MAX; i++){

      printf("\n %d   %d",i,G->Matriz[vis][i]);

      if(G->visitados[i] ==  0 && (G->Matriz[vis][i] == 1)){ 
        
         
        G->visitados[i] = 1;    
        Enfileira(&f,i);// Adiciono os vetores que tem ligações
        printf(" Entrou, Enfilera [%d] na fila | recebe [Cor Cinza = 1]",i);
      }
    }
     G->visitados[vis] = 2; 
     printf("\n\nVertice [%d] | recebe [Cor Preta = 2]  \n", vis);

  }

}

//-----------DFS------------

void DFS_VISIT(Graph G,int v, int *cor, int *d, int *f, int *tempo){
  cor[v]  = 1;
  *tempo  += 1;
  d[v]    = *tempo;

  for(int u = 0; u < MAX; u++) // vou percorrer na linha da minha matriz
    if(G->Matriz[v][u] == 1 &&  cor[u] == 0)
      DFS_VISIT(G, u, cor, d, f, tempo);


  cor[v] = 2;
  *tempo += 1;
  f[v] = *tempo;
  printf("Vertex:%d D:%d, F:%d \n", v, d[v], f[v]);
}


void DFS(Graph G){
  int cor[MAX]; // Branco 0, Cinza 1, Preto 2
  int d[MAX];   // Tempo de descoberta
  int f[MAX];   // Tempo de finalização
  int tempo = 0;

  for(int v=0; v<MAX; v++)
    cor[v] = 0;

  for(int v=0; v<MAX; v++)
    if(cor[v] == 0)
      DFS_VISIT(G,v, cor, d, f, &tempo);
} 


