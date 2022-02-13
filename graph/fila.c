#include "fila.h"


void FFVazia(Fila *f){
	f->first = 1;
	f->last  = 1;
}

void Enfileira(Fila *f, int d){
	if (f->last % MAXTAM + 1 == f->first){
		printf("FILA CHEIA!\n");
	}else{
		f->vet[f->last - 1] = d;
		f->last = f->last % MAXTAM + 1;
	}

}

int Desenfileira(Fila *f){

	int d;

	if(f->first == f->last)
		printf("FILA VAZIA!\n");
	else{
		d = f->vet[f->first - 1];
		f->first = f->first % MAXTAM + 1;
	}

	return d;
}

void FImprime(Fila *f){

	printf("\n================\nFila Contem:\n");
	for(int i=f->first-1; i<f->last-1; i++)
		printf("%d\t", f->vet[i]);
	printf("\n================\n");

}

int isEmpty(Fila *f){
	if(f->first == f->last)
    	return 1;
 	 else
    	return 0;
}




