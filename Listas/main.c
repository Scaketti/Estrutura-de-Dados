#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){

	TipoListaSimples *L1 = NULL;
	TipoListaSimples *L2 = NULL;
	TipoListaSimples *L3 = NULL;
	TipoListaSimples *L4 = NULL;

	//Pesquisa No LISTA VAZIA
	L2 = pesquisaNo(L1, 2);
	L2 = pesquisaNo(L1, 8);
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
	L4 = pesquisaNo(L1, 2);
	printf("\npesquisaNo--------------------\nPesquisa: %p\n", L4);
	L4 = pesquisaNo(L1, 1);
	printf("Pesquisa: %p\n\n", L4);

	//ATUALIZA VALOR
	atualizaValor(L1, 5);
	printf("atualizaValor-------------------\n");
	printaLista(L1);

	//INSERE FIM LISTA
	L4 = insereFimListaSimples(&L1, 3, 3);
	L4 = insereFimListaSimples(&L1, 4, 4);
	printf("\nInsere FIMLISTA---------------\n");
	printaLista(L1);

	L2 = copiaListas(L1);
	printf("\nCopiaListas-------------------\n");
	printaLista(L2);

	liberaNos(&L2);
	liberaNos(&L1);
	insereInicioListaSimples(&L1, 4, 1);
	insereInicioListaSimples(&L1, 2, 8);
	insereInicioListaSimples(&L1, 1, 5);
	
	insereInicioListaSimples(&L2, 1, 1);
	insereInicioListaSimples(&L2, 2, 8);
	insereInicioListaSimples(&L2, 5, 5);
	printf("\nInserindoL2-------------------\n");
	printaLista(L2);

	printf("\nInterseçãoListas--------------\n");
	L3 = intersecaoListas(L1, L2);
	printaLista(L3);

	transplantaNo(&L1, &L2);
	printf("\ntransplantaNo-----------------\n");
	printaLista(L1);
	printf("\n------------------------------\n");
	printaLista(L2);

	//REMOVE PRIMEIRO NO
	removePrimeiroNo(&L1);
	printf("\nRemove PrimeiNó---------------\n");
	printaLista(L1);

	//REMOVE ULTIMO NO
	printf("\nRemove UltimoNó---------------\n");
	removeUltimoNo(&L1);
	printaLista(L1);

	//Remove\insere
	insereInicioListaSimples(&L1, 2, 8);
	insereInicioListaSimples(&L1, 1, 5);
	printf("\nRemove/insereL1-----------------\n");
	insereRemove(&L1, &L3);
	printaLista(L1);
	printf("\nRemove/insereL3-----------------\n");
	printaLista(L3);

	//LIBERA TODOS OS NOS
	printf("\nLiberaNó----------------------\n");
	liberaNos(&L3);
	printaLista(L3);

	
	
	return 0;
}