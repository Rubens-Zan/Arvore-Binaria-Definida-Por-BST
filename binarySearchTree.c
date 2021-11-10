#include <stdlib.h>
#include <stdio.h>

typedef struct tNo tNo;
struct tNo
{
    int chave; // pode ser modificado para qualquer tipo de dado
    tNo *esq, *dir, *pai;
};

tNo *criaNo(int chave)
{
    tNo *n = (tNo *)malloc(sizeof(tNo));
    n->chave = chave;
    n->esq = NULL;
    n->dir = NULL;
    n->pai = NULL;
    return n;
};

tNo *inclui(tNo *no, int c)
{
    if (no == NULL)
        return criaNo(c);
    if (c < no->chave)
    {
        no->esq = inclui(no->esq, c);
        no->esq->pai = no;
    }
    else
    {
        no->dir = inclui(no->dir, c);
        no->dir->pai = no;
    }
    return no;
};

tNo *inclusaoIterativa(tNo *no, int c)
{
    if (no == NULL)
        return criaNo(c);
    tNo *pai, *raiz = no;
    while (no != NULL)
    {
        pai = no;
        if (c < no->chave)
            no = no->esq;
        else
            no = no->dir;
    }
    no = criaNo(c);
    if (c < pai->chave)
        pai->esq = no;
    else
        pai->dir = no;
    no->pai = pai;
    return raiz;
};

int token_to_num(const char *str, int *indice)
{
    char token[100];
    int i = 0;
    while (str[*indice] != '\0' && str[*indice] != ' ')
    {
        token[i] = str[*indice];
        i++;
        (*indice)++;
    }
    token[i] = '\0';
    (*indice)++;
    return atoi(token);
};

tNo *montaarvore(const char *str)
{
    tNo *raiz = NULL;
    int resultado = 0;
    int i = 0, v = 0;
    raiz = inclui(NULL, token_to_num(str, &i));
    while (str[i] != '\0')
    {
        inclui(raiz, token_to_num(str, &i));
        resultado += token_to_num(str, &i); 
    }
    printf("RESULTADO DO MONTA ARVORE :: %d \n", resultado); 
    return raiz;
};


void visita(tNo *no)
{
    printf("%d . ", no->chave);
};

void preordem(tNo *no)
{
    if (no != NULL)
    {
        visita(no);
        preordem(no->esq);
        preordem(no->dir);
    }
};

void emordem(tNo *no)
{
    if (no != NULL)
    {
        emordem(no->esq);
        visita(no);
        emordem(no->dir);
    }
};

void posordem(tNo *no)
{
    if (no != NULL)
    {
        posordem(no->esq);
        posordem(no->dir);
        visita(no);
    }
};

int contaNos(tNo *no)
{
    if (no != NULL)
    {
        return contaNos(no->esq) + contaNos(no->dir) + 1;
    }
    else
        return 0;
};

int altura(tNo *p)
{
    int he, hd;
    if (p == NULL)
        return -1;
    he = altura(p->esq);
    hd = altura(p->dir);
    if (he > hd)
        return he + 1;
    else
        return hd + 1;
};

tNo *busca(tNo *no, int chave)
{
    if (no == NULL)
        return NULL;
    if (no->chave == chave)
        return no;
    if (chave < no->chave)
        return busca(no->esq, chave);
    else
        return busca(no->dir, chave);
};

tNo *buscaIterativa(tNo *no, int chave)
{
    while (no != NULL && no->chave != chave)
    {
        if (chave < no->chave)
            no = no->esq;
        else
            no = no->dir;
    }
    return no;
};

void imprime(const char *str, tNo *no)
{
    printf("|| %s   ", str);
    if (no != NULL)
        printf("[%d]  ", no->chave);
    else
        printf("nao");
    printf("encontrado \n");
};

tNo *min(tNo *no)
{
    if (no->esq == NULL)
        return no;
    else
        return min(no->esq);
};

tNo *sucessor(tNo *no)
{
    tNo *s = NULL;
    if (no->dir != NULL)
        return min(no->dir);
    else
    {
        s = no->pai;
        while (s != NULL && no == s->dir)
        {
            no = s;
            s = s->pai;
        }
    }
    return s;
};

void ajustaNoPai(tNo *no, tNo *novo)
{
    if (no->pai != NULL)
    {
        if (no->pai->esq == no)
            no->pai->esq = novo;
        else
            no->pai->dir = novo;
        if (novo != NULL)
            novo->pai = no->pai;
    }
};

tNo *exclui(tNo *no, tNo *raiz)
{
    tNo *s, *novaRaiz = raiz;
    if (no->esq == NULL)
    {
        ajustaNoPai(no, no->dir);
        free(no);
    }
    else
    {
        if (no->dir == NULL)
        {
            ajustaNoPai(no, no->esq);
            free(no);
        }
        else
        {
            s = sucessor(no);
            ajustaNoPai(s, s->dir);
            s->esq = no->esq;
            s->dir = no->dir;
            ajustaNoPai(no, s);
            if (no == raiz)
                novaRaiz = s;
            free(no);
        }
    }
    return novaRaiz;
};