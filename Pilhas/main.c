#include "bib.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

	int selec, podeSair = 1;

	pilha *pont = NULL;
	int chave = 1;
	char nome[50];

	do{
		printf("Selecione uma Opção:\n1- Inserir na pilha.\n2- Remover na pilha.\n");
		scanf("%d", &selec);

		switch(selec){
			case 1:
				printf("Digite um nome\n");
				scanf("%s", nome);

				inserePilha(&pont, chave++, nome);

				podeSair = 2;
				break;

			case 2:
				removePilha(&pont);

				podeSair = 2;
				break;

			default:
				printf("Digite uma opção válida!\n");
		}

		if(podeSair == 2){
			printf("Deseja fazer outra operação? (1-Sim / 0-Não)\n");
			scanf("%d", &podeSair);
		}
	}while(podeSair == 1);


	return 0;
}
