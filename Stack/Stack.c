#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ReversePolish.h"

//Definição do tipo lista

struct element{
	struct data DATA;		// campo do tipo dado
	struct element *next;		// ponteiro que armazena a proxima posicao da pilha 
};

typedef struct element Elem;		// definição de um nome padrão para a struct elemento

// FUNCOES BASICAS DA PILHA 

Stack* createStack(){       // Funcao de criacao da pilha
    Stack* ST = (Stack*) malloc(sizeof(Stack));
    if (ST != NULL){
        *ST = NULL;
    }
    return ST;
}

void freeStack(Stack* ST){      // Funcao de destruicao da pilha
    if (ST != NULL){
        Elem* NO;
        while ((*ST)!= NULL){
            NO = *ST;
            *ST = (*ST)->next;
            free(NO);
        }
        free(ST);
    }
}

int sizeStack(Stack* ST){       // Funcao que retorna o tamanho da pilha
    if(ST == NULL){
        return 0;
    }
    int COUNT = 0;
    Elem* NO = *ST;
    while (NO != NULL){
        COUNT++;
        NO = NO->next;
    }
    return COUNT;    
}

int emptyStack(Stack* ST){       // Funcao que retorna se a pilha está vazia 
    if(ST == NULL){
        return 1;
    }
    if(*ST == NULL){
        return 1;
    }
    return 0;
}

int insertStack(Stack* ST, struct data DT){       // Funcao de insercao na pilha (Lembrando que pilha e LIFO)
    if(ST == NULL){
        return 0;
    }
    Elem* NO;
    NO = (Elem*) malloc(sizeof(Elem));
    if(NO == NULL){
        return 0;
    }
    NO->DATA = DT;
    NO->next = (*ST);
    *ST = NO;
    return 1;
}

int removeStack(Stack* ST){       // Funcao de remocao na pilha (Essa remocao sempre acontece do topo) 
    if(ST == NULL){
        return 0;
    }
    if((*ST) == NULL){
        return 0;
    }
    Elem *NO = *ST;
    *ST = NO->next;
    free(NO);
    return 1;
}

int accessTopStack(Stack* ST, struct data *DT){       // Funcao que acessa o topo da pilha
    if(ST == NULL){
        return 0;
    }if((*ST) == NULL){
        return 0;
    }
    *DT = (*ST)->DATA;
    return 1;
}