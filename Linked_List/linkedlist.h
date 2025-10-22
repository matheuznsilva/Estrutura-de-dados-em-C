
#define MAX 100 

// STRUCT ONDE SERÃO ARMAZENADOS OS DADOS
struct data{		
	int num;		
	char name[MAX];		
	float n1, n2, n3, average;		
};

typedef struct element* List; // padronização do nome do ponteiro tipo lista

List* create_list();	// criação da lista
void free_list(List* LI);		// função de destruição da lista
int search_list_pos(List* LI, int pos, struct data *DT);		// função de busca do elemento pela posição
int search_list_num(List* LI, int num, struct data *DT);		// função de busca do elemento pela matricula
int insert_end_list(List* LI, struct data DT);		// função de inserção ao final da lista
int insert_start_list(List* LI, struct data DT);		// função de inserção no inicio da lista
int insert_sorted_list(List* LI, struct data DT);		// função de inserção de forma ordenada
int remove_list(List* LI, int num);		// função de remoção de um elemento especifico
int remove_start_list(List* LI);		// função de remoção de um elemento no inicio da lista
int remove_end_list(List* LI);		// função de remoção de um elemento ao final da lista
int size_list(List* LI);		// função que retorna o tamanho da lista
int full_list(List *LI);		// função que retorna se a lista esta cheia
int empty_list(List* LI);		// função que retorna se a lista esta vazia
void print_list(List* LI);		// função que imprime a lista
