typedef struct no
{
    int info;
    struct no* esq;
    struct no* dir;
    int altura;
} Nodo;

typedef struct avl
{
    Nodo* raiz;
}Arv_avl;

Arv_avl* abb_cria(void);
void imprime(Arv_avl*arv, int escolha);
void imprime_no(Nodo*r, int escolha);
void imprime_pre(Nodo*r);
void imprime_in(Nodo*r);
void imprime_pos(Nodo*r);
void libera(Arv_avl* arv);
void libera_no(Nodo*r);
Nodo* busca_no(Nodo* r, int i);
Nodo* busca_no_interativa(Nodo* r, int i);
void abb_insere(Arv_avl*arv, int i);
Nodo* abb_insere_no(Nodo*r, int i);
void remover(Arv_avl*avr, int i);
Nodo* remover_no(Nodo*r, int c);
int altura(Nodo*a);
int max(int a, int b);
Nodo* novo_nodo(int info);
int calc_fb(Nodo*r);
Nodo* dirRotate(Nodo*y);
Nodo* esqRotate(Nodo*x);

