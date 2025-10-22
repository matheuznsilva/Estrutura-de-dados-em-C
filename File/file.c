#include "file.h"

FILE* open_file(char text[SIZE]){
	FILE* arc;
	arc = fopen(text, "r");
	if(arc == NULL){
	    printf("ERROR 404! - FILE NOT FOUND\n");
	}
	return arc;
}

void read_file(int *vector, char text[SIZE]){
	FILE *arc = open_file(text);
	int i = 0;
	while(!feof(arc)){
		fscanf(arc, "%d", &vector[i]);
		i++;
	}
	fclose(arc);
}

void write_file(int *vector, char text[SIZE], int N){
	FILE *arc = open_file(text);
	int i = 0;
	while(i < N){
		fprintf(arc, "%d ", vector[i]);
		i++;
	}
	fclose(arc);
}