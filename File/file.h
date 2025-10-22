#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

FILE* open_file(char text[SIZE]);

void read_file(int *vector, char text[SIZE]);

void write_file(int *vector, char text[SIZE], int N);