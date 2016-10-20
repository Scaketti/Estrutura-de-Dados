#include "lista.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

	return aux;
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
	if(prim == NULL){
		printf("Lista Vazia!\n");
	}

	while(prim != NULL){
		printf("Chave: %d\tValor:%d\n", prim->chave, prim->valor);
		prim = prim->prox;
	}
}

//INACABADO
void removeNo(TipoListaSimples *prim, TipoChave chave){

	if(prim == NULL) printf("Lista Vazia!\n");
	TipoListaSimples *ant = NULL;

	while(prim->prox != NULL){
		if(prim->chave == chave){
			ant->prox = prim->prox;
		}
		ant = prim;
		prim = prim->prox;
	}
	free(prim);
}

void liberaNos(TipoListaSimples **prim){
	assert(prim);

	TipoListaSimples *auxAnt = NULL;
	TipoListaSimples *auxAtual = *prim;

	if(auxAtual != NULL){
		while(auxAtual->prox != NULL){
			auxAnt = auxAtual;
			auxAtual = auxAtual->prox;
			free(auxAnt);
		}
		free(auxAtual);
		*prim = NULL;
	}
}

TipoListaSimples *copiaListas(TipoListaSimples *prim){
	TipoListaSimples *ponteiroPrim = NULL;
	TipoListaSimples *ponteiroAtual = NULL;

	ponteiroAtual = (TipoListaSimples *) malloc(sizeof(TipoListaSimples));
	memcpy(ponteiroAtual, prim, sizeof(TipoListaSimples));
	ponteiroAtual->prox = NULL;
	ponteiroPrim = ponteiroAtual;

	prim = prim->prox;

	while(prim != NULL){
		ponteiroAtual->prox = (TipoListaSimples *) malloc(sizeof(TipoListaSimples));
		ponteiroAtual = ponteiroAtual->prox;
		memcpy(ponteiroAtual, prim, sizeof(TipoListaSimples));
		ponteiroAtual->prox = NULL;

		prim = prim->prox;

	}

	return ponteiroPrim;
}

TipoListaSimples *intersecaoListas(TipoListaSimples *prim1, TipoListaSimples *prim2){

	int qtdNos = 1;
	TipoListaSimples *novaLista = NULL;
	TipoListaSimples *novaPrim = NULL;
	TipoListaSimples *auxPrim2 = prim2;

	if(prim1 == NULL)return NULL;

	while(prim1 != NULL){
		while(prim2 != NULL){
			if((prim1->valor == prim2->valor)){
				if(qtdNos == 1){
					novaLista = (TipoListaSimples *) malloc(sizeof(TipoListaSimples));
					novaPrim = novaLista;
					novaLista->valor = prim1->valor;
					novaLista->chave = qtdNos++;
					novaLista->prox = NULL;
				}else{
					novaLista->prox = (TipoListaSimples *) malloc(sizeof(TipoListaSimples));
					novaLista = novaLista->prox;
					novaLista->valor = prim1->valor;
					novaLista->chave = qtdNos++;
					novaLista->prox = NULL;
				}
			}
			prim2 = prim2->prox;
		}
		prim1 = prim1->prox;
		prim2 = auxPrim2;
	}
	return novaPrim;
}

void insereRemove(TipoListaSimples **primLista1, TipoListaSimples **primLista2){

	assert(primLista1);
	assert(primLista2);

	TipoListaSimples *aux1 = *primLista1;
	TipoListaSimples *ant2 = NULL;
	TipoListaSimples *atual2 = *primLista2;

	if(*primLista2 == NULL) return;


	while(aux1->prox != NULL){
		aux1 = aux1->prox;
	}
	while(atual2->prox != NULL){
		ant2 = atual2;
		atual2 = atual2->prox;
	}

	aux1->prox = (TipoListaSimples *) malloc(sizeof(TipoListaSimples));
	memcpy(aux1->prox, atual2, sizeof(TipoListaSimples));
	(aux1->prox)->prox = NULL;

	if(*primLista1 == NULL) *primLista1 = aux1->prox;

	free(atual2);
	ant2->prox = NULL;
}

void transplantaNo(TipoListaSimples **primLista1, TipoListaSimples **primLista2){
	assert(primLista1);
	assert(primLista2);

	TipoListaSimples *antPrim = *primLista1;
	TipoListaSimples *atualPrim1 = *primLista1;

	TipoListaSimples *atualPrim2 = *primLista2;

	if(*primLista1 == NULL){
		printf("Não existe nós.\n");
		return;
	}
	while(atualPrim1->prox != NULL){
		antPrim = atualPrim1;
		atualPrim1 = atualPrim1->prox;
	}
	while(atualPrim2->prox != NULL){
		atualPrim2 = atualPrim2->prox;
	}
	atualPrim2->prox = atualPrim1;
	antPrim->prox = NULL;
}