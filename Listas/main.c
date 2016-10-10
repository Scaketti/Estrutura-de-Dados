#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){

	TipoListaSimples *L1 = NULL;

	//Pesquisa No LISTA VAZIA
	TipoListaSimples *L2 = pesquisaNo(L1, 2);
	printf("pesquisaNo----------------------\nPesquisa: %p\n\n", L2);

	//INSERE INICIO: LISTA VAZIA
	insereInicioListaSimples(&L1, 1, 1);
	printf("insereInicioListaSimples--------\n");
	printaLista(L1);

	//INSIRE INICIO: LISTA !VAZIA
	insereInicioListaSimples(&L1, 2, 2);
	printf("\ninsereInicioListaSimples------\n");
	printaLista(L1);

	//Pesquisa No LISTA !VAZIA
	L2 = pesquisaNo(L1, 2);
	printf("\npesquisaNo--------------------\nPesquisa: %p\n", L2);
	L2 = pesquisaNo(L1, 1);
	printf("Pesquisa: %p\n\n", L2);

	//ATUALIZA VALOR
	atualizaValor(L1, 3);
	printf("atualizaValor-------------------\n");
	printaLista(L1);

	//INSERE FIM LISTA
	L2 = insereFimListaSimples(&L1, 3, 3);
	L2 = insereFimListaSimples(&L1, 4, 4);
	printf("\nInsere FIMLISTA---------------\n");
	printaLista(L1);

	//L2 = copiaListas(L1);
	//printf("\nCopiaListas-------------------\n");
	//printaLista(L2);

	//transplantaNo(&L1, &L2);
	//printf("\ntransplantaNo------------------\n");
	//printaLista(L1);
	//printaLista(L2);

	//REMOVE PRIMEIRO NO
	removePrimeiroNo(&L1);
	printf("\nRemove PrimeiNó---------------\n");
	printaLista(L1);

	//REMOVE ULTIMO NO
	printf("\nRemove UltimoNó---------------\n");
	removeUltimoNo(&L1);
	printaLista(L1);

	//LIBERA TODOS OS NOS
	printf("\nLiberaNó----------------------\n");
	liberaNos(&L1);
	printaLista(L1);
	
	return 0;
}