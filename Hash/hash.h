struct word{
	Lista *li;
	int contador;
};

typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);

void liberaHash(Hash* ha);

int valorString(char *str);

int chaveDiv(int chave, int TABLE_SIZE);

int insere_Hash(Hash* ha, struct arquivo ar);

int busca_Hash(Hash* ha, struct arquivo ar);

int imprime_Hash(Hash* ha);
