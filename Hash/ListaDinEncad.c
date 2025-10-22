#include "ListaDinEncad.h"

Lista* criar_lista(){
	Lista* li = (Lista*) malloc(sizeof(Lista));		// alocação de memoria para a Lista
	
	if(li != NULL){		// confere se a lista foi criada
		*li = NULL;	// caso criada faz o ponteiro apontar para null
		printf("\n\nLISTA CRIADA\n"); // confirmação q a lista foi criada
	}
	return li;		// retorna o ponteiro li;
}
// ==========================================================

// FUNÇÃO QUE DESTROI A LISTA

void libera_lista(Lista* li){
	if(li!= NULL){		// verifica se a lista existe
		Elem* no;		// declaração de um ponteiro auxiliar
		while((*li)!=NULL){		// loop para percorrer a lista com condição de para ser o final da lista
			no = *li;		// ponteiro auxiliar recebe a posição atual do ponteiro li
			*li = (*li)->prox;		// li recebe a posição do proximo elemento 
			free(no);		// apaga o nó(elemento) da lista
		}
		free(li);	// libera o ponteiro	
		printf("\nLISTA APAGADA COM EXITO\n");		// informado que a lista foi apagada

	} else{
		printf("\nLISTA NÃO EXISTENTE\n");		// caso não exista a lista informa que a operação não pode ser processada

	}	
}
// ==========================================================

// FUNAÇÃO QUE RETORNA O TAMANHO DA LISTA

int tamanho_lista(Lista* li){	
	if(li == NULL){		// confere se a lista existe
		return 0;		// caso não exista retorna 0
	}
	int cont = 0;		// declaração de variável local(contador) para armazenar a quantidade de elementos presentes na lista
	Elem* no = *li;		// declaração e atribuição do ponteiro auxiliar para percorrer a lista
	while(no != NULL){		// loop para percorrer a lista com condição de para ser o final da lista
		cont++;		// incremento do contador
		no = no->prox;		// ponteiro auxiliar recebe a proxima posição da lista
	}
	return cont;		// retorna o contador
}
// ==========================================================

// FUNÇÃO QUE RETORNA SE A LISTA ESTA VAZIA OU NÃO

int lista_vazia(Lista* li){
	if(li == NULL){		// confere se a lista existe
		return 1;		// se a lista não existir retorna 1
	}
	if(*li == NULL){	// confere se a lista está vazia
		return 1;		// caso esteja retorna 1
	}
	return 0;		// caso ja exista algum elemento na lista retorna 0
}
// ==========================================================

// FUNÇÃO DE INSERÇÃO

int insere_lista_final(Lista* li, struct arquivo ar){		//  inserção ao final da lista
	if(li == NULL){		// confere se a lista existe
		return 0;		// caso não exista não ocorre a inserção
	}
	Elem* no;		// delcaração de um ponteiro auxiliar
	no = (Elem*) malloc(sizeof(Elem));		// alocação de memoria para um novo elemento
	if(no == NULL){		// confere se ocorreu a alocação
		return 0;		// caso não tenha ocorrido retorna 0
	}
	no->dados = ar;		// o campo dados do novo elemento recebe os dados digitados pelo usuário
	no->prox = NULL;	// o ponteiro prox do novo elemento passa a apontar para null

	if((*li) == NULL){		// confere se é uma lista vazia
		*li = no;		// caso seja atribuimos o novo elemento ao inicio da lista
	} else {		// caso não seja percorremos a lista até encontrar o ultimo elemento
		Elem *aux;		// declaração de um outro ponteiro auxiliar
		aux = *li;		// ponteiro auxiliar recebe a posição inicial da lista
		while(aux->prox != NULL){		// loop para percorrer a lista tendo como condição de parada o final da lista
			aux = aux->prox;		// ponteiro auxiliar recebe o endereço do proximo elemento
		}
		aux->prox = no;		// ao final do loop o ponteiro prox que antes apontava pra null passa a apontar para o novo elemento
	}
	return 1;
}

// ==========================================================

// FUNÇÕES DE REMOÇÃO

int remove_lista_final(Lista* li){		// remoção no final da lista
	if(li == NULL){		// confere se a lista existe
		printf("\nLISTA NÃO EXISTENTE\n");		// caso não exista informa que a operação não pode ser processada
		return 0;
	}
	if((*li) == NULL){		// confere se existe elementos na lista
		printf("\nLISTA NÃO POSSUI ELEMENTOS CADASTRADOS\n");		// caso não exista elementos informa que a operação não pode ser processada
		return 0;
	}
	Elem *ant, *no = *li;		// declaração de ponteiros auxiliares e atribuição do ponteiro no apontando para o primeiro elemento da lista
	while(no->prox != NULL){		// loop para percorrer a lista tendo como condição de parada o final da lista
		ant = no;		// atribui ao ponteiro ant a posição do elemento apontado por no
		no = no->prox;		// ponteiro no recebe a posição do proximo elemento da lista
	}

	if(no == (*li)){		// confere se o nó é igual ao inicio da lista
		*li = no->prox;		// se for o ponteiro li passa a apontar para o proximo elemento
	} else{
		ant->prox = no->prox;		// se não for o ponteiro prox do anterior passa a apontar para o proximo elemento
	}
	free(no);		// apaga o elemento (libera a memoria utilizada pelo elemento a ser apagado)
	return 1;
}

// ==========================================================

// FUNÇÃO DE IMPRESSÃO DA LISTA

void imprime_lista(Lista* li){
	if(li == NULL){		// confere se a lista existe
		printf("\nLISTA NÃO EXISTENTE\n");		// caso não exista informa que a operação não pode ser processada
	}
	if((*li) == NULL){		//confere se existe elementos na lista
		printf("\nLISTA NÃO POSSUI ELEMENTOS CADASTRADOS\n");		// caso não exista elementos informa que a operação não pode ser processada
	}

	Elem *no = *li;		// declaração e atribuição do ponteiro no apontando para o primeiro elemento da lista
	printf("\nPalavra: ");
	while(no != NULL){		// loop para deslocamento na lista 
		printf("%s ", no->dados.str);		// imprime o nome do arquivo
		no = no->prox;		// ponteiro no recebe a posição do proximo elemento da lista
	}
		printf("\n");		// quebra de linha

}


