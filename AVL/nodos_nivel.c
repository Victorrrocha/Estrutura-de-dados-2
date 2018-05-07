#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int num_nodos = 0;

void nodos_nivel_arv(Arv_avl*arv, int nivel)
{
    nodos_nivel(arv->raiz, nivel);
    printf("%d\n", num_nodos);
}

int nodos_nivel(Nodo*no, int nivel)
{
    if(no->altura == nivel)
        num_nodos++;
    else
    {
        nodos_nivel(no->esq, nivel);
        nodos_nivel(no->dir, nivel);
    }
}
