
//#define MAX 100 // define tamanho maximo da lista

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Definição do tipo lista



// dado do tipo arquivo
struct arquivo{		// struct onde é guardada as informações de cada nó da lista
	char str[20];		// variável onde é guardado o nome do arquivo
	int linha;		//	variavel onde é guardada a posição da linha onde a palavra é encontrada
};

typedef struct elemento* Lista; // padronização do nome do ponteiro tipo lista

struct elemento{
	struct arquivo dados;		// campo do tipo arquivo que recebe o dado a ser armazenado
	struct elemento *prox;		// ponteiro do tipo elemento que indica o proximo elemento 
};

typedef struct elemento Elem;		// definição de um nome padrão para a struct elemento
// ==========================================================


Lista* criar_lista();	// criação da lista

void libera_lista(Lista* li);		// função de destruição da lista

int insere_lista_final(Lista* li, struct arquivo ar);		// função de inserção ao final da lista

int remove_lista_final(Lista* li);		// função de remoção de um elemento ao final da lista

int lista_vazia(Lista* li);		// função que retorna se a lista esta vazia

void imprime_lista(Lista* li);		// função que imprime a lista
