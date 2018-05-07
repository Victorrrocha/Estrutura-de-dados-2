#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int main()
{
    Arv_avl*oak = abb_cria();
    abb_insere(oak, 40);
    abb_insere(oak, 30);
    abb_insere(oak, 50);
    abb_insere(oak, 20);
    abb_insere(oak, 10);

    imprime(oak, 2);
    return 0;
}
