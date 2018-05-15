#include <stdio.h>
#include <stdlib.h>
#include "arvoreRB.h"

Arv* ARB_cria(void)
{
    Arv* arv = (Arv*) malloc(sizeof(Arv));
    arv->raiz = NULL;
    return arv;
}

Nodo*criar_nodo(int info)
{
    Nodo*novo = (Nodo*) malloc(sizeof(Nodo));
    novo->esq = novo->dir = novo->p = NULL;
    novo->info = info;
    novo->color = RED;
    return novo;
}

void inserir(Arv*t, int info)
{
    Nodo*z = criar_nodo(info);
    rb_insert(t, z);
}

void rb_insert(Arv*t, Nodo*z)
{
    Nodo*y = NULL;
    Nodo*x = t->raiz;

    while( x != NULL)
    {
        y = x;
        if(z->info < x->info)
            x = x->esq;
        else
            x = x->dir;
    }
    z->p = y;

    if(y == NULL)
        t->raiz = z;
    else if(z->info < y->info)
        y->esq = z;
    else y->dir = z;

    z->esq = z->dir = NULL;
    z->color = RED;
    rb_fix_up_insert(t, z);
}

void rb_fix_up_insert(Arv*t, Nodo*z)
{
    while(z != t->raiz &&(z->color != BLACK && z->p->color == RED))
    {
        if(z->p == z->p->p->esq)
        {
            Nodo*y = z->p->p->dir;
            if(z->p->p->dir != NULL && y->color == RED)
            {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else
            {
                if(z == z->p->dir)
                {
                    z = z->p;
                    leftRotate(t,z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                rightRotate(t, z->p->p);
            }
        }
        else
        {
            Nodo*y = z->p->p->esq;
            if(z->p->p->esq != NULL && y->color == RED)
            {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else
            {
                if(z == z->p->esq)
                {
                    z = z->p;
                    rightRotate(t,z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                leftRotate(t, z->p->p);
            }
        }
    }
    t->raiz->color = BLACK;
}

void leftRotate(Arv*t, Nodo*x)
{
    Nodo*y = x->dir;
    x->dir = y->esq;

    if(y->esq != NULL)
        y->esq->p = x;
    y->p = x->p;
    if(x->p == NULL)
        t->raiz = y;
    else if(x == x->p->esq)
        x->p->esq = y;
    else
        x->p->dir = y;
    y->esq = x;
    x->p = y;
}

void rightRotate(Arv*t,Nodo*x)
{
    Nodo*y = x->esq;
    x->esq = y->dir;

    if(y->dir != NULL)
        y->dir->p = x;
    y->p = x->p;
    if(x->p == NULL)
        t->raiz = y;
    else if(x->p->dir == x)
        x->p->dir = y;
    else
        x->p->esq = y;
    y->dir = x;
    x->p = y;
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
{    while(r != NULL && r->info != i)
    {
        if(i<r->info)
            r = r->esq;
        else
            r = r->dir;
    }
    return r;
}
