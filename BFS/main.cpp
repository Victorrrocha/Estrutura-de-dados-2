#include <iostream>
#include <queue>
#include <list>
#include <limits.h>

using namespace std;
enum Color {BRANCO, CINZA, PRETO};

typedef struct grafo
{
    int V;
    list<int> *adj;

}Grafo;
///
typedef struct vertice
{
    int valor;
    int cor;
    int distancia;
    int pai;

} Vertice;
///
Grafo*criar_grafo(int V)
{
    Grafo*x = new Grafo;
    x->V = V;
    x->adj = new list<int>[V];
    return x;
}
///
Vertice*criar_vertice(int key)
{
    Vertice*y = new Vertice;
    y->valor = key;
    y->cor = y->distancia = y->pai = NULL;
}
///
void criar_aresta(Grafo*x, int v, int w)
{
    x->adj[v].push_back(w);
}

void BFS(Grafo* G, int s)
{
    int cor[G->V];
    int distancia[G->V];
    int pai[G->V];

    for(int i = 0; i < G->V; i++)
    {
        cor[i] = BRANCO;
        distancia[i] = INT_MAX;
        pai[i] = NULL;
    }

    cor[s] = CINZA;
    distancia[s] = 0;
    queue <int> Q;
    Q.push(s);

    while(!Q.empty())
    {
        int u;
        u = Q.front();
        cout << u << " ";
        Q.pop();

        list<int>::iterator v;
        for(v = G->adj[u].begin(); v != G->adj[u].end(); v++)
        {
            if(cor[*v] == BRANCO)
            {
                cor[*v] = CINZA;
                distancia[*v] = distancia[u] + 1;
                pai[*v] = u;
                Q.push(*v);
            }
        }
        cor[u] = PRETO;
    }
}

int main()
{
    Grafo*g = criar_grafo(4);

    criar_aresta(g, 0,1);
    criar_aresta(g, 0,2);
    criar_aresta(g, 1,2);
    criar_aresta(g, 1,3);

    BFS(g, 0);
    return 0;
}
