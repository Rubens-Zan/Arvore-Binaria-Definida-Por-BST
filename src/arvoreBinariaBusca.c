#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinariaBusca.h"

/* -------------------------------------------------------------------------- */
tNo *inicia(const char *valor)
{
    tNo *n = (tNo *)malloc(sizeof(tNo));
    n->chave = atoi(valor);
    n->dir = NULL;
    n->esq = NULL;

    return n;
}
/* -------------------------------------------------------------------------- */
tNo *criaNo(int chave)
{
    tNo *n = (tNo *)malloc(sizeof(tNo));
    n->chave = chave;
    n->esq = NULL;
    n->dir = NULL;
    n->pai = NULL;
    return n;
};
/* -------------------------------------------------------------------------- */
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
/* -------------------------------------------------------------------------- */
int token_to_num(const char *str, int *indice, int * chave)
{
    char token[100];
    int i = 0;
    while (str[*indice] != '(' && str[*indice] != ')' && str[*indice] != ' ')
    {
        token[i] = str[*indice];
        i++;
        (*indice)++;
    }
    token[i] = '\0';
    (*chave) += atoi(token); 
    (*indice)++;
    return 
        atoi(token);
};
/* -------------------------------------------------------------------------- */
tNo *montaarvore(const char *str, int * chave)
{
    tNo *raiz = NULL;
    int res = 0;
    int i = 0, v = 0;
    raiz = inclui(NULL, token_to_num(str, &i, chave));
    while (str[i] != '\0')
    {
        inclui(raiz, token_to_num(str, &i, chave));
    } 
    return raiz;
};
/* -------------------------------------------------------------------------- */

tNo *montaArvorePrincipal(int chave)
{
    tNo *raiz = NULL;
    raiz = inclui(NULL, chave);
    return raiz;
};
/* -------------------------------------------------------------------------- */
void emordem(tNo *no)
{   
    if (no != NULL)
    {
        emordem(no->esq);
        printf(" %d \n", no->chave); 
        emordem(no->dir);
    }
};
/* -------------------------------------------------------------------------- */
void arvoreResultante(tNo *no)
{ 
    printf("["); 
    if (no != NULL)
    {
        printf("%d\n", no->chave);  
        if (no->dir != NULL || no->esq != NULL){
            arvoreResultante(no->esq);
            arvoreResultante(no->dir);
        }
    }else{
        printf("\n"); 
    }
    printf("]\n"); 
};
/* -------------------------------------------------------------------------- */
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
/* -------------------------------------------------------------------------- */
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
/* -------------------------------------------------------------------------- */
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
/* -------------------------------------------------------------------------- */
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
/* -------------------------------------------------------------------------- */
tNo *min(tNo *no)
{
    if (no->esq == NULL)
        return no;
    else
        return min(no->esq);
};
