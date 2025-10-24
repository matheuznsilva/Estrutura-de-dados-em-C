#include "hash.h"


// =============== DEFINIÇÃO DO TIPO HASH GENÉRICO ===============

struct hash{
	int qtd, TABLE_SIZE;
	//List **slots;
	SlotData **slots;
};


// =============== CRIAÇÃO DA TABELA DE HASH GENÉRICA ===============

Hash* create_Hash(int TABLE_SIZE){
	
	Hash* HA = (Hash*)malloc(sizeof(struct hash));
	if(HA != NULL){
		HA->TABLE_SIZE = TABLE_SIZE;
		// Aloca o array de ponteiros para SlotData
		HA->slots = (SlotData**)malloc(TABLE_SIZE * sizeof(SlotData*));
 
		if(HA->slots == NULL){
			free(HA);
			return NULL;
		}
		HA->qtd = 0;
		for(int i=0; i<HA->TABLE_SIZE; i++){
			HA->slots[i] = NULL;
		}
	}
	return HA;
}


// =============== DESTRUINDO A TABELA DE HASH GENÉRICA ===============

void free_Hash(Hash* HA){ 
	if(HA != NULL){
		for(int i=0; i<HA->TABLE_SIZE; i++){
			if(HA->slots[i] != NULL){
				free(HA->slots[i]);
			}
		}
		free(HA->slots);
		free(HA);
	}
}

// =============== FUNÇÕES AUXILIARES DE CÁLCULO DE CHAVE E SONDAGEM ===============

// ------ Metodo da divisao ------
int division_key(int key, int TABLE_SIZE){
	// O & 0x7FFFFFFF garante que a chave seja não negativa, se necessário
	return (key & 0x7FFFFFFF) % TABLE_SIZE; 
}

// ------ Metodo da multiplicação ------
int multiplication_key(int key, int TABLE_SIZE){
	const float A = 0.6180339887; // (sqrt(5) - 1) / 2
	float frac = (key * A) - (int)(key * A);
	return (int)(TABLE_SIZE * frac);
}

// ------ Metodo da dobra ------
int folding_key(int key, int TABLE_SIZE){
	int bits_number = 10; // Número de bits a considerar
	int part_one = key >> bits_number;
	int part_two = key & ((1 << bits_number) - 1);
	return (part_one ^ part_two);
}

// ------ Calculo valor da strings ------
int calculate_String_value(char *str){
	int valor = 7;
	int TAM = (int)strlen(str);

	for (int i = 0; i < TAM; i++){
		// Ignora pontuação
		if (str[i] != ' ' && str[i] != '.' && str[i] != ',' && str[i] != '!'){
			valor = 31 * valor + (int)str[i];
		}
	}
	return (valor & 0x7FFFFFFF);
}

// ------ Sondagem Linear ------
int linear_probing(int initial_pos, int i, int TABLE_SIZE){
	return ((initial_pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

// ------ Sondagem Quadrática ------
int quadratic_probing(int initial_pos, int i, int TABLE_SIZE){
	initial_pos = initial_pos + (2*i) + (5*(i*i));
	return (initial_pos & 0x7FFFFFFF) % TABLE_SIZE;
}

// ----- Double Hashing (Hash Dupla) -----
int double_hashing(int hash_one, int key, int i, int TABLE_SIZE){
	int hash_two = division_key(key, TABLE_SIZE - 1) + 1;
	return ((hash_one + i * hash_two) & 0x7FFFFFFF) % TABLE_SIZE;
}

// =============== INSERÇÃO NA HASH GENÉRICA ===============

// ------ (Endereçamento Direto/Sem Colisão) ------
int insert_hash_collisionFree(Hash* HA, SlotData data){
	if (HA == NULL || HA->qtd == HA->TABLE_SIZE){
		return 0;		// Erro ou tabela cheia
	}
    
	int key = data.key;
	//int key = string_value(data.name);

	// Calcula a posição inicial
	int pos = division_key(key, HA->TABLE_SIZE);
	//int pos = multiplication_key(key, HA->TABLE_SIZE);
	//int pos = folding_key(key, HA->TABLE_SIZE);

	// Verifica se a posição já está ocupada (tratamento simples/sem colisão)
	if (HA->slots[pos] != NULL) {
		return 0; // Colisão não tratada, inserção falha
	}

	SlotData* new_slot = (SlotData*) malloc(sizeof(SlotData));
	if (new_slot == NULL){
		return 0; // Falha na alocação
	}

	*new_slot = data; // Copia os dados para o novo slot
	HA->slots[pos] = new_slot;
	HA->qtd++;
	return 1;
}

// ------ (Endereçamento Aberto) ------
int insert_hash_openAddress(Hash* HA, SlotData data){
	if (HA == NULL || HA->qtd == HA->TABLE_SIZE){
		return 0;
	}
		
	int key = data.key;
	//int key = string_value(data.name);
	int initial_pos = division_key(key, HA->TABLE_SIZE);
	//int initial_pos = multiplication_key(key, HA->TABLE_SIZE);
	//int initial_pos = folding_key(key, HA->TABLE_SIZE);
	int new_pos;

	// Tenta encontrar uma posição livre usando sondagem
	for (int i = 0; i < HA->TABLE_SIZE; i++){

		// Use a sondagem que desejar (ex: linear_probing)
		new_pos = linear_probing(initial_pos, i, HA->TABLE_SIZE);
		//new_pos = quadratic_probing(initial_pos, i, HA->TABLE_SIZE);
		//new_pos = double_hashing(initial_pos, key, i, HA->TABLE_SIZE);

		if (HA->slots[new_pos] == NULL){
			// Encontrou slot vazio, aloca e insere
			SlotData* new_slot = (SlotData*) malloc(sizeof(SlotData));
			if (new_slot == NULL){
				return 0;		// Falha na alocação
			}

			*new_slot = data; // Copia os dados para o novo slot
			HA->slots[new_pos] = new_slot;
			HA->qtd++;
			return 1;
		}
	}
	return 0; // Tabela cheia
}

// =============== BUSCA NA HASH GENÉRICA ===============

// ------ (Endereçamento Direto/Sem Colisão) ------
int search_hash_collisionFree(Hash* HA, int key, SlotData *result){
	if (HA == NULL){
		return 0;
	}

	int pos = division_key(key, HA->TABLE_SIZE);
	//int pos = multiplication_key(key, HA->TABLE_SIZE);
	//int pos = folding_key(key, HA->TABLE_SIZE);
	
	if (HA->slots[pos] == NULL){
		return 0; // Slot vazio
	}

	// Verifica se a chave do dado no slot corresponde à chave buscada
	if (HA->slots[pos]->key == key){
		*result = *(HA->slots[pos]);
		return 1;
	}

	return 0; // Não encontrado
}

// ------ (Endereçamento Aberto) ----------
int search_hash_openAddress(Hash* HA, int key, SlotData *result){
	if (HA == NULL){
		return 0;
	}

	int initial_pos = division_key(key, HA->TABLE_SIZE);
	//int initial_pos = multiplication_key(key, HA->TABLE_SIZE);
	//int initial_pos = folding_key(key, HA->TABLE_SIZE);
	int new_pos;

	for (int i = 0; i < HA->TABLE_SIZE; i++){

		// Use a MESMA sondagem que foi usada na inserção
		new_pos = linear_probing(initial_pos, i, HA->TABLE_SIZE);
		//new_pos = quadratic_probing(initial_pos, i, HA->TABLE_SIZE);
		//new_pos = double_hashing(initial_pos, key, i, HA->TABLE_SIZE);

		if (HA->slots[new_pos] == NULL){
			return 0; // Slot vazio
		}
		
		if (HA->slots[new_pos]->key == key){
			*result = *(HA->slots[new_pos]);
			return 1; // Encontrado
		}
	}
	return 0; // Não encontrado
}