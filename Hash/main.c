#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ListaDinEncad.h"
#include "hash.h"
#include "arquivo.h"
#define TAMANHO 997
//#define MAX 20

int main(){

	struct arquivo B, T;
	int aux, i, j=0, k=0, linha=1;
	char texto[MAX], palavra[MAX], c;

	
	Hash *ha;

do{
		system("clear");

		// --------- MENU --------- //
		printf("\n------ BEM VINDO À INDEXAÇÃO DE PALAVRAS EM TEXTOS ------\n\n" 
		"1 - CRIAR TABELA\n" 
		"2 - INSERIR TEXTO (texto txt)\n" 
		"3 - BUSCAR PALAVRA\n"
		"4 - IMPRIMIR TABELA\n"
		"5 - APAGAR TABELA\n"

		"0 - SAIR\n"
		"\nDigite sua escolha: ");		// solicita ao usuário que digite a opção escolhida
		setbuf(stdin, NULL);		// limpa o buffer do teclado
		scanf("%d", &i);		// recebe a opção digitada
		system("clear");		// função utilizada para limpar a tela

		switch(i){
			case 1:{		// criação da lista
				
				ha = criaHash(TAMANHO);		// chamada da função de criação da Hash
				printf("\nDeseja voltar ao menu? (1 - SIM / 0 - NÃO): ");		// pergunta ao usuário se ele deseja continuar no programa
				setbuf(stdin, NULL);		// limpa o buffer do teclado
				scanf("%d", &i);		// recebe a opção digitada
					
				break;		// ponto de fuga do case
			}

			case 2:{		// inserção de elemento na lista
			
				system("clear");
				printf("ENTRE COM O NOME DO ARQUIVO: ");
				setbuf(stdin, NULL);
   				scanf("%s", texto);

				FILE* arq = abrir_arquivo(texto);
				
				while(!feof(arq)){	
					fscanf(arq,"%s", B.str);
					//fputs(B.str, stdout);
                    aux = insere_Hash(ha, B);
				}

				//printf("\n%d", linha-1);					

				system("clear");		// função utilizada para limpar a tela
				if(aux == 1){		// confere se o ocorreu a inserção do elemento
					printf("\nTEXTO INSERIDO COM SUCESSO!\n");		// informa que o elemento foi inserido
				} 
				
				printf("\nDeseja voltar ao menu? (1 - SIM / 0 - NÃO): ");		// pergunta ao usuário se ele deseja continuar no programa
				scanf("%d", &i);		// recebe a opção digitada
					
				break;		// ponto de fuga do case
			}

			case 3: {		// busca elemento na lista

				printf("\nENTRE COM A PALAVRA A SER PROCURADA: ");		// solicita ao usuário que digite a matricula procurada
				setbuf(stdin, NULL);		// limpa o buffer do teclado
				scanf("%s", B.str);

				system("clear");		// função utilizada para limpar a tela

				aux = busca_Hash(ha, B);

				if(aux == 0){
					printf("\nPALAVRA NÃO ENCONTRADA\n");
				}

				printf("\nDeseja voltar ao menu? (1 - SIM / 0 - NÃO): ");		// pergunta ao usuário se ele deseja continuar no programa
				scanf("%d", &i);		// recebe a opção digitada
				
				break;		// ponto de fuga do case
			}

			case 4:{		// remove elemento na lista

				imprime_Hash(ha);
			
				printf("\nDeseja voltar ao menu? (1 - SIM / 0 - NÃO): ");		// pergunta ao usuário se ele deseja continuar no programa
				scanf("%d", &i);		// recebe a opção digitada
				
				break;		// ponto de fuga do case

			}

			case 5:{		// impressão da lista

				liberaHash(ha);
				printf("\nTABELA APAGADA COM EXITO\n");		// informado que a lista foi apagada
				
				printf("\nDeseja voltar ao menu? (1 - SIM / 0 - NÃO): ");		// pergunta ao usuário se ele deseja continuar no programa
				scanf("%d", &i);		// recebe a opção digitada
				
				break;		// ponto de fuga do case

			}

			case 0:{
				
				break;		// ponto de fuga do case
			}

			default:{
				printf("\nOPÇÃO INCORRETA\n");		// informa que a opção digitada pelo usuário não existe
				printf("\nDeseja voltar ao menu? (1 - SIM / 0 - NÃO): ");		// pergunta ao usuário se ele deseja continuar no programa
				scanf("%d", &i);		// recebe a opção digitada
				
				break;		// ponto de fuga do case
			}

		}

	}while(i!=0);

	system("clear");		// função utilizada para limpar a tela
	printf("\nOBRIGADO POR UTILIZAR ESSE PROGRAMA\n\n");		// agradece ao usuário por ter utilizado o programa
	sleep(2);		// função que faz o programa parar por 2 segundos
	liberaHash(ha);		// chamada da função de destruição da tabela
	system("clear");		// função utilizada para limpar a tela
	
	//fclose(arq);
	}
