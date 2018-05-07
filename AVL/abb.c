#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

Arv_avl* abb_cria(void)
{
    Arv_avl* arv = (Arv_avl*) malloc(sizeof(Arv_avl));
    arv->raiz = NULL;
    return arv;
}

Nodo* novo_nodo(int info)
{
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    novo->info = info;
    novo->esq = novo->dir = NULL;
    novo->altura = 0;
    return(novo);
}

void imprime(Arv_avl*arv, int escolha)
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

void libera(Arv_avl* arv)
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

int altura(Nodo*a)
{
    if(a == NULL)
    {
        return -1;
    }
    return a->altura;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

void abb_insere(Arv_avl*arv, int i)
{
    arv->raiz = abb_insere_no(arv->raiz, i);
}

Nodo* abb_insere_no(Nodo*r, int i)
{
    if(r == NULL)
    {
        return(novo_nodo(i));
    }
    if(i < r->info)
        r->esq = abb_insere_no(r->esq, i);
    else if(i > r->info)
        r->dir = abb_insere_no(r->dir, i);
    else
        return r;

    r->altura = 1 + max(altura(r->esq), altura(r->dir));

    int fator_balanceamento = calc_fb(r);
    ///CASOS
    ///left left
    if(fator_balanceamento < -1 && i < r->esq->info)
        return dirRotate(r);
    ///right right
    if(fator_balanceamento > 1 && i > r->dir->info)
        return esqRotate(r);
    ///left right
    if(fator_balanceamento < -1 && i > r->esq->info)
    {
        r->esq = esqRotate(r->esq);
        return dirRotate(r);
    }
    ///right left
    if(fator_balanceamento > 1 && i < r->dir->info)
    {
        r->dir = dirRotate(r->dir);
        return esqRotate(r);
    }
    return r;
}

void remover(Arv_avl* arv, int i)
{
    arv->raiz = remover_no(arv->raiz, i);
}

Nodo* remover_no(Nodo*r, int i)
{
    if(r == NULL)
        return NULL;
    else if(i < r->info)
        r->esq = remover_no(r->esq, i);
    else if(i > r->info)
        r->dir = remover_no(r->dir, i);
    else
    {
        ///no kids
        if(r->esq == NULL && r->dir == NULL)
        {
            free(r);
            r = NULL;
        }
        ///one kid to the right
        else if(r->esq == NULL)
        {
            Nodo*aux = r;
            r = r->dir;
            free(aux);
        }
        ///one kid to the left
        else if(r->dir == NULL)
        {
            Nodo*aux = r;
            r = r->esq;
            free(aux);
        }
        ///deux enfants
        else
        {
            Nodo*aux = r->esq;
            while(aux->dir != NULL)
            {
                aux = aux->dir;
            }
            r->info = aux->info;
            aux->info = i;
            r->esq = remover_no(r->info, i);
        }
    }

    if(r == NULL)
        return r;

    r->altura = 1 + max(altura(r->esq), altura(r->dir));

    int fator_balaceamento = calc_fb(r);

    ///left left case
    if(fator_balaceamento < -1 && calc_fb(r->esq) <= 0)
        return dirRotate(r);
    ///left right case
    if(fator_balaceamento < -1 && calc_fb(r->esq) > 0)
    {
        r->esq = esqRotate(r->esq);
        return dirRotate(r);
    }
    ///right right case
    if(fator_balaceamento > 1 && calc_fb(r->dir) >= 0)
        return esqRotate(r);
    ///right right case
    if(fator_balaceamento > 1 && calc_fb(r->dir) < 0)
    {
        r->dir = dirRotate(r->dir);
        return esqRotate(r);
    }

    return r;
}

Nodo* dirRotate(Nodo*y)
{
    Nodo*x = y->esq;
    Nodo*t2 = x->dir;

    x->dir = y;
    y->esq = t2;

    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

Nodo* esqRotate(Nodo*x)
{
    Nodo*y = x->dir;
    Nodo*t2 = y->esq;

    y->esq = x;
    x->dir = t2;

    x->altura = max(altura(x->esq), altura(x->dir)) + 1;        x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

int calc_fb(Nodo*r)
{
    if(r == NULL)
        return 0;
    return altura(r->dir) - altura(r->esq);
}
