#ifndef BS_TREE_H
#define BS_TREE_H

#include <stdio.h>
#include <stdlib.h>

// B_Tree é um ponteiro para um ponteiro de nó (NO**) para
// manipular a raiz. Como é uma Árvore Binária de Busca.
typedef struct NO* BS_Tree;

// Funções de Gerenciamento da Árvore
BS_Tree* create_BS_Tree();
void free_BS_Tree(BS_Tree* root);

// Funções de Operação
int insert_BS_Tree(BS_Tree* root, int key);
int remove_BS_Tree(BS_Tree* root, int key);
int consult_BS_Tree(BS_Tree* root, int key);

// Funções de Estado e Estatísticas
int empty_BS_Tree(BS_Tree* root);
int height_BS_Tree(BS_Tree* root);
int total_nodes_BS_Tree(BS_Tree* root);

// Funções de Travessia
void pre_order(BS_Tree* root);
void in_order(BS_Tree* root);
void post_order(BS_Tree* root);

#endif // BS_TREE_H