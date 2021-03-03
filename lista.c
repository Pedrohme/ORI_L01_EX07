#include <stdlib.h>
#include "lista.h"

void l_inicializa( lista* l, int (*cmp)( lista_item i1, lista_item i2)) {
	l->sentinela = (lista_no*)malloc(sizeof(lista_no));
    if (!l->sentinela) 
		return;
    l->sentinela->prox = l->sentinela->ant = l->sentinela;
    l->compara = cmp;
}

int l_inicializada(lista* l) {
	if (l->sentinela == NULL)
		return 0;
	else
		return 1;
}

void l_destroi(lista* l) {
	while(!l_vazia(l))
		l_retira(l, l_elemento(l_primeiro(l)));
	free(l->sentinela);
}

int l_vazia(lista* l) {
	return l->sentinela->prox == l->sentinela;
}

void l_insere(lista* l, lista_item item) {
	lista_iterador it = l_procuraTeto(l,item);
	lista_no* novo = (lista_no*)malloc(sizeof(lista_no));
	novo->item = item;
	novo->prox = it.p;
	novo->ant = it.p->ant;
	it.p->ant = novo;
	novo->ant->prox = novo;
	l->quantidade++;
}

void l_retira(lista* l, lista_item item) {
	/* Procura a primeira ocorrencia do item passado utilizando um iterador, a partir dele, itera e retira todos os valores
	   iguais ao modificar os proximos e anteriores dos elementos, e libera a memória alocada */
	if(!l_vazia(l))
	{
		lista_iterador it = l_procuraPrimeiro(l, item);
		if (l_acabou(it))
			return;
		while(!l_acabou(it) && l->compara(l_elemento(it), item) == 0)
		{
			lista_no *n = it.p;
			l_proximo(&it);
			n->ant->prox = n->prox;
			n->prox->ant = n->ant;
			free(n);
		}
	}
}

lista_iterador l_primeiro(lista* l) {
	lista_iterador it;
	it.l = l;
	it.p = l->sentinela->prox;
	return it;
}

lista_iterador l_ultimo(lista* l) {
	lista_iterador it;
	it.l = l;
	it.p = l->sentinela->ant;
	return it;
}
lista_item l_elemento(lista_iterador i) {
	return i.p->item;
}

int l_proximo(lista_iterador* i) {
	if( !l_acabou(*i) ) {
		i->p = i->p->prox;
		return 1;
	}
	return 0;
}

int l_anterior(lista_iterador* i) {
	if( !l_acabou(*i) ) {
		i->p = i->p->ant;
		return 1;
	}
	return 0;
}

int l_acabou(lista_iterador i) {
	return i.p == i.l->sentinela;
}

lista_iterador l_procuraPrimeiro(lista* l, lista_item item) {
	lista_iterador it = l_procuraTeto(l,item);
	if(!l_acabou(it) && l->compara(l_elemento(it),item) != 0 ) {
		it.p = l->sentinela;
	}
	return it;
}

lista_iterador l_procuraTeto(lista* l, lista_item item) {
	/* um iterador começa no primeiro elemento da lista e itera por cada elemento até encontrar o primeiro valor >= ao item passado.
	   retorna o iterador. */
	l->sentinela->item = item;
	lista_iterador it = l_primeiro(l);
	while ( l->compara(l_elemento(it), item) == -1 )
	{
		l_proximo(&it);
	}
	return it;
}

lista_iterador l_procuraPiso(lista* l, lista_item item) {
	l->sentinela->item = item;
	lista_iterador it = l_ultimo(l);
	while( l->compara( l_elemento(it), item ) == 1 ) {
		l_anterior(&it);
	}
	return it;
}
