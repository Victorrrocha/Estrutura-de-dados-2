enum Color {BLACK = 1, RED = 0};

typedef struct no
{
    int info;
    int color;
    struct no* esq;
    struct no* dir;
    struct no* p;
}Nodo;

typedef struct arv
{
    Nodo* raiz;
}Arv;

Arv* ARB_cria(void);
Nodo*criar_nodo(int info);

void imprime(Arv*arv, int escolha);
void imprime_no(Nodo*r, int escolha);
void imprime_pre(Nodo*r);
void imprime_in(Nodo*r);
void imprime_pos(Nodo*r);

void libera(Arv* arv);
void libera_no(Nodo*r);

void remover_arv(Arv*arv, int key);
Nodo*remover_no(Nodo*raiz, int key);

Nodo* busca_no(Nodo* r, int i);
Nodo* busca_no_interativa(Nodo* r, int i);

void inserir(Arv*t, int info);
void rb_insert(Arv*t, Nodo*z);
void rb_fix_up_insert(Arv*t, Nodo*z);

void leftRotate(Arv*t, Nodo*x);
void rightRotate(Arv*t,Nodo*x);
