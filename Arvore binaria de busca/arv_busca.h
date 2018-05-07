typedef struct no
{
    int info;

    struct no* esq;
    struct no* dir;
}Nodo;

typedef struct arv
{
    Nodo* raiz;
}Arv;

Arv* abb_cria(void);

void imprime(Arv*arv, int escolha);
void imprime_no(Nodo*r, int escolha);
void imprime_pre(Nodo*r);
void imprime_in(Nodo*r);
void imprime_pos(Nodo*r);

void libera(Arv* arv);
void libera_no(Nodo*r);

Nodo* busca_no(Nodo* r, int i);
Nodo* busca_no_interativa(Nodo* r, int i);

void insere(Arv*arv, int i);
Nodo* insere_no(Nodo*r, int i);

void remover_arv(Arv*avr, int i);
Nodo* remover_no(Nodo*r, int c);
