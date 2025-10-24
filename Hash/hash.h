#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 100 

struct slot_data {
  int number;
  char name[MAX_NAME_SIZE];		
	float grade_1, grade_2, grade_3;		
};

typedef struct hash Hash;

Hash* create_Hash(int TABLE_SIZE);
void free_Hash(Hash* HA);
int string_Value(char *str);
int insert_hash_collisionFree(Hash* HA, struct slot_data data);
int search_hash_collisionFree(Hash* HA, int number, struct slot_data *result);
int insert_hash_openAddress(Hash* HA, struct slot_data data);
int search_hash_openAddress(Hash* HA, int number, struct slot_data *result);

int linear_probing(int initial_pos, int i, int TABLE_SIZE);
int quadratic_probing(int initial_pos, int i, int TABLE_SIZE);
int double_hashing(int hash_one, int key, int i, int TABLE_SIZE);

#endif // HASH_H