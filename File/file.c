#include "file.h"

int read_file(int *vector, const char *file_name, int max_N) {
    FILE *arc = fopen(file_name, "r");
    
    // 1. Verificação de erro ao abrir o arquivo
    if (arc == NULL) {
        fprintf(stderr, "ERRO: Não foi possível abrir o ficheiro para leitura: %s\n", file_name);
        return 0;
    }
    
    int i = 0;
    
    // 2. Leitura correta: O ciclo continua APENAS se:
    //    a) fscanf ler exatamente 1 item (o número inteiro).
    //    b) o índice 'i' não exceder o limite do vetor (max_N).
    while (i < max_N && fscanf(arc, "%d", &vector[i]) == 1) {
        i++;
    }

    // 3. Fechamento do arquivo
    if (fclose(arc) != 0) {
        fprintf(stderr, "AVISO: Erro ao fechar o ficheiro de leitura: %s\n", file_name);
    }
    
    // 4. Retorna o número total de elementos que foram lidos e armazenados
    return i;
}

int write_file(const int *vector, const char *file_name, int N) {
    // 1. Abertura do ficheiro no modo de escrita ("w")
    // O modo "w" cria o ficheiro se não existir ou apaga o conteúdo se existir.
    FILE *arc = fopen(file_name, "w"); 
    
    // 2. Verificação de erro
    if (arc == NULL) {
        fprintf(stderr, "ERRO: Não foi possível abrir o ficheiro para escrita: %s\n", file_name);
        return -1;
    }
    
    // 3. Escrita dos elementos no ficheiro
    for (int i = 0; i < N; i++) {
        // Escreve cada número seguido de um espaço.
        fprintf(arc, "%d ", vector[i]); 
        // Escreve cada número seguido de uma quebra de linha.
        // fprintf(arc, "%d\n", vector[i]); 
    }

    // 4. Fechamento do arquivo
    if (fclose(arc) != 0) {
        fprintf(stderr, "AVISO: Erro ao fechar o ficheiro de escrita: %s\n", file_name);
        // Não é um erro fatal para a escrita, mas é um aviso útil
    }
    
    return 0;
}