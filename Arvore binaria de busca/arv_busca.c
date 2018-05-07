#include <stdio.h>
#include <stdlib.h>
#include "arv_busca.h"

Arv* abb_cria(void)
{
    Arv* arv = (Arv*) malloc(sizeof(Arv));
    arv->raiz = NULL;
    return arv;
}

void imprime(Arv*arv, int escolha)
{
    imprime_no(arv->raiz, escolha);
}

void imprime_no(Nodo*r, int escolha)
{
    if(escolha == 1)
        imprime_pre(r);
    else if(escolha == 2)
        imprime_in(r);
    else if(escolha == 3)
        imprime_pos(r);
    else
        printf("Escolha invalida\n");
}

void imprime_pre(Nodo*r)
{
    if(r != NULL)
    {
        printf("%d\t", r->info);
        imprime_pre(r->esq);
        imprime_pre(r->dir);
    }

}

void imprime_in(Nodo*r)
{
    if(r != NULL)
    {
        imprime_pre(r->esq);
        printf("%d\t", r->info);
        imprime_pre(r->dir);
    }

}

void imprime_pos(Nodo*r)
{
    if(r != NULL)
    {
        imprime_pre(r->esq);
        imprime_pre(r->dir);
        printf("%d\t", r->info);
    }
}

void libera(Arv* arv)
{
    libera_no(arv->raiz);
    free(arv);
}

void libera_no(Nodo*r)
{
    if(r != NULL)
    {
        libera_no(r->esq);
        libera_no(r->dir);
        free(r);
    }
}

Nodo* busca_no(Nodo* r, int i)
{
    if(r == NULL || r->info == i)
        return r;
    if(i < r->info)
        return busca_no(r->esq,i);
    else
        return busca_no(r->dir,i);
}
///BUSCA ITERATIVA
Nodo* busca_no_interativa(Nodo* r, int i)
{
    while(r != NULL && r->info != i)
    {
        if(i<r->info)
            r = r->esq;
        else
            r = r->dir;
    }
    return r;
}

void insere(Arv* arv, int k)
{
    arv->raiz = insere_no(arv->raiz, k);
}

Nodo* insere_no(Nodo*r, int k)
{
    if(r == NULL)
    {
        r = (Nodo*) malloc(sizeof(Nodo));
        r->info = k;
        r->dir = r->esq = NULL;
    }
    else if(k > r->info)
        r->dir = insere_no(r->dir, k);
    else if(k < r->info)
        r->esq = insere_no(r->esq, k);
    else
        return r;
}

void remover_arv(Arv*arv, int key)
{
    arv->raiz = remover_no(arv->raiz, key);
}

Nodo*remover_no(Nodo*raiz, int key)
{
    if(raiz == NULL)
        return NULL;

    else if(key < raiz->info)
        raiz->esq = remover_no(raiz->esq, key);

    else if(key > raiz->info)
        raiz->dir = remover_no(raiz->dir, key);

    else
    {
        ///sem filhos
        if(raiz->dir == NULL && raiz->esq == NULL)
        {
            free(raiz);
            raiz = NULL;
        }
        ///um filho a direita
        else if(raiz->esq == NULL)
        {
            Nodo*aux = raiz->dir;
            free(raiz);
            raiz = aux;
        }
        ///um filho a esquerda
        else if(raiz->dir == NULL)
        {
            Nodo*aux = raiz;
            free(raiz);
            raiz = aux;
        }
        /// tem dois filhos;
        else
        {
            Nodo* p = raiz->esq;
            while(p->dir != NULL)
                p = p->dir;
            raiz->info = p->info;
            p->info = key;
            raiz->esq = remover_no(raiz->esq, key);
        }
    }

    if(raiz == NULL)
        return raiz;
}
