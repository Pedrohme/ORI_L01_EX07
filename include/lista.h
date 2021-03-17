#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include "aluno.h"

/*!
 * Tipo do elemento armazenado na lista
 */
typedef struct aluno lista_item;

struct lista_no_struct {
	lista_item item;
	struct lista_no_struct* prox;
	struct lista_no_struct* ant;
};
typedef struct lista_no_struct lista_no;


struct lista_struct {
    int (*compara)( lista_item i1, lista_item i2);
	unsigned quantidade;
	lista_no* sentinela;
};
typedef struct lista_struct lista;

/*! Iterador da lista, faz referencia a um elemento
 *  
 */
struct lista_iterador_struct {
    lista_no* p;
    lista* l;
};
typedef struct lista_iterador_struct lista_iterador;

/*! Inicializa uma lista ordenada. Primeiro procedimento a ser
 *  chamado para permitir o uso da lista.
 *  
 * \param l Endereco da lista a ser inicializada
 * \param m Funcao que compara dois elementos da lista.
 * 			Esta função deve retornar:
 * 			-1, caso i1<i2;
 * 			0, caso i1=i2;
 * 			1, caso i1>i2.
 *  
 */
void l_inicializa( lista* l, int (*cmp)( lista_item i1, lista_item i2));

//checa se a lista foi inicializada
int l_inicializada(lista* l);

/*! Desaloca uma lista. Ultimo procedimento a ser chamado.
 * 
 * \param l Endereco da lista a ser desalocada
 *  
 */
void l_destroi(lista* l);

/*!
 * Verifica se uma lista esta ou nao vazia.
 * 
 * \param d Endereço da lista
 * \return Verdadeiro (diferente de zero) se a lista estiver vazia
 * 
 */
int l_vazia(lista* l);

/*! Insere um determinado elemento na lista ordenada. O novo elemento será inserido antes dos elementos maiores ou iguais.
 * 
 * \param l Endereco da lista
 * \param item Elemento a ser inserido
 *  
 */
void l_insere(lista* l, lista_item item);

/*! Remove todas as ocorrencias de um determinado elemento na lista ordenada, se existirem.
 * 
 * \param l Endereco da lista
 * \param item Elemento a ser removido
 *  
 */
void l_retira(lista* l, lista_item item);

/*!
 * Retorna um iterador para o elemento do inicio da lista, se houver.
 * 
 * \param l Endereço da lista
 * \return Iterador para o menor elemento da lista, se houver
 * 
 */
lista_iterador l_primeiro(lista* l);

/*!
 * Retorna um iterador para o elemento do final da lista, se houver.
 * 
 * \param l Endereço da lista
 * \return Iterador para o maior elemento da lista, se houver
 * 
 */
lista_iterador l_ultimo(lista* l);

/*!
 * Retorna o elemento referenciado pelo iterador, se houver
 * 
 * \param i Iterador
 * \return Elemento da lista, se houver
 * 
 */
lista_item l_elemento(lista_iterador i);

/*!
 * Avanca o iterador e retorna verdadeiro caso nao seja o final da lista
 * 
 * \param i Endereco do Iterador
 * \return Falso caso nao tenha um proximo elemento
 * 
 */
int l_proximo(lista_iterador* i);

/*!
 * Retrocede o iterador e retorna verdadeiro caso nao seja o inicio da lista
 * 
 * \param i Endereco do Iterador
 * \return Falso caso nao tenha um elemento anterior
 * 
 */
int l_anterior(lista_iterador* i);

/*!
 * Retorna se o elemento referenciado pelo iterador existe
 * 
 * \param i Iterador
 * \return Falso caso o iterador nao aponte para um elemento
 * 
 */
int l_acabou(lista_iterador i);

/*!
 * Procura por um determinado elemento e retorna um iterador para a
 * primeira ocorrencia. 
 * 
 * \param l Endereco da lista
 * \param item Elemento a ser procurado
 * \return Iterador para a primeira ocorrencia, se existir. Caso não encontre, o iterador terá acabou() verdadeiro.
 * 
 */
lista_iterador l_procuraPrimeiro(lista* l, lista_item item);

/*!
 * Procura pelo teto de um determinado elemento e retorna um iterador para a
 * primeira ocorrencia. O teto de um elemento é o menor elemento dentre os maiores 
 * ou iguais a ele.
 * 
 * \param l Endereco da lista
 * \param item Elemento a ser procurado
 * \return Iterador para a primeira ocorrencia do teto, se existir. Caso não exista,
 * 		    o iterador terá acabou() verdadeiro.
 * 
 */
lista_iterador l_procuraTeto(lista* l, lista_item item);

/*!
 * Procura pelo piso de um determinado elemento e retorna um iterador para a
 * última ocorrencia. O piso de um elemento é o maior elemento dentre os menores 
 * ou iguais a ele.
 * 
 * \param l Endereco da lista
 * \param item Elemento a ser procurado
 * \return Iterador para a última ocorrencia do piso, se existir. Caso não exista,
 * 		    o iterador terá acabou() verdadeiro.
 * 
 */
lista_iterador l_procuraPiso(lista* l, lista_item item);

#endif

 
