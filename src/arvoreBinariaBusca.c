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