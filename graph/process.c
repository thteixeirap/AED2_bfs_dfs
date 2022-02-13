#include "process.h"

void Menu(){


    int op;
    printf("\n\n\t\t\tMENU\n");

    printf("\t1 - Matriz Adjacente [BFS]\n");
    printf("\t2 - Matriz Adjacente [DFS]\n");
    printf("\t3 - Matriz Incidente [BFS]\n");
    printf("\t4 - Matriz Incidente [DFS]\n");
    printf("\t--> ");
    scanf("%d",&op);


    switch (op)
    {
        case 1:
            MatrizAdjBFS();
        break;

         case 2:
            MatrizAdjDFS();
        break;

        case 3:
            MatrizIncBFS();
        break;

        case 4:
            MatrizIncDFS();
        break;
    
    default:
        break;
    }
}

void MatrizAdjBFS(){

    Graph G = GraphInitialize();

	GraphInsertEdge(G,0,1);
	GraphInsertEdge(G,0,2);
	GraphInsertEdge(G,1,2);
	GraphInsertEdge(G,1,4);
	GraphInsertEdge(G,1,3);
	GraphInsertEdge(G,2,4);
	GraphInsertEdge(G,4,3);
	GraphInsertEdge(G,4,5);
	
    printf("\n\n================ BFS ANALISADO=================\n\n");
	ImprimeGraph(G);
    bfs(G,0);	

    free(&G);
}

void MatrizAdjDFS(){
 
     Graph G = GraphInitialize();

	GraphInsertEdge(G,0,1);
	GraphInsertEdge(G,0,2);
	GraphInsertEdge(G,1,2);
	GraphInsertEdge(G,1,4);
	GraphInsertEdge(G,1,3);
	GraphInsertEdge(G,2,4);
	GraphInsertEdge(G,4,3);
	GraphInsertEdge(G,4,5);
    
	printf("\n\n================ DFS =================\n\n");
	DFS(G);	

    free(&G);
}

void MatrizIncBFS(){
    GraphInc GI = GraphInitializeInc();

 
    GraphInsertEdgeInc(GI,0, 4);
    GraphInsertEdgeInc(GI,0, 3);
    GraphInsertEdgeInc(GI,1, 2);
    GraphInsertEdgeInc(GI,1, 4);
    GraphInsertEdgeInc(GI,1, 5);
    GraphInsertEdgeInc(GI,2, 3);
    GraphInsertEdgeInc(GI,2, 5);
    GraphInsertEdgeInc(GI,5, 3);
    GraphInsertEdgeInc(GI,5, 4);

    printf("\n\n================ BFS ANALISADO =================\n\n");
	ImprimeGraphInc(GI);
	bfsInc(GI,0);
    free(&GI);
}

void MatrizIncDFS(){

    GraphInc GI = GraphInitializeInc();

 
    GraphInsertEdgeInc(GI,0, 4);
    GraphInsertEdgeInc(GI,0, 3);
    GraphInsertEdgeInc(GI,1, 2);
    GraphInsertEdgeInc(GI,1, 4);
    GraphInsertEdgeInc(GI,1, 5);
    GraphInsertEdgeInc(GI,2, 3);
    GraphInsertEdgeInc(GI,2, 5);
    GraphInsertEdgeInc(GI,5, 3);
    GraphInsertEdgeInc(GI,5, 4);

    printf("\n\n================ DFS =================\n\n");
    ImprimeGraphInc(GI);
    printf("\n\n");
    DFSInc(GI); 

}