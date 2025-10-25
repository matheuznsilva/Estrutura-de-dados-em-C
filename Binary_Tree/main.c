#include "bs_tree.h"

int main(){
  BS_Tree* tree = create_BS_Tree();
  
  if (tree == NULL) {
    printf("Erro ao alocar a árvore!\n");
    return 1;
  }

  free_BS_Tree(tree);

  return 0;
}