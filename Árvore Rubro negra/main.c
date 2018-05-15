#include <stdio.h>
#include <stdlib.h>
#include "arvoreRB.h"

int main()
{
    Arv*oak = ARB_cria();

    inserir(oak, 1);
    inserir(oak, 2);
    inserir(oak, 3);
    inserir(oak, 4);

    imprime(oak, 2);

    return 0;
}
