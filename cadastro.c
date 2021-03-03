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
        insere(alunos, al);
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

void menu(FILE *cad) {
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
            cadastrar(cad);
            break;
        case 2:
            alterar(cad);
            break;
        case 3:
            remover(cad);
            break;
        case 4:
            buscar(cad);
            break;
        case 5:
            listar(cad);
            break;
        case 6:
            sair(cad);
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    }
}

void cadastrar(FILE *cad) {
    printf("cadastrar\n");
}
void alterar(FILE *cad) {
    printf("alterar\n");
}
void remover(FILE *cad) {
    printf("remover\n");
}
void buscar(FILE *cad) {
    printf("buscar\n");
}
void listar(FILE *cad) {
    printf("listar\n");
}
void sair(FILE *cad) {
    printf("sair\n");
}