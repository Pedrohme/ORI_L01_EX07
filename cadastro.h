#ifndef CADASTRO_H
#define CADASTRO_H

#include <stdio.h>
#include "lista.h"

int inicializar(FILE *cad, char nome[], lista *alunos);
int arqParaMem(FILE *cad, lista *alunos);
void menu(FILE *cad);
void cadastrar(FILE *cad);
void alterar(FILE *cad);
void remover(FILE *cad);
void buscar(FILE *cad);
void listar(FILE *cad);
void sair(FILE *cad);

#endif