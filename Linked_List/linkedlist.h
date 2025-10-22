#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h> // Para size_t

// Definimos o tamanho máximo para o nome do aluno aqui
#define MAX_NAME_SIZE 100 

// ----------------------------------------------------
// Estrutura de Dados do Aluno (Informação a ser armazenada)
struct data{		
	int num; // Matricula (usada para ordenação e busca)	
	char name[MAX_NAME_SIZE];		
	float n1, n2, n3, average;		
};

// Tipo OPACO (Handle) para a Lista encadeada
// O utilizador só vê o ponteiro, a estrutura interna (struct list)
typedef struct list List; 

// ----------------------------------------------------
// PROTÓTIPOS DAS FUNÇÕES

// Funções de Gerenciamento da Lista
List* create_list();
void free_list(List* li);
int size_list(const List* li);
int empty_list(const List* li);

// Funções de Inserção
int insert_start_list(List* li, struct data dt);
int insert_end_list(List* li, struct data dt);
int insert_sorted_list(List* li, struct data dt);

// Funções de Remoção
int remove_start_list(List* li);
int remove_end_list(List* li);
int remove_list_by_num(List* li, int num);

// Funções de Busca
int search_list_pos(const List* li, int pos, struct data *dt);
int search_list_num(const List* li, int num, struct data *dt);

// Funções de Impressão
void print_list(const List* li);

#endif // LINKEDLIST_H