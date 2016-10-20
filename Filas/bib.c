#include "bib.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


void insereFila(fila **pont, int chave, char *nome){
	assert(pont);

	printf("%s\n", nome);
	if(*pont == NULL){
		*pont = (fila *) malloc(sizeof(fila));
		if(*pont != NULL){
			(*pont)->chave = chave;
			strcpy((*pont)->nome, nome);
			(*pont)->prox = *pont;
		}
	}else{
		fila *aux = (fila *) malloc(sizeof(fila));
		aux->chave = chave;
		strcpy(aux->nome, nome);
		aux->prox = (*pont)->prox;
		(*pont)->prox = aux;
	}
	printaFila(*pont);
}

void removeFila(fila **pont){
	assert(pont);

	if(*pont == NULL) return;

	fila *pontPrim = (*pont)->prox;
	fila *pontPenult = (*pont)->prox;

	if(pontPrim->prox != pontPrim){
		while(pontPenult->prox != *pont){
			pontPenult = pontPenult->prox;
		}
		free(*pont);
		*pont = pontPenult;
		pontPenult->prox = pontPrim;
	}else{
		free(*pont);
		*pont = NULL;
	}
	printaFila(*pont);
}

void printaFila(fila *pont){
	if(pont == NULL){
		printf("Fila Vazia!\n");
	}else{
		fila *aux = pont;
		while(aux->prox != pont){
			aux = aux->prox;
			printf("Chave: %d\tNome: %s\tEndereço: %p\n", aux->chave, aux->nome, aux);
		}

		printf("Chave: %d\tNome: %s\tEndereço: %p\n", pont->chave, pont->nome, pont);
	}
}