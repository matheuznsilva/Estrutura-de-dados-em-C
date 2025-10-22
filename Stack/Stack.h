struct data{		// struct do tipo dado, basicamente onde é armazenado os dados inseridos na pilha
	float NUMBER;		// variável onde será armasenado o dado do tipo float  
};

typedef struct element* Stack;

// DECLARACAO DAS FUNCOES BASICAS DA PILHA

Stack* createStack();
void freeStack(Stack* ST);
int accessTopStack(Stack* ST, struct data *DT);
int insertStack(Stack* ST, struct data DT);
int removeStack(Stack* ST);
int sizeStack(Stack* ST);
int emptyStack(Stack* ST);