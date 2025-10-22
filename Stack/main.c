#include "Stack.h" 

int main(){
    
    // Criação da Pilha
    Stack *my_stack = createStack(); 
    
    if (my_stack == NULL) {
        fprintf(stderr, "Erro ao criar a pilha!\n");
        return 1;
    }

    // Limpeza da memória
    freeStack(my_stack);
    printf("\nPilha destruída (memória liberada).\n");
    
    return 0;
}