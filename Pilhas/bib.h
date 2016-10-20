#ifndef BIB_H
#define BIB_H

struct tipoNoPilha{
	int chave;
	char nome[50];
	struct tipoNoPilha *prox;
};
typedef struct tipoNoPilha pilha;

void inserePilha(pilha **pont, int chave, char nome[]);
void removePilha(pilha **pont);
void printaPilha(pilha *pont);

#endif
