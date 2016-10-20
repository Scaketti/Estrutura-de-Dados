#ifndef BIB_H
#define BIB_H

struct tipoNoFila{
	int chave;
	char nome[50];
	struct tipoNoFila *prox;
};
typedef struct tipoNoFila fila;

void insereFila(fila **pont, int chave, char *nome);
void removeFila(fila **pont);
void printaFila(fila *pont);

#endif