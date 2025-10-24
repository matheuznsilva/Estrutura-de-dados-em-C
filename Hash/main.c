#include "hash.h" // Hash Genérica

#define TAMANHO_HASH 997

int main(){

	// Criação da Tabela Hash
	Hash *HA = create_Hash(TAMANHO_HASH);

	// Liberação de Memória
	free_Hash(HA);

	return 0;
}