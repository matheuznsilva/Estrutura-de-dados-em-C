#include "hash.h" // Hash Genérica

#define TAMANHO_HASH 997

int main(){

	Hash *HA = create_Hash(TAMANHO_HASH);

	// Garante que a memória é liberada antes de sair
	if (HA != NULL){
		free_Hash(HA);
	}

	return 0;
}