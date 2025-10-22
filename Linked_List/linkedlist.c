#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// ----------------------------------------------------
// 1. Definições Internas (Estruturas Ocultas)

// Definição do Tipo Elemento (Nó)
typedef struct element Elem;
struct element{
	struct data data;		
	Elem *next;		
};

// Definição da Estrutura de Gestão da Lista (Handle)
struct list{
    Elem *head; // Ponteiro para o primeiro elemento (cabecalho)
    int size;   // Armazena o tamanho atual da lista (opcional, mas otimiza size_list)
};

// ----------------------------------------------------
// 2. FUNÇÃO DE CRIAÇÃO E DESTRUIÇÃO

/**
 * Cria e inicializa a estrutura de gestão da lista.
 * return - Retorna um ponteiro para a nova Lista ou NULL em caso de falha.
*/
List* create_list(){
	// Aloca memória para a estrutura de gestão (handle)
	List *li = (List*) malloc(sizeof(struct list));
	
	if(li != NULL){
		li->head = NULL; // Inicializa o ponteiro do primeiro elemento como NULL
        li->size = 0;    // Inicializa o contador de tamanho
	}
	return li;
}

/**
 * Libera a memória de todos os nós e da estrutura de gestão da lista.
 * li - Ponteiro para a estrutura de gestão da lista.
*/
void free_list(List* li){
	if(li != NULL){
		Elem* current_node = li->head;
		Elem* next_node;
		
		// Loop para liberar cada nó
		while(current_node != NULL){
			next_node = current_node->next; 
			free(current_node);		
            current_node = next_node;
		}
		free(li); // Libera a estrutura de gestão por último
	}	
}

// ----------------------------------------------------
// 3. FUNÇÕES DE CONSULTA

int size_list(const List* li){	
	if(li == NULL){
		return 0; 
	}
    // Retorna o tamanho armazenado, que é O(1). 
    // Se não armazenássemos, teríamos que percorrer (O(N)).
	return li->size; 
}

// Verifica se a lista está vazia, retorna 1 se vazia ou NULL, 0 caso contrário.
int empty_list(const List* li){
	if(li == NULL || li->head == NULL){
		return 1;
	}
	return 0;
}

// ----------------------------------------------------
// 4. FUNÇÕES DE INSERÇÃO

/**
 * Cria e inicializa um novo nó. Função auxiliar interna.
 * dt - Os dados a serem armazenados.
 * return - Retorna o novo nó alocado ou NULL em caso de falha.
*/
static Elem* create_node(struct data dt) {
    Elem* new_node = (Elem*) malloc(sizeof(Elem));
    if (new_node != NULL) {
        new_node->data = dt;
        new_node->next = NULL;
    }
    return new_node;
}


// ========= Inserção no início da lista. =========
/** 
 * li - Ponteiro para a estrutura de gestão.
 * dt - Os dados a serem inseridos.
 * retorna 1 em sucesso, 0 em falha.
*/
int insert_start_list(List* li, struct data dt){
	if(li == NULL){
		return 0;
	}
	Elem* new_node = create_node(dt);
	if(new_node == NULL){
		return 0;
	}
    
	// O novo nó aponta para o antigo primeiro (li->head)
	new_node->next = li->head;
	// O cabeçalho passa a apontar para o novo nó
	li->head = new_node;
    li->size++;
    
	return 1;
}


// ========= Inserção no final da lista. =========
/**
 * li - Ponteiro para a estrutura de gestão.
 * dt - Os dados a serem inseridos.
 * retorna 1 em sucesso, 0 em falha.
*/
int insert_end_list(List* li, struct data dt){
	if(li == NULL){
		return 0;
	}
	Elem* new_node = create_node(dt);
	if(new_node == NULL){
		return 0;
	}

	if(li->head == NULL){
		// Se a lista estiver vazia, o novo nó é o primeiro
		li->head = new_node;
	} else {
		// Percorrer a lista até encontrar o último nó
		Elem *aux = li->head;
		while(aux->next != NULL){
			aux = aux->next;
		}
		// O último nó passa a apontar para o novo nó
		aux->next = new_node;
	}
    li->size++;
	return 1;
}


// ========= Inserção ordenada (crescente pelo campo 'num'). =========
/**
 * li - Ponteiro para a estrutura de gestão.
 * dt - Os dados a serem inseridos.
 * retorna 1 em sucesso, 0 em falha.
*/
int insert_sorted_list(List* li, struct data dt){
	if(li == NULL){
		return 0;
	}
	Elem* new_node = create_node(dt);
	if(new_node == NULL){
		return 0;
	}

	// Caso 1: Lista Vazia
	if(li->head == NULL){
		li->head = new_node;
	} else{
        // Caso 2: Inserção no início (matrícula menor que a primeira)
        if(dt.num < li->head->data.num){
            new_node->next = li->head;
            li->head = new_node;
        } else {
            // Caso 3: Inserção no meio ou final
            Elem *prev, *current = li->head;
            
            // Procura a posição: para no nó onde a matrícula for MAIOR
            while(current != NULL && current->data.num < dt.num){
                prev = current;
                current = current->next;
            }
            
            // current é NULL (inserção no final) ou o primeiro nó maior
            new_node->next = current; 
            prev->next = new_node; 
        }
	}
    li->size++;
	return 1;
}

// ----------------------------------------------------
// 5. FUNÇÕES DE REMOÇÃO

// =========  Remove o elemento do início da lista. ========= 
/**
 * li - Ponteiro para a estrutura de gestão.
 * retorna 1 em sucesso, 0 em falha (lista inexistente ou vazia).
*/
int remove_start_list(List* li){
	if(li == NULL || li->head == NULL){
		return 0;
	}
	
	Elem *node_to_remove = li->head;
	// O novo cabeçalho é o próximo nó
	li->head = li->head->next;
	
	free(node_to_remove);
    li->size--;
	return 1;
}


// ========= Remove o elemento do final da lista. ========= 
/**
 * li - Ponteiro para a estrutura de gestão.
 * retorna 1 em sucesso, 0 em falha.
*/
int remove_end_list(List* li){
	if(li == NULL || li->head == NULL){
		return 0;
	}

	// Caso especial: apenas um elemento na lista
	if(li->head->next == NULL){
		free(li->head);
		li->head = NULL;
        li->size--;
		return 1;
	}
    
  // Caso geral: dois ou mais elementos
	Elem *prev = li->head;
  Elem *current = li->head->next;
    
	// Percorre até que 'current' seja o último (next == NULL)
	while(current->next != NULL){
		prev = current;
		current = current->next;
	}
    
	// 'prev' é o penúltimo nó
	prev->next = NULL; // O penúltimo passa a ser o novo último
	free(current);     // Remove o antigo último
    li->size--;
	return 1;
}


// ========= Remove um elemento pela matrícula.  ========= 
/**
 * li - Ponteiro para a estrutura de gestão.
 * num - O número da matrícula a ser removido.
 * retorna 1 em sucesso, 0 em falha.
*/
int remove_list_by_num(List* li, int num){
	if(li == NULL || li->head == NULL){
		return 0;
	}

	Elem *prev = NULL;
	Elem *current = li->head;
    
	// Procura o nó a ser removido
	while(current != NULL && current->data.num != num){
		prev = current;
		current = current->next;
	}
    
	// Não encontrou a matrícula
	if(current == NULL){
		return 0;
	}
    
	// Caso 1: Remoção do primeiro elemento (current == li->head)
	if(current == li->head){
		li->head = current->next;
	} else{
    // Caso 2: Remoção do meio ou final
		prev->next = current->next;
	}
    
	free(current);
    li->size--;
	return 1;
}

// ----------------------------------------------------
// 6. FUNÇÕES DE BUSCA

// =========  Busca um elemento pela posição. ========= 
/**
 * li - Ponteiro constante para a estrutura de gestão.
 * pos - A posição (1-baseada) a ser procurada.
 * dt - Ponteiro onde os dados encontrados serão armazenados.
 * retorna 1 em sucesso, 0 em falha.
*/
int search_list_pos(const List* li, int pos, struct data *dt){
	if(li == NULL || pos <= 0 || li->head == NULL || pos > li->size){
		return 0;
	}
    
	Elem *current = li->head;
	for (int i = 1; i < pos; i++){
		current = current->next;
	}
    
	*dt = current->data;
	return 1;
}


// ========= Busca um elemento pela matrícula. =========
/**
 * li - Ponteiro constante para a estrutura de gestão.
 * num - A matrícula a ser procurada.
 * dt - Ponteiro onde os dados encontrados serão armazenados.
 * retorna 1 em sucesso, 0 em falha.
*/
int search_list_num(const List* li, int num, struct data *dt){
	if(li == NULL || li->head == NULL){
		return 0;
	}
    
	Elem *current = li->head;
    
	while(current != NULL && current->data.num != num){
		current = current->next;
	}
    
	if(current == NULL){
		return 0;
	} else{
		*dt = current->data;
	}
	return 1;
}

// ----------------------------------------------------
// 7. FUNÇÃO DE IMPRESSÃO

/**
 * Imprime todos os elementos da lista.
 * li - Ponteiro constante para a estrutura de gestão.
 */
void print_list(const List* li){
	if(li == NULL || li->head == NULL){
		printf("\nLISTA INEXISTENTE OU VAZIA\n");
        return;
	}
    
    printf("\n--- INÍCIO DA LISTA (Tamanho: %d) ---\n", li->size);
	Elem *current = li->head;
    
	while(current != NULL){
		printf("======================================\n");
		printf("NAME: %s\n", current->data.name);
		printf("NUMBER: %d\n", current->data.num);
		printf("Nota 1: %.1f\n", current->data.n1);
		printf("Nota 2: %.1f\n", current->data.n2);
		printf("Nota 3: %.1f\n", current->data.n3);
		printf("Media final: %.1f\n", current->data.average);
		current = current->next;
	}
    printf("--- FIM DA LISTA ---\n");
}