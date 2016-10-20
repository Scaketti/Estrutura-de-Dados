#include "bib.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


void inserePilha(pilha **pont, int chave, char nome[]){
	assert(pont);

	pilha *aux = (pilha *) malloc(sizeof(pilha));

	if(aux != NULL){
		if(*pont == NULL){
			aux->chave = chave;
			strcpy(aux->nome, nome);
			aux->prox = NULL;
			*pont = aux;
		}else{
			aux->chave = chave;
			strcpy(aux->nome, nome);
			aux->prox = *pont;
			*pont = aux;
		}
	}

	printaPilha(*pont);
}

void removePilha(pilha **pont){
	assert(pont);

	if(*pont != NULL){
		pilha *aux = (*pont)->prox;
		free(*pont);

		*pont = aux;
	}
	printaPilha(*pont);
}

void printaPilha(pilha *pont){
	if(pont == NULL){
		return;
	}

	printf("Chave: %d\tNome: %s\tEndereço: %p\n", pont->chave, pont->nome, &pont);

	printaPilha(pont->prox);
}