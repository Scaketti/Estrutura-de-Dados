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

	assert(prim);

	if(prim != NULL){
		prim->valor = novoValor;
	}
}

//DUVIDA AQUI!!!!!!
void removePrimeiroNo(TipoListaSimples **prim){

	if(*prim != NULL){
		TipoListaSimples *aux = (**prim).prox;
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

TipoListaSimples * insereFimListaSimples(TipoListaSimples **prim, TipoChave chave, TipoValor valor){
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
		free(auxAnt);
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

void removeNo(TipoListaSimples *prim, TipoChave chave){

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