#include "Stack.h" // Inclui os protótipos e struct data

// ----------------------------------------------------
// 1. Definições Internas (Estruturas Ocultas)

// Definição do Tipo Elemento (Nó da Pilha)
typedef struct element Elem;
struct element{
	struct data data;
	Elem *next;
};

// Definição da Estrutura de Gestão da Pilha (Handle)
struct stack{
  Elem *head; // Ponteiro para o elemento do topo
  int size;   // Armazena o tamanho atual (O(1) para sizeStack)
};

// ----------------------------------------------------
// 2. FUNÇÕES DE CRIAÇÃO E DESTRUIÇÃO

/**
 * Cria e inicializa a estrutura de gestão da pilha.
 * retorna um ponteiro para a nova Pilha ou NULL em caso de falha.
*/
Stack* createStack(){ 
  // Aloca memória para a estrutura de gestão (handle)
  Stack* ST = (Stack*) malloc(sizeof(struct stack));

  if (ST != NULL){
    ST->head = NULL; // Inicializa o topo da pilha como NULL
    ST->size = 0;    // Inicializa o contador de tamanho
  }
  return ST;
}

/**
 * Libera a memória de todos os nós e da estrutura de gestão da pilha.
 * ST - Ponteiro para a Pilha.
*/
void freeStack(Stack* ST){
  if (ST != NULL){
    Elem* current = ST->head;
    Elem* next_node;
    
    while (current != NULL){
      next_node = current->next;
      free(current);
      current = next_node;
    }
    free(ST); // Libera a estrutura de gestão por último
  }
}

// ----------------------------------------------------
// 3. FUNÇÕES DE CONSULTA

int sizeStack(const Stack* ST){
  if(ST == NULL){
    return 0;
  }
  // Retorna o numero de elementos na pilha (O(1)). 
  return ST->size;    
}

// Verifica se a pilha está vazia, retorna 1 se vazia ou NULL, 0 caso contrário.
int emptyStack(const Stack* ST){
  if(ST == NULL || ST->head == NULL){
    return 1;
  }
  return 0;
}

// Acessa (mas não remove) o elemento do topo da pilha (PEEK), retorna 1 em sucesso, 0 em falha.
int accessTopStack(const Stack* ST, struct data *dt){ 
  if(ST == NULL || ST->head == NULL){
    return 0; // Pilha inexistente ou vazia
  }
  *dt = ST->head->data; // O topo é sempre o 'head'
  return 1;
}

// ----------------------------------------------------
// 4. FUNÇÕES DE MANIPULAÇÃO

/**
 * Adiciona um elemento ao topo da pilha (PUSH).
 * ST - Ponteiro para a Pilha.
 * dt - Os dados a serem inseridos.
 * retorna 1 em sucesso, 0 em falha.
*/
int insertStack(Stack* ST, struct data dt){ 
  if(ST == NULL){
    return 0;
  }
  
  // 1. Aloca e inicializa o novo nó
  Elem* new_node = (Elem*) malloc(sizeof(Elem));
  if(new_node == NULL){
    return 0;
  }
  new_node->data = dt;
  
  // 2. O novo nó aponta para o antigo topo
  new_node->next = ST->head;
  
  // 3. O 'head' da pilha passa a ser o novo nó
  ST->head = new_node;
  
  // 4. Atualiza o tamanho
  ST->size++;
  
  return 1;
}

/**
 * Remove o elemento do topo da pilha (POP).
 * ST - Ponteiro para a Pilha.
 * retorna 1 em sucesso, 0 em falha (pilha vazia ou inexistente).
 */
int removeStack(Stack* ST){ 
    if(ST == NULL || ST->head == NULL){
        return 0; // Pilha inexistente ou vazia
    }
    
    Elem *node_to_remove = ST->head;
    
    // O 'head' passa a apontar para o próximo nó (o novo topo)
    ST->head = node_to_remove->next;
    
    free(node_to_remove);
    
    // Atualiza o tamanho
    ST->size--;
    
    return 1;
}