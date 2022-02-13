#ifndef FILA_H 
#define FILA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXTAM 10

typedef struct Fila{
	int vet[MAXTAM];
	int first;
	int last;
}Fila;


void FFVazia(Fila *f);
void Enfileira(Fila *f, int d);
int Desenfileira(Fila *f);
void FImprime(Fila *f);
int isEmpty(Fila *f);

#endif