#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h" //inclui os prototipos 

//Definição do tipo lista

struct element{
	struct data DATA;		// campo do tipo aluno que recebe o dado a ser armazenado
	struct element *next;		// ponteiro do tipo elemento que indica o proximo elemento 
};

typedef struct element Elem;		// definição de um nome padrão para a struct elemento
// ==========================================================

// FUNÇÃO DE CRIAÇÃO DA LISTA

List* create_list(){
	List *LI = (List*) malloc(sizeof(List));		// alocação de memoria para a Lista
	
	if(LI != NULL){		// confere se a lista foi criada
		*LI = NULL;	// caso criada faz o ponteiro apontar para null
		printf("\nLISTA CRIADA\n"); // confirmação q a lista foi criada
	}
	return LI;		// retorna o ponteiro li;
}
// ==========================================================

// FUNÇÃO QUE DESTROI A LISTA

void free_list(List* LI){
	if(LI!= NULL){		// verifica se a lista existe
		Elem* NO;		// declaração de um ponteiro auxiliar
		while((*LI)!=NULL){		// loop para percorrer a lista com condição de para ser o final da lista
			NO = *LI;		// ponteiro auxiliar recebe a posição atual do ponteiro li
			*LI = (*LI)->next;		// li recebe a posição do proximo elemento 
			free(NO);		// apaga o nó(elemento) da lista
		}
		free(LI);	// libera o ponteiro	
	}	
}

// ==========================================================

// FUNAÇÃO QUE RETORNA O TAMANHO DA LISTA

int size_list(List* LI){	
	if(LI == NULL){		// confere se a lista existe
		return 0;		// caso não exista retorna -1 informando o erro
	}
	int count = 0;		// declaração de variável local(contador) para armazenar a quantidade de elementos presentes na lista
	Elem* NO = *LI;		// declaração e atribuição do ponteiro auxiliar para percorrer a lista
	while(NO != NULL){		// loop para percorrer a lista com condição de para ser o final da lista
		count++;		// incremento do contador
		NO = NO->next;		// ponteiro auxiliar recebe a proxima posição da lista
	}
	return count;		// retorna o contador
}
// ==========================================================

// FUNÇÃO QUE RETORNA SE A LISTA ESTA CHEIA

int full_list(List* LI){		// função que retorna se a lista está cheia
	return 0;		// tendo em vista q a lista só estará cheia se nn houver mais memoria, ela sempre retorna 0
}
// ==========================================================

// FUNÇÃO QUE RETORNA SE A LISTA ESTA VAZIA OU NÃO

int empty_list(List* LI){
	if(LI == NULL){		// confere se a lista existe
		return 1;		// se a lista não existir retorna 1
	}
	if(*LI == NULL){	// confere se a lista está vazia
		return 1;		// caso esteja retorna 1
	}
	return 0;		// caso ja exista algum elemento na lista retorna 0
}
// ==========================================================

// FUNÇÕES DE INSERÇÃO

int insert_start_list(List* LI, struct data DT){		//  inserção no inicio da lista
	if(LI == NULL){ 	// confere se a lista existe
		return 0;		// caso não exista não ocorre a inserção
	}
	Elem* NO;		// delcaração de um ponteiro auxiliar
	NO = (Elem*) malloc(sizeof(Elem));		// alocação de memoria para um novo elemento
	if(NO == NULL){		// confere se ocorreu a alocação
		return 0;		// caso não tenha ocorrido retorna 0
	}		// caso tenha ocorrido executa os comandos abaixo
	NO->DATA = DT;		// o campo dados do novo elemento recebe os dados digitados pelo usuário
	NO->next = (*LI);	// o ponteiro prox recebe endereço do elemento ja existente, ou seja, passa a apontar para o agora proximo elemento da lista
	*LI = NO;		// a posição inicial recebe o agora primeiro elemento
	return 1;
}

int insert_end_list(List* LI, struct data DT){		//  inserção ao final da lista
	if(LI == NULL){		// confere se a lista existe
		return 0;		// caso não exista não ocorre a inserção
	}
	Elem* NO;		// delcaração de um ponteiro auxiliar
	NO = (Elem*) malloc(sizeof(Elem));		// alocação de memoria para um novo elemento
	if(NO == NULL){		// confere se ocorreu a alocação
		return 0;		// caso não tenha ocorrido retorna 0
	}
	NO->DATA = DT;		// o campo dados do novo elemento recebe os dados digitados pelo usuário
	NO->next = NULL;	// o ponteiro prox do novo elemento passa a apontar para null

	if((*LI) == NULL){		// confere se é uma lista vazia
		*LI = NO;		// caso seja atribuimos o novo elemento ao inicio da lista
	} else {		// caso não seja percorremos a lista até encontrar o ultimo elemento
		Elem *aux;		// declaração de um outro ponteiro auxiliar
		aux = *LI;		// ponteiro auxiliar recebe a posição inicial da lista
		while(aux->next != NULL){		// loop para percorrer a lista tendo como condição de parada o final da lista
			aux = aux->next;		// ponteiro auxiliar recebe o endereço do proximo elemento
		}
		aux->next = NO;		// ao final do loop o ponteiro prox que antes apontava pra null passa a apontar para o novo elemento
	}
	return 1;
}

int insert_sorted_list(List* LI, struct data DT){		//  inserção ordenada
	if(LI == NULL){		// confere se a lista existe
		return 0;		// caso não exista não ocorre a inserção
	}
	Elem* NO;		// delcaração de um ponteiro auxiliar
	NO = (Elem*) malloc(sizeof(Elem));		// alocação de memoria para um novo elemento
	if(NO == NULL){		// confere se ocorreu a alocação
		return 0;		// caso não tenha ocorrido retorna 0
	}
	NO->DATA = DT;		// o campo dados do novo elemento recebe os dados digitados pelo usuário
	if((*LI) == NULL){		// confere se é uma lista vazia
		NO->next == NULL;	// caso seja o ponteiro prox do novo elemento passa a apontar para null
		*LI = NO;		// atribui o novo elemento ao inicio da lista
		return 1;
	} else{		// se não for uma lista vazia, iremos percorre a lista até encontrar um numero de matricula maior que o cadastrado pelo usuário
		Elem *prev, *current = *LI;		// declaração de ponteiros auxiliares e atribuição do ponteiro atual recebendo a primeira posição da lista
		while(current != NULL && current->DATA.num < DT.num){		// loop para percorrer a lista tendo como ponto de parada o final da lista e a matricula do elemento presente na lista ser maior que a do elemento a ser inserido 
			prev = current;		// atribui ao ponteiro ant a posição do elemento apontado por atual
			current = current->next;		// atual recebe a posição do proximo elemento da lista
		}
		if(current == *LI){		// confere se a posição apontada por atual foi a primeira posição da lista 
			NO->next = (*LI);		// caso seja o ponteiro prox do novo elemento passa a apontar para o antigo primeiro elemento da lista
			*LI = NO;		// li passa agora a apontar para o novo elemento
		} else{		// caso não seja o ponteiro executa os comando a baixo
			NO->next = current;		// o ponteiro prox do novo elemento passa a apontar para a posição do atual(elemento que o ponteiro atual aponta)
			prev->next = NO;		// o ponteiro prox do elemento apontado por ant passa a apontar para a posição do novo elemento
		}
		return 1;
	}
}
// ==========================================================

// FUNÇÕES DE REMOÇÃO

int remove_start_list(List* LI){		//  remoção no inicio da lista
	if(LI == NULL){		// confere se a lista existe
		printf("\nLISTA NÃO EXISTENTE\n");		// caso não exista informa que a operação não pode ser processada
		return 0;
	}
	if((*LI) == NULL){		//confere se existe elementos na lista
		printf("\nLISTA NÃO POSSUI ELEMENTOS CADASTRADOS\n");		// caso não exista elementos informa que a operação não pode ser processada
		return 0;
	}
	Elem *NO = *LI;		// declaração e atribuição do ponteiro no apontando para o primeiro elemento da lista
	*LI = NO->next;		// ponteiro principal recebe o proximo elemento da lista
	free(NO);		// apaga o elemento (libera a memoria utilizada pelo elemento a ser apagado)
	return 1;
}

int remove_end_list(List* LI){		// remoção no final da lista
	if(LI == NULL){		// confere se a lista existe
		printf("\nLISTA NÃO EXISTENTE\n");		// caso não exista informa que a operação não pode ser processada
		return 0;
	}
	if((*LI) == NULL){		// confere se existe elementos na lista
		printf("\nLISTA NÃO POSSUI ELEMENTOS CADASTRADOS\n");		// caso não exista elementos informa que a operação não pode ser processada
		return 0;
	}
	Elem *prev, *NO = *LI;		// declaração de ponteiros auxiliares e atribuição do ponteiro no apontando para o primeiro elemento da lista
	while(NO->next != NULL){		// loop para percorrer a lista tendo como condição de parada o final da lista
		prev = NO;		// atribui ao ponteiro ant a posição do elemento apontado por no
		NO = NO->next;		// ponteiro no recebe a posição do proximo elemento da lista
	}
	if(NO == (*LI)){		// confere se o nó é igual ao inicio da lista
		*LI = NO->next;		// se for o ponteiro li passa a apontar para o proximo elemento
	} else{
		prev->next = NO->next;		// se não for o ponteiro prox do anterior passa a apontar para o proximo elemento
	}
	free(NO);		// apaga o elemento (libera a memoria utilizada pelo elemento a ser apagado)
	return 1;
}

int remove_list(List* LI, int num){		// remoção de acordo com a matricula
	if(LI == NULL){		// confere se a lista existe
		printf("\nLISTA NÃO EXISTENTE\n");		// caso não exista informa que a operação não pode ser processada
		return 0;
	}
	if((*LI) == NULL){		//confere se existe elementos na lista
		printf("\nLISTA NÃO POSSUI ELEMENTOS CADASTRADOS\n");		// caso não exista elementos informa que a operação não pode ser processada
		return 0;
	}
	Elem *prev, *NO = *LI;		// declaração de ponteiros auxiliares e atribuição do ponteiro no apontando para o primeiro elemento da lista
	while(NO != NULL && NO->DATA.num != num){		// loop para percorrer a lista tendo como ponte de parada o fim da lista ou ter encontrado a matricula procurada 
		prev = NO;		// atribui ao ponteiro ant a posição do elemento apontado por no
		NO = NO->next;		// ponteiro no recebe a posição do proximo elemento da lista
	}
	if(NO == NULL){		// caso o numero da matricula não seja encontrado 
		printf("\nA MATRICULA PROCURADA NÃO CONSTA NO CADASTRO\n");
		return 0;
	}
	if(NO == *LI){		// confere se o nó é igual ao inicio da lista
		*LI = NO->next;		// se for o ponteiro li passa a apontar para o proximo elemento
	} else{
		prev->next = NO->next;		// se não for o ponteiro prox do anterior passa a apontar para o proximo elemento
	}
	free(NO);		// apaga o elemento (libera a memoria utilizada pelo elemento a ser apagado)
	return 1;
}
// ==========================================================

// FUNÇÕES DE BUSCA

int search_list_pos(List* LI, int num, struct data *DT){		// busca de acordo com a posição
	if(LI == NULL || num <= 0){		// confere se a lista existe ou se a posição procurada é menor ou igual a 0
		return 0;
	}
	Elem *NO = *LI;		// declaração e atribuição do ponteiro no apontando para o primeiro elemento da lista
	int i = 1;		// declaração e inicialização de variável local que servirá como contador
	while(NO != NULL && i<num){		// loop para percorrer a lista tendo como condição de parada o fim da lista ou o contador ser maior que a posição procurada
		NO = NO->next;		// ponteiro no recebe a posição do proximo elemento da lista
		i++;		// incremento do contador
	}
	if(NO == NULL){		// caso a posição desejada não seja encontrada
		printf("\nELEMENTO NÃO ENCONTRADO\n");	
		return 0;
	} else{		// caso seja encontrada
		*DT = NO->DATA; 		// retorna o ponteiro para struct aluno onde serão guardadas as informações
		return 1;
	}
}

int search_list_num(List* LI, int num, struct data *DT){		// busca de acordo com a matricula
	if(LI == NULL){		// confere se a lista existe
		return 0;
	}
	Elem *NO = *LI;		// declaração e atribuição do ponteiro no apontando para o primeiro elemento da lista
	while(NO != NULL && NO->DATA.num != num){		// loop para percorrer a lista tendo como condição de parada o fim da lista ou ter encontrado a matricula procurada
		NO = NO->next;		// ponteiro no recebe a posição do proximo elemento da lista		
	}
	if(NO == NULL){		// caso a matricula desejada não seja encontrada
		printf("\nELEMENTO NÃO ENCONTRADO\n");		// caso não encontre o elemento informa que o mesmo não existe
		return 0;
	} else{
		*DT = NO->DATA; 		// retorna o ponteiro para struct aluno onde serão guardadas as informações
	}
	return 1;
}
// ==========================================================

// FUNÇÃO DE IMPRESSÃO DA LISTA

void print_list(List* LI){
	if(LI == NULL){		// confere se a lista existe
		printf("\nLISTA NÃO EXISTENTE\n");		// caso não exista informa que a operação não pode ser processada
	}
	Elem *NO = *LI;		// declaração e atribuição do ponteiro no apontando para o primeiro elemento da lista
	while(NO != NULL){		// loop para deslocamento na lista 
		printf("\nNAME: %s", NO->DATA.name);		// imprime o nome do aluno
		printf("NUMBER: %d", NO->DATA.num);		// imprime a matricula do aluno
		printf("\nNota 1: %.1f", NO->DATA.n1);		// imprime a 1ª nota do aluno
		printf("\nNota 2: %.1f", NO->DATA.n2);		// imprime a 2ª nota do aluno
		printf("\nNota 3: %.1f", NO->DATA.n3);		// imprime a 3ª nota do aluno
		printf("\nMedia final: %.1f", NO->DATA.average);		// imprime a media entre as três notas do aluno
		printf("\n");		// quebra de linha
		NO = NO->next;		// ponteiro no recebe a posição do proximo elemento da lista
	}
}