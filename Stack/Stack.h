#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> 

// ----------------------------------------------------
// Estrutura de Dados (Item armazenado na pilha)
struct data{		
	float NUMBER; // Variável onde será armazenado o dado do tipo float  
};

// ----------------------------------------------------
// Tipo OPACO (Handle) para a Pilha
// O utilizador só vê o ponteiro, a estrutura interna (struct stack)
typedef struct stack Stack; 

// ----------------------------------------------------
// PROTÓTIPOS DAS FUNÇÕES DA PILHA (Stack)
// Nota: 'insertStack' é o termo para PUSH, 'removeStack' para POP.

// Funções de Gerenciamento da Pilha
Stack* createStack();
void freeStack(Stack* ST);
int sizeStack(const Stack* ST);
int emptyStack(const Stack* ST);

//Adiciona um elemento ao topo da pilha (PUSH).
int insertStack(Stack* ST, struct data dt);

//Remove o elemento do topo da pilha (POP).
int removeStack(Stack* ST);

//Acessa (mas não remove) o elemento do topo da pilha (PEEK).
int accessTopStack(const Stack* ST, struct data *dt);

#endif // STACK_H