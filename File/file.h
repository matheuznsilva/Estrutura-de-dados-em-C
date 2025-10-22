#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // Para size_t

// O tamanho máximo do nome do ficheiro, se for necessário, mas 
// é melhor definir fora do cabeçalho se não for um limite constante. 
#define SIZE 50

/**
 - Lê números inteiros de um ficheiro de texto e armazena-os num vetor.
 - vector - Ponteiro para o vetor onde os inteiros serão armazenados.
 - file_name - Nome (caminho) do ficheiro a ser lido.
 - max_N - O número máximo de elementos a ler (tamanho alocado do vetor).
 */
int read_file(int *vector, const char *file_name, int max_N);

/**
 - Escreve os números inteiros de um vetor para um ficheiro de texto.
 - vector - Ponteiro para o vetor que contém os inteiros a serem escritos.
 - file_name - Nome (caminho) do ficheiro para onde será escrito.
 - N - O número de elementos a escrever.
 */
int write_file(const int *vector, const char *file_name, int N);

#endif // FILE_H