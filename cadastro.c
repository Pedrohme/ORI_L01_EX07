#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "aluno.h"
#include "lista.h"
#include "cadastro.h"

int inicializar(FILE *cad, char nome[], lista *alunos) {
    if (strcmp(nome, "Alunos.dat")) {
        printf("nome do arquivo não aceito, espera-se \"Alunos.dat\"\n");
        return 0;
    }
    else if ( (cad = fopen(nome, "r+")) == NULL ) {
        printf("Arquivo inexistente ou impossível de ser aberto, deseja criar um novo arquivo de cadastros?\nS/N : ");
        char input = 'a';
        while (1) {
            scanf(" %c", &input);
            input = tolower(input);
            if (input != 's' && input != 'n') {
                printf("\nOpcao invalida\nS/N : ");
            }
            else {
                break;
            }
        }
        if (input == 'n') {
            printf("\nFinalizando programa\n");
            return 0;
        }
        else {
            cad = fopen(nome, "w+");
        }
    }
    if (cad != NULL) {
        return arqParaMem(cad, alunos);
    }
    else {
        printf ("ocorreu um erro\n");
        return 0;
    }
}

int arqParaMem(FILE *cad, lista *alunos) {
    int retScan = 0;
    struct aluno al;
    while ( (retScan = (fscanf(cad, "%d@%100[^@]@%d@%d", &al.RA, al.nome, &al.anoIngresso, &al.credCursados))) == 4) {
        l_insere(alunos, al);
    }
    if (feof(cad) && retScan == -1) {
        printf("Arquivo lido com sucesso!\n");
        return 1;
    }
    else {
        printf("Houve um erro ao ler o arquivo, terminando programa...\n");
        return 0;
    }
}

void menu(FILE *cad, lista *alunos) {
    int input = 0;
    while (input != 6) {
        printf("\nMENU\n");
        printf("1. Cadastrar\n");
        printf("2. Alterar\n");
        printf("3. Remover\n");
        printf("4. Buscar\n");
        printf("5. listar\n");
        printf("6. Sair\n");
        scanf(" %d", &input);
        printf("\n");

        switch (input) {
        case 1:
            cadastrar(alunos);
            break;
        case 2:
            alterar(alunos);
            break;
        case 3:
            remover(alunos);
            break;
        case 4:
            buscar(alunos);
            break;
        case 5:
            listar(alunos);
            break;
        case 6:
            sair(cad, alunos);
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    }
}

void cadastrar(lista *alunos) {
    lista_iterador it;
    struct aluno aux;

    printf("Insira os dados do aluno.\n");
    printf("RA: ");
    if ( (aux.RA = intInput()) <= -1) {
        printf("Valor inválido.\n");
        printf("RA: ");
        if ( (aux.RA = intInput()) <= -1) {
            printf("Valor inválido. Voltando para o menu.\n");
            return;
        }
    }

    it = l_procuraPrimeiro(alunos, aux);
    if (!l_acabou(it)) {
        printf("Aluno ja cadastrado\n");
        return;
    }

    printf("nome: ");
    scanf(" %100[^\n]", aux.nome);
    
    printf("Ano de ingresso: ");
    if ( (aux.anoIngresso = intInput()) <= -1) {
        printf("Valor inválido.\n");
        printf("Ano de ingresso: ");
        if ( (aux.anoIngresso = intInput()) <= -1) {
            printf("Valor inválido. Voltando para o menu.\n");
            return;
        } 
    }

    printf("Quantidade de créditos cursados: ");
    if ( (aux.credCursados = intInput()) <= -1) {
        printf("Valor inválido.\n");
        printf("Quantidade de créditos cursados: ");
        if ( (aux.credCursados = intInput()) <= -1) {
            printf("Valor inválido. Voltando para o menu.\n");
            return;
        } 
    }

    l_insere(alunos, aux);
}
void alterar(lista *alunos) {
    printf("alterar\n");
}
void remover(lista *alunos) {
    printf("remover\n");
}
void buscar(lista *alunos) {
    printf("buscar\n");
}
void listar(lista *alunos) {
    printf("listar\n");
}
void sair(FILE *cad, lista *alunos) {
    printf("sair\n");
}

int intInput() {
    char str[64];

    scanf("%63s", str);

    char *endptr;
    int num = (int)strtol(str, &endptr, 10);

    if (endptr == str) {
        return -1;
    }
    else if (*endptr != '\0') {
        return -1;
    }
    else {
        return num;
    }
}