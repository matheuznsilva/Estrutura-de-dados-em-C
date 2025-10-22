#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

int main(){
  // Cria o HANDLE da lista
  List *li = create_list(); 

  if (li == NULL) {
    fprintf(stderr, "Erro ao criar a lista!\n");
    return 1;
  }

  free_list(li);
  printf("\nLista destruída (memória liberada).\n");
  
  return 0;
}