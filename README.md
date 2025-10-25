# Estruturas de Dados Essenciais em C

Este repositório é uma coleção de implementações de estruturas de dados e algoritmos fundamentais em **C**. O objetivo é fornecer código claro e modular para referência e estudo.

## Algoritmos Incluídos

Atualmente, o repositório contém as seguintes estruturas de dados e algoritmos:

| Estrutura/Algoritmo | Descrição | Implementação em |
| :--- | :--- | :--- |
| **Lista Encadeada** (`Linked_List/`) | Implementação básica de listas ligadas para inserção, remoção e travessia de elementos. | C |
| **Pilha** (`Stack/`) | Estrutura de dados *Last-In, First-Out* (LIFO) com as operações padrão `push` e `pop`. | C |
| **Tabela Hash** (`Hash/`) | Implementação de Tabela Hash para armazenamento e recuperação eficiente de dados, utilizando um método de tratamento de colisões. | C |
| **Manipulação de Arquivos** (`File/`) | Funções utilitárias para lidar com operações de arquivos (leitura e escrita), facilitando a interação dos algoritmos com o sistema de arquivos. | C |

## Estrutura do Projeto

A estrutura de pastas do repositório foi organizada para modularizar cada estrutura de dados, facilitando a navegação e a inclusão em seus projetos:

## Estrutura do Projeto:

A estrutura de pastas do repositório foi organizada para facilitar a utilização:
```
.
└── Estrutura de dados em C/
        ├── Binary_Tree/    # Possui algoritmo de Arvore Binaria
        ├── File/           # Possui algoritmo de manipulação de arquivos
        ├── Hash/           # Possui algoritmo de Tabela Hash
        ├── Linked_List/    # Possui algoritmo de Lista Encadeada
        ├── Makefile/       # Possui Exemplo de makefile
        ├── Stack/          # Possui algoritmo de Pilha
        ├── LICENSE
        └── README.md

```
## Configuração e Execução

Para utilizar qualquer um dos algoritmos em seu projeto, siga os passos básicos abaixo:

### Pré-requisitos
* gcc (GNU Compiler Collection)

### Passo 1
Adicione os arquivos de cabeçalho (`.h`) e de código-fonte (`.c`) das bibliotecas desejadas (ex: `Linked_List/`) no diretório da sua aplicação principal.

### Passo 2
No seu código principal (`main.c` ou similar), importe a biblioteca usando a diretiva `#include`:
```c
#include "nome_da_biblioteca.h" 
// Exemplo: #include "linked_list.h"
```
Após a inclusão, declare a variável do tipo da estrutura para começar a utilizá-la e acessar suas funções.

### Passo 3
Compile e execute o seu projeto usando o gcc, garantindo que você inclua todos os arquivos .c necessários.

## Licença
Este projeto está sob a licença MIT License.

## Contato
Desenvolvido por Matheus Nascimento Silva. Sinta-se à vontade para entrar em contato ou contribuir!

LinkedIn: https://www.linkedin.com/in/matheuznsilva/

GitHub: https://github.com/matheuznsilva