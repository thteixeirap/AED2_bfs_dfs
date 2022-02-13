#include "incidence.h"
#include "fila.h"

int ed_no = 0;

GraphInc GraphInitializeInc(){

  GraphInc G = malloc (sizeof(GraphInc));
  G->V = MAXInc;
  G->E = Edge;
  int i,j;

  for(i=0; i<MAXInc; i++){
    G->visitados[i] = 0;
    for(j=0;j<Edge;j++){
      G->Matriz[i][j] = 0;
    }
  }
  return G;
}

void GraphInsertEdgeInc(GraphInc G, int v1, int v2){
  
 G->Matriz[v1][ed_no] = 1;
 G->Matriz[v2][ed_no] = 1;
  
  ed_no++;
  G->E ++;
}

void ImprimeGraphInc(GraphInc G){

  int i, j;
  printf("\n  ");
  for(int k=0;k<Edge;k++)
  printf(" %d",k);
  printf("\n");
  
  for (i = 0; i < MAXInc; i++) {
    printf("%d: ", i);
    for (j = 0; j < Edge; j++) {
      printf("%d ", G->Matriz[i][j]);
    }
    printf("\n");
  }
  
}

void bfsInc(GraphInc G, int start){
 
  Fila f;
  FFVazia(&f);//criei a lista
  Enfileira(&f,start);// Adiciono a posição inicial na lista

  G->visitados[start] = 1; // Coloro de Cinza
  int vis;

  while(isEmpty(&f) == 0){ // Enquanto tiver elemento na lista
  
    FImprime(&f);
    vis = Desenfileira(&f); //Desinfilera a cabeça
    printf("Visitado vetor [%d] | Desenfilera da Fila\n",vis); 
    
    for(int i=0; i<Edge;i++){  // Vou percorrer as linhas procurando 
        
        if(G->Matriz[vis][i] == 1){
            
            for(int j=0; j<MAXInc;j++){
               // printf("Matriz[%d][%d] = %d  Visitados[%d] = %d \n",j,i,G->Matriz[j][i],j,G->visitados[j]);
                if(G->Matriz[j][i]==1 && G->visitados[j]==0 ){
                     G->visitados[j] = 1;    
                    Enfileira(&f,j);// Adiciono os vetores que tem ligações
                    printf(" Entrou, Enfilera [%d] na fila | Aresta: %d| recebe [Cor Cinza = 1]\n",j,i);
                    break;
                }
            }
        }
    }

     G->visitados[vis] = 2; 
     printf("\n\nVertice [%d] | recebe [Cor Preta = 2]  \n", vis);
  }

  free(&f);

}

//-----------DFS------------

void DFS_VISITInc(GraphInc G,int v, int *cor, int *d, int *f, int *tempo){
  cor[v]  = 1;
  *tempo  += 1;
  d[v]    = *tempo;

    for(int u = 0; u < Edge; u++){ // vou percorrer na linha da minha matriz
        if(G->Matriz[v][u] == 1 &&  cor[u] == 0){
            for(int j=0;j<MAXInc;j++){ // vou percorrer na linha da minha matriz
                if(G->Matriz[j][u] == 1 && cor[j] == 0){
                    //printf(" j->%d",j);
                    DFS_VISITInc(G, j, cor, d, f, tempo);
                }
            }
        }
    }


  cor[v] = 2;
  *tempo += 1;
  f[v] = *tempo;
  printf("Vertex:%d D:%d, F:%d \n", v, d[v], f[v]);
}


void DFSInc(GraphInc G){
  int cor[MAXInc]; // Branco 0, Cinza 1, Preto 2
  int d[MAXInc];   // Tempo de descoberta
  int f[MAXInc];   // Tempo de finalização
  int tempo = 0;

  for(int v=0; v<MAXInc; v++)
    cor[v] = 0;

  for(int v=0; v<MAXInc; v++)
    if(cor[v] == 0)
      DFS_VISITInc(G,v, cor, d, f, &tempo);
} 
