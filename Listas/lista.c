#include "lista.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

TipoListaSimples *insereInicioListaSimples(TipoListaSimples **prim, TipoChave chave, TipoValor valor){

	assert(prim);

	TipoListaSimples *aux = (TipoListaSimples *) malloc(sizeof(TipoListaSimples));

	if(aux != NULL){
		if(*prim == NULL){
			aux -> chave = chave;
			aux -> valor = valor;
			aux -> prox = NULL;
			*prim = aux;
		}else{
			aux -> chave = chave;
			aux -> valor = valor;
			aux -> prox = *prim;
			*prim = aux;
		}
	}else return NULL;
}

void atualizaValor(TipoListaSimples *prim, TipoValor novoValor){

	if(prim != NULL){
		prim->valor = novoValor;
	}
}

void removePrimeiroNo(TipoListaSimples **prim){

	assert(prim);

	if(*prim != NULL){
		TipoListaSimples *aux = (*prim)->prox;
		free(*prim);

		*prim = aux;
	}
}

TipoListaSimples *pesquisaNo(TipoListaSimples *prim, TipoChave chave){

	if(prim != NULL){
		do{
			if(prim->chave == chave) return prim;
			else{
				prim = prim->prox;
			}

		}while(prim != NULL);
	}
	return NULL;
}

TipoListaSimples *insereFimListaSimples(TipoListaSimples **prim, TipoChave chave, TipoValor valor){
  //verifica se o ponteiro para ponteiro esta vazio (não pode estar)
	assert(prim);

	TipoListaSimples *aux = *prim;
  
  //verifica se existe o primeiro nó
	if(aux == NULL){
		aux = (TipoListaSimples *) malloc(sizeof(TipoListaSimples));
    
    //verifica se conseguiu alocar
		if(aux != NULL){
			aux->chave = chave;
			aux->valor = valor;
			aux->prox = NULL;
			*prim = aux;
			return *prim;
		}
	}
  //se não existir ele percorre a lista até que encontre o aux->prox == NULL, então ele aloca outro nó
	else{
    //laço para movimentar na lista
		do{
			aux = aux->prox;
		}while((aux->prox) != NULL);
    
    //aloca o nó no campo prox do então último nó
		(aux->prox) = (TipoListaSimples *) malloc(sizeof(TipoListaSimples));
    
    //verifica se conseguiu alocar
		if((aux->prox) != NULL){
			(aux->prox)->chave = chave;
			(aux->prox)->valor = valor;
			(aux->prox)->prox = NULL;
			return (aux->prox);
		}
	}
  //no final caso nada der certo ele retorna NULL
	return NULL;
}

void removeUltimoNo(TipoListaSimples **prim){

	assert(prim);

	TipoListaSimples *auxAnt = NULL;
	TipoListaSimples *auxAtual = *prim;

	if(auxAtual == NULL){
		return;
	}
	else{
		do{
			auxAnt = auxAtual;
			auxAtual = auxAtual->prox;
		}while(auxAtual->prox != NULL);

		auxAnt->prox = NULL;
		free(auxAtual);
	}
}

void printaLista(TipoListaSimples *prim){

	TipoListaSimples *aux = prim;

	if(aux == NULL){
		printf("Lista Vazia!\n");
	}

	while(aux != NULL){
		printf("Chave: %d\tValor:%d\n", aux->chave, aux->valor);
		aux = aux->prox;
	}
}

//INACABADO
void removeNo(TipoListaSimples *prim, TipoChave chave){

	if(prim == NULL){
		return;
	}
	else{
		do{
			if(prim->chave == chave){

			}
			else{
				prim = prim->prox;
			}

		}while(prim != NULL);
	}
	printf("Não existe a chave na lista!\n");
}

void liberaNos(TipoListaSimples **prim){
	assert(prim);

	TipoListaSimples *auxAnt = *prim;
	TipoListaSimples *auxAtual = *prim;

	if(auxAtual != NULL){
		do{
			auxAnt = auxAtual;
			auxAtual = auxAtual->prox;
			free(auxAnt);
		}while(auxAtual->prox != NULL);

		free(auxAtual);
		*prim = NULL;
	}
}

//INACABADO
TipoListaSimples *copiaListas(TipoListaSimples *prim){
	TipoListaSimples *ponteiroPrim = NULL;
	TipoListaSimples *ponteiroAtual = NULL;

	ponteiroAtual = (TipoListaSimples *) malloc(sizeof(TipoListaSimples));
	ponteiroAtual->chave = prim->chave;
	ponteiroAtual->valor = prim->valor;
	ponteiroAtual->prox = NULL;
	ponteiroPrim = ponteiroAtual;

	do{
		ponteiroAtual->prox = (TipoListaSimples *) malloc(sizeof(TipoListaSimples));
		ponteiroAtual->chave = prim->chave;
		ponteiroAtual->valor = prim->valor;
		ponteiroAtual->prox = NULL;
		ponteiroAtual = ponteiroAtual->prox;

		prim = prim->prox;

	}while(prim != NULL);

	return ponteiroPrim;
}

//INACABADO
TipoListaSimples *intersecaoListas(TipoListaSimples *prim1, TipoListaSimples *prim2){
}

//INACABADO
void insereRemove(TipoListaSimples **primLista1, TipoListaSimples **primLista2){
}

//INACABADO
void transplantaNo(TipoListaSimples **primLista1, TipoListaSimples **primLista2){
	assert(primLista1);
	assert(primLista2);

	TipoListaSimples *aux1Ant = NULL;
	TipoListaSimples *aux1Atual = *primLista1;
	TipoListaSimples *aux2 = *primLista2;

	if(aux1Atual != NULL){
		do{
			aux1Ant = aux1Atual;
			aux1Atual = aux1Atual->prox;
		}while(aux1Atual->prox != NULL);

		if(aux2 != NULL){
			do{
				aux2 = aux2->prox;
			}while(aux2->prox != NULL);
			aux2->prox = aux1Ant->prox;
		}else{
			aux2 = aux1Ant->prox;
		}
	}else{
		printf("Não existe nos na primeira lista!\n");
		return;
	}

	
	free(aux1Atual);
	aux1Ant->prox = NULL;
}