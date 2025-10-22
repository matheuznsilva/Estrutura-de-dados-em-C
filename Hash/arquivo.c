
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

FILE* abrir_arquivo(char texto[MAX]){
	FILE* arq;
	arq = fopen(texto, "r");
	if(arq == NULL){
	printf("ERRO NA LEITURA DO ARQUIVO!\n");
	exit(1);
	}
	return arq;
}
