#include "hash.h"

// =============== DEFINIÇÃO DO TIPO HASH GENÉRICO ===============

struct hash{
	int qtd, TABLE_SIZE;
	//List **slots;
	struct slot_data **slots; // Onde struct word **itens estava
};


// =============== CRIAÇÃO DA TABELA DE HASH GENÉRICA ===============

Hash* criaHash(int TABLE_SIZE){
	
	Hash* HA = (Hash*)malloc(sizeof(struct hash));
	if(HA != NULL){
		HA->TABLE_SIZE = TABLE_SIZE;
		HA->slots = (struct slot_data**)malloc(TABLE_SIZE * sizeof(struct slot_data*));
 
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

// =============== CALCULO DE CHAVE ===============

// ------ Metodo da divisao ------
int division_key(int key, int TABLE_SIZE){
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
	int part_two = key & (TABLE_SIZE - 1);
	return (part_one ^ part_two);
}

// ------ Calculo valor da strings ------
int string_value(char *str){
	int valor = 7;
	int TAM = (int)strlen(str);

	for (int i = 0; i < TAM; i++){
		// Ignora pontuação
		if (str[i] != ' ' && str[i] != '.' && str[i] != ',' && str[i] != '!'){
			valor = 31 * valor + (int)str[i];
		}
	}
	return valor;
}

// =============== INSERÇÃO NA HASH GENÉRICA ===============

int insert_hash_collisionFree(Hash* HA, struct slot_data data){
	if (HA == NULL || HA->qtd == HA->TABLE_SIZE){
		return 0;
	}
    
	int key = data.number;
	//int key = string_value(data.name);
	int pos = division_key(key, HA->TABLE_SIZE);
	//int pos = multiplication_key(key, HA->TABLE_SIZE);
	//int pos = folding_key(key, HA->TABLE_SIZE);
	struct slot_data* new_slot = (struct slot_data*) malloc(sizeof(struct slot_data));

	if (new_slot == NULL){
		return 0;
	}

	*new_slot = data; // Copia os dados para o novo slot
	HA->slots[pos] = new_slot;
	HA->qtd++;
	return 1;
}

int insert_hash_openAddress(Hash* HA, struct slot_data data){
	if (HA == NULL || HA->qtd == HA->TABLE_SIZE){
		return 0;
	}
		
	int key = data.number;
	//int key = string_value(data.name);
	int initial_pos = division_key(key, HA->TABLE_SIZE);
	int new_pos;
	//int initial_pos = multiplication_key(key, HA->TABLE_SIZE);
	//int initial_pos = folding_key(key, HA->TABLE_SIZE);
	for (int i = 0; i < HA->TABLE_SIZE; i++){
		new_pos = linear_probing(initial_pos, i, HA->TABLE_SIZE);
		//new_pos = quadratic_probing(initial_pos, i, HA->TABLE_SIZE);
		//new_pos = double_hashing(initial_pos, key, i, HA->TABLE_SIZE);

		if (HA->slots[new_pos] == NULL){
			struct slot_data* new_slot = (struct slot_data*) malloc(sizeof(struct slot_data));
			if (new_slot == NULL){
				return 0;
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

int search_hash_collisionFree(Hash* HA, int number, struct slot_data *result){
	if (HA == NULL){
		return 0;
	}

	int pos = division_key(number, HA->TABLE_SIZE);
	//int pos = multiplication_key(number, HA->TABLE_SIZE);
	//int pos = folding_key(number, HA->TABLE_SIZE);
	
	if (HA->slots[pos] == NULL){
		return 0; // Slot vazio
	}
	
	*result = *(HA->slots[pos]);
	return 1;
}

int search_hash_openAddress(Hash* HA, int number, struct slot_data *result){
	if (HA == NULL){
		return 0;
	}

	int initial_pos = division_key(number, HA->TABLE_SIZE);
	int new_pos;
	//int initial_pos = multiplication_key(number, HA->TABLE_SIZE);
	//int initial_pos = folding_key(number, HA->TABLE_SIZE);

	for (int i = 0; i < HA->TABLE_SIZE; i++){
		new_pos = linear_probing(initial_pos, i, HA->TABLE_SIZE);
		//new_pos = quadratic_probing(initial_pos, i, HA->TABLE_SIZE);
		//new_pos = double_hashing(initial_pos, key, i, HA->TABLE_SIZE);

		if (HA->slots[new_pos] == NULL){
			return 0; // Slot vazio
		}
		
		if (HA->slots[new_pos]->number == number){
			*result = *(HA->slots[new_pos]);
			return 1; // Encontrado
		}
	}
	return 0; // Não encontrado
}