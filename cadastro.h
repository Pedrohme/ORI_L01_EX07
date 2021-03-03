#ifndef CADASTRO_H
#define CADASTRO_H

#include <stdio.h>
#include "lista.h"

//Le o arquivo de cadastros, ou cria um novo caso não exista, entao passa os dados para uma lista encadeada ordenada durante a execucao do programa
int inicializar(FILE **cad, char nome[], lista *alunos);
//Funcao auxiliar para passar os dados do arquivo para a memoria primaria
int arqParaMem(FILE **cad, lista *alunos);

//Menu principal de opcoes
void menu(FILE **cad, lista *alunos);

//solicita todos os dados do aluno, caso o RA informado ja exista, informa que já está cadastrado e retorna ao menu
void cadastrar(lista *alunos);

//solicita o RA do aluno, caso seja encontrado, solicita as informacoes para atualizar. Caso nao econtrado, informa e retorna ao menu
void alterar(lista *alunos);

//solicita o RA do aluno, caso seja encontrado, remove o registro. Caso nao econtrado, informa e retorna ao menu
void remover(lista *alunos);

//solicita o RA do aluno, caso seja encontrado, exibe todos os campos do registro. Caso nao encontrado, informa e retorna ao menu
void buscar(lista *alunos);

//imprime na tela todos os campos de todos os registros em ordem crescente
void listar(lista *alunos);

//sobrescreve o arquivo com dados atualizados, libera a memoria e fecha o programa
void sair(FILE **cad, lista *alunos);

//funcao para receber um int
int intInput();

#endif