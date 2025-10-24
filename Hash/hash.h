#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 100 

typedef struct slot_data {
  int key;
  char name[MAX_NAME_SIZE];		
	float grade_1, grade_2, grade_3;		
} SlotData;

typedef struct hash Hash;

// Funções de Gerenciamento da Hash
Hash* create_Hash(int TABLE_SIZE);
void free_Hash(Hash* HA);

// Funções de Cálculo de Chave
int calculate_String_Value(char *str);

// Funções de Inserção e Busca (Colisão Sem Tratamento/Endereçamento Direto)
int insert_hash_collisionFree(Hash* HA, struct slot_data data);
int search_hash_collisionFree(Hash* HA, int key, struct slot_data *result);

// Funções de Inserção e Busca (Endereçamento Aberto)
int insert_hash_openAddress(Hash* HA, struct slot_data data);
int search_hash_openAddress(Hash* HA, int key, struct slot_data *result);

// Funções de Sondagem para Endereçamento Aberto (Implementações Necessárias)
int linear_probing(int initial_pos, int i, int TABLE_SIZE);
int quadratic_probing(int initial_pos, int i, int TABLE_SIZE);
int double_hashing(int hash_one, int key, int i, int TABLE_SIZE);

#endif // HASH_H