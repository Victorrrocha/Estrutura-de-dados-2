#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


int parent(int i)
{
    return i/2;
}

int left(int i)
{
    return 2*i;
}

int right(int i)
{
    return (2*i) +1;
}

void min_heapify(int heap[],int n, int i)
{
    int largest = i;
    int l = left(i);
    int r = right(i);

    if(l < n && heap[l] > heap[largest])
    {
        largest = l;
    }

    if(r < n && heap[r] > heap[largest])
        largest = r;

    if(largest != i)
    {
        int aux = heap[i];
        heap[i] = heap[largest];
        heap[largest] = aux;

        min_heapify(heap,n, largest);
    }
}

void heapsort(int arr[], int n)
{
    int i;
    for(i = n / 2 -1; i >= 0; i--)
        min_heapify(arr, n, i);

    for(i = n - 1; i >= 0; i--)
    {
        int aux = arr[0];
        arr[0] = arr[i];
        arr[i] = aux;

        min_heapify(arr, i, 0);
    }
}

void imprimir(int arr[], int n)
{
    int i;
    for(i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}
