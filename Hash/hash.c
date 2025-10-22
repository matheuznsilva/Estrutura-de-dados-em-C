#include <stdlib.h>																								
#include <stdio.h>
#include <string.h>
#include "ListaDinEncad.h"
#include "hash.h"
#define MAX 20

// =============== DEFINIÇÃO DO TIPO HASH ===============

struct hash{
	int qtd, TABLE_SIZE;
	struct word **itens;
};


// =============== CRIAÇÃO DA TABELA DE HASH ===============

Hash* criaHash(int TABLE_SIZE){
	Hash* ha = (Hash*)malloc(sizeof(Hash));		// Alocação de memoria para a tabela Hash
	if(ha != NULL){		// Confere se a alocação funcionou
		int i;		// Declaração de variável local
		ha->TABLE_SIZE = TABLE_SIZE;		// Faz o campo que guarda o tamanho da hash receber o tamanho informado pelo usuário
		ha->itens = (struct word**)malloc(TABLE_SIZE * sizeof(struct word*));		// Alocação de memoria para guardar os itens na  tabela	
		if(ha->itens == NULL){		// Confere se a alocação funcionou
			free(ha);		// Se não funcionar o ponteiro é apagado
			return NULL;		// Retorna-se NULL para informar que deu erro na alocação
		}
		ha->qtd = 0;		// Faz o campo que guarda a quantidade de elementos apontar para 0
		for(i=0; i<ha->TABLE_SIZE; i++){		// Laço de repetição para inicializar todas as posições da tabela com NULL
			ha->itens[i] = NULL;		// Atribui NULL para todas as posições da tabela
		}
	}
	return ha;		// Retorna o ponteiro da tabela
}


// =============== DESTRUIINDO A TABELA DE HASH ===============

void liberaHash(Hash* ha){ 
	if(ha != NULL){		// Confere se a tabela existe
		int i;		// Declaração de variavel local
		for(i=0; i<ha->TABLE_SIZE; i++){		// Laço de repetição para percorrer a tabela
			if(ha->itens[i] != NULL){		// Confere se exites elementos na posição i
				free(ha->itens[i]);		// Caso exista o ponteiro é liberado
			}
		}		
		free(ha->itens);		// O Ponteiro para itens é liberado
		free(ha);		// O Ponteiro principal é liberado
	}
}


// =============== FUNÇÃO HASHING ===============

int chaveDiv(int chave, int TABLE_SIZE){		// Função Hashing utilizando metodo da divisão
	return(chave & 0x7FFFFFFF) % TABLE_SIZE;		// O 0x7FFFFFFF é utilizado para eliminar o bit de sinal
}

int valorString(char *str){		// Função Hashing utilizando string como chave
	int i, valor = 7;		// Declaração de variáveis locais
	int TAM = strlen(str);		// Declaração da variável tam, que recebe a quantidade de caracteres existentes na string
	
	for(i=0; i < TAM; i++){		// Laço de repetição para calcular o valor da chave 
		if(str[i] != ' ' && str[i] != '.' && str[i] != ',' && str[i] != '!'){
			valor = 31 * valor + (int) str[i];		// 
		}
	}
	return valor;		// Retorna o valor da chave
}


// =============== INSERÇÃO NA HASH ===============

int insere_Hash(Hash* ha, struct arquivo ar){ 		// função de inserção na hash
	if (ha == NULL || ha->qtd == ha-> TABLE_SIZE){
		return 0;
	}
	int chave = valorString(ar.str);
	int aux;
	int pos = chaveDiv(chave, ha->TABLE_SIZE);
	struct word* novo;
	printf("\n");
	
	if(ha->itens[pos] == NULL){
	
		Lista *li; 
		li = criar_lista();
		aux = insere_lista_final(li, ar);
		if(aux == 0){
			printf("Não Inserido\n");
			printf("\n-------------------");
		} else if(aux == 1){
			fputs(ar.str,stdout);
			printf("\nInserido");
			printf("\nposição %d", pos);
			printf("\n-------------------");
		}
		novo = (struct word*) malloc(sizeof(struct word));
		novo->li = li;
		novo->contador = 1;

		ha->itens[pos] = novo;
		ha->qtd++;
		return 1;
	} else{
		aux = insere_lista_final(ha->itens[pos]->li, ar);
		ha->qtd++;
		if(aux == 0){
			printf("Não Inserido\n");
			printf("\n-------------------");
		} else if(aux == 1){
			fputs(ar.str,stdout);
			printf("\nInserido");
			printf("\nposição %d", pos);
			printf("\n-------------------");
		}
	}
	return 1;
}


// =============== BUSCA NA HASH ===============

int busca_Hash(Hash* ha, struct arquivo ar){ 		// função de inserção na hash
	if (ha == NULL){
		return 0;
	}
	int chave = valorString(ar.str);
	int aux;
	int pos = chaveDiv(chave, ha->TABLE_SIZE);
	struct word* novo;

	if(ha->itens[pos] == NULL){ // confere se tem algum elemento na lista
		return 0;
	}

	novo = ha->itens[pos];
	Lista *no = novo->li;

	if(strcmp((*no)->dados.str, ar.str)==0){
		printf("PALAVRA ENCONTRADA!\n");
		printf("POSIÇÃO: %d\n", pos);
		return 1;
	}
	
	return 0;
}


// =============== IMPRESSÃO DA HASH ===============

int imprime_Hash(Hash* ha){
	if (ha == NULL){
		printf("TABELA NÃO ENCONTRADA");
		return 0;
	} else{

		for(int i=0; i<ha->TABLE_SIZE; i++){
			if(ha->itens[i] != NULL){
				imprime_lista(ha->itens[i]->li);
			}
		}
	}
	return 1;
}

