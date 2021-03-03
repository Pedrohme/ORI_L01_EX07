/*  Organização e recuperação da informação - Lista 01
    Exercício 07
    Aluno: Pedro Henrique Mendes  */

#include <stdio.h>
#include "aluno.h"
#include "lista.h"
#include "cadastro.h"

int compare(struct aluno a1, struct aluno a2) {
    if (a1.RA < a2.RA)
        return -1;
    else if (a1.RA > a2.RA)
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[]) {
    FILE *cad;
    lista alunos;

    if (argc == 2) {
        l_inicializa(&alunos, compare);
        if (inicializar(cad, argv[1], &alunos) == 1) {
            menu(cad, &alunos);
        }
    }
    else {
        printf("chamada incorreta do programa\n");
    }

    if (cad != NULL) {
        fclose(cad);
    }
    if (l_inicializada(&alunos)) {
        l_destroi(&alunos);
    }

    return 0;
}