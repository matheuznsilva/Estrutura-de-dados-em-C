# include <stdio.h>
# include <stdlib.h>
# include "bs_tree.h"

// Definição da Estrutura Interna do Nó
typedef struct NO {
  int key;
  struct NO* left;
  struct NO* right;
} NO;

// =============== FUNÇÕES DE GERENCIAMENTO ===============

// Função auxiliar (static) para liberar a memória de forma recursiva
static void free_nodes(NO* node){
  if (node != NULL) {
    free_nodes(node->left); // Libera o nó esquerdo
    free_nodes(node->right);  // Libera o nó direito
    free(node); // Libera o nó atual
    node = NULL; // Evita ponteiros pendentes
  }
}

// Cria e inicializa a Árvore (ponteiro para o ponteiro da raiz)
BS_Tree* create_BS_Tree(){
  BS_Tree* root = (BS_Tree*) malloc(sizeof(BS_Tree));
  if (root != NULL) {
    *root = NULL;   // Inicializa a raiz como NULL (árvore vazia)
  }
  return root;
}

// Libera toda a memória da Árvore
void free_BS_Tree(BS_Tree* root){
  if (root != NULL) {
    free_nodes(*root);  
    free(root); 
  }
}

// Auxiliar: Encontra e retorna o nó com o menor valor (sucessor in-order) a partir de 'node'
static NO* find_min_node(NO* node){
  NO* current = node;
  // A chave mínima está sempre no nó mais à esquerda
  while(current != NULL && current->left != NULL){
    current = current->left;
  }
  return current;
}

// Auxiliar: Remove um nó da ABB
static NO* remove_node(NO* current){
  NO *temp, *successor;
  if(current->left == NULL){
    temp = current->right;
    free(current);
    return temp;
  }
  if(current->right == NULL){
    temp = current->left;
    free(current);
    return temp;
  }

  successor = find_min_node(current->right);
  current->key = successor->key;
  current->right = remove_node(current->right);

  NO* parent_successor = current;
  successor = current->right;
  while(successor->left != NULL){
    parent_successor = successor;
    successor = successor->left;
  }
  current->key = successor->key;
  if(parent_successor != current){
    parent_successor->left = successor->right;
  } else {
    parent_successor->right = successor->right;
  }
  free(successor);
  return current;
}

// =============== FUNÇÕES DE OPERAÇÃO BÁSICA ===============

// Insere uma nova chave na ABB
int insert_BS_Tree(BS_Tree* root, int key){
  if(root == NULL){
    return 0;
  }
  NO* new_node = (NO*) malloc(sizeof(NO));
  if(new_node == NULL){
    return 0;
  }
  new_node->key = key;
  new_node->left = NULL;
  new_node->right = NULL;

  if(*root == NULL){
    *root = new_node;
  } else {
    NO* current = *root;
    NO* prev = NULL;
    
    while(current != NULL){
      prev = current;
      if(key == current->key){
        free(new_node);   // Chave já existe, libera o nó alocado
        return 0; 
      } 
      if(key < current->key){
        current = current->left;
      } else {
        current = current->right;
      }
    }

    if(key < prev->key){
      prev->left = new_node;
    } else {
      prev->right = new_node;
    }
  }
  return 1;
}

// Remove uma chave da ABB
int remove_BS_Tree(BS_Tree* root, int key){
  if(root == NULL || *root == NULL){
    return 0;
  }

  //NO* prev = NULL;
  NO** current_ptr = root;

  // Busca o nó a ser removido
  while(current_ptr != NULL && (*current_ptr)->key != key){
    if(key < (*current_ptr)->key){
      current_ptr = &((*current_ptr)->left);
    } else {
      current_ptr = &((*current_ptr)->right);
    }
  }
  if(current_ptr == NULL){
    return 0; // Chave não encontrada
  }
  *current_ptr = remove_node(*current_ptr);
  return 1;
}

// Retorna 1 se a árvore estiver vazia, 0 caso contrário
int empty_BS_Tree(BS_Tree* root){
  return (root == NULL || *root == NULL) ? 1 : 0;
}

// Retorna a altura da árvore
int height_BS_Tree(BS_Tree* root){
  if(root == NULL || *root == NULL){
    return 0;
  }
  int height_left = height_BS_Tree(&((*root)->left));
  int height_right = height_BS_Tree(&((*root)->right));
  return (height_left > height_right ? height_left : height_right) + 1;
}

// Retorna o número total de nós
int total_nodes_BS_Tree(BS_Tree* root){
  if(root == NULL || *root == NULL){
    return 0;
  }
  int total_left = total_nodes_BS_Tree(&((*root)->left));
  int total_right = total_nodes_BS_Tree(&((*root)->right));
  return total_left + total_right + 1;
}

// Consulta uma chave na ABB
int consult_BS_Tree(BS_Tree* root, int key){
  if(root == NULL || *root == NULL){
    return 0;
  }
  NO* current = *root;
  while(current != NULL){
    if(key == current->key){
      return 1; 
    } 
    if(key < current->key){
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return 0; 
}

// Funções de Travessia (Percorrem a árvore e imprimem a chave)
void pre_order(BS_Tree* root){
  if(root == NULL || *root == NULL){
    return;
  }
  printf("%d ", (*root)->key);
  pre_order(&((*root)->left));
  pre_order(&((*root)->right));
}

void in_order(BS_Tree* root){
  if(root == NULL || *root == NULL){
    return;
  }
  in_order(&((*root)->left));
  printf("%d ", (*root)->key);
  in_order(&((*root)->right));
}

void post_order(BS_Tree* root){
  if(root == NULL || *root == NULL){
    return;
  }
  post_order(&((*root)->left));
  post_order(&((*root)->right));
  printf("%d ", (*root)->key);
}