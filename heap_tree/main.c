#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main()
{
    int arr[] = {7,2,3,5,1,6};

    int n = sizeof(arr)/sizeof(arr[0]);

    heapsort(arr, n);

    imprimir(arr, n);
    return 0;
}
