<h1 align="center"> 
 Trabalho AEDS|CEFET 
</h1>
<h4 align="center">	
  Este trabalho consiste na implementação da estrutura BFS e DFS utilizando Matriz Adjacente e Matriz de Incidência
</h4>
<h1></h1>

#### Execução

- Usado o "C/C++ Makefile Project" extensão do VsCode

- Programa criado no Windowns 10, VisualCode
  
  Mudar no arquivo Makefile SRCDIR = "endereço da pasta"
  
  
 Modo de execução:
  
- Abrir pasta do arquivo  ./graph
- make
- graph.exe


## Adptação do Código

<p> Partindo do código estudado em sala e disponibilizado no qual utilizamos uma fila de adjacência foram reaizadas modificações tanto nas estruturas do grafo quanto nas estruturas BFS e DFS para comportar as matrizes de adjacência e de incidência <p>
 
### Grafo com Matrizes de Adjacência
 
 [#1](https://github.com/thteixeirap/BSF-DSF/blob/main/graph/graph.h#L16) -> A primeira mudança se refere a struct do grafo, no qual irá comportar uma matriz estática e um vetor estático que servirá de auxliar nas estruturas BSF e DFS.
 
 [#2](https://github.com/thteixeirap/BSF-DSF/blob/main/graph/graph.c#L10) -> Nossa iniciação irá atribuir para todos os indices do vetor visitados o valor de 0 e para todas posições da matriz.
 
 [#3](https://github.com/thteixeirap/BSF-DSF/blob/main/graph/graph.c#L25) -> Nossa inserção foi modificada para atribuir o valor de 1 para a posição da matriz em que os vértices fazem arestas.
 
 <h1></h1>
 
 #### Mudança no BFS (Matriz Adjacente)
 
 
 * BFS com lista de adjacência:
<img src="https://user-images.githubusercontent.com/78819692/153752438-a4a01b83-13de-4625-88ee-04e9140cad7f.png" width="350">

Para o nosso BFS comportar a matriz de adjacência tivemos uma mudança no dentro do while (linha 10 do exemplo acima). 

```sh
 while(isEmpty(&f) == 0){ // Enquanto tiver elemento na lista
  
    FImprime(&f);
    vis = Desenfileira(&f); //Desinfilera a cabeça
    printf("Visitado vetor [%d] | Desenfilera da Fila\n",vis); 
    printf("\n V   E");
    
    // Percorro toda minha linha do vetor q estou visitando procurando aresta (1)
    for(int i=0;i<MAX; i++){ 

      printf("\n %d   %d",i,G->Matriz[vis][i]);
      
      /* Se eu encontrar uma aresta, sendo q no vértice encontrado essa aresta 
       nao foi visitado, entro no if */
       
      if(G->visitados[i] ==  0 && (G->Matriz[vis][i] == 1)){ 
        G->visitados[i] = 1;   // Atribuo cor cinza 
        Enfileira(&f,i);// Adiciono o vertice encontrado na fila
        printf(" Entrou, Enfilera [%d] na fila | recebe [Cor Cinza = 1]",i);
      }

    }
     G->visitados[vis] = 2; // terminei de analisar o vértice por completo, recebe cor preta
     printf("\n\nVertice [%d] | recebe [Cor Preta = 2]  \n", vis);
  }
```
 
