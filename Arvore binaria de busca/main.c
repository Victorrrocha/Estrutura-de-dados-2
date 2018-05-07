#include <stdio.h>
#include <stdlib.h>
#include "arv_busca.h"

int main()
{
    Arv*oak = abb_cria();
    insere(oak, 10);
    insere(oak, 30);
    insere(oak, 5);

    imprime(oak, 2);
    return 0;
}
