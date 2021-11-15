#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "arvoreSecundaria.h"

/* -------------------------------------------------------------------------- */
tArvoreB *inicia(const char *valor)
{
    tArvoreB *n = (tArvoreB *)malloc(sizeof(tArvoreB));
    n->chave = atoi(valor);
    n->dir = NULL;
    n->esq = NULL;

    return n;
}
/* -------------------------------------------------------------------------- */
tArvoreB *criaNo(int chave)
{
    tArvoreB *n = (tArvoreB *)malloc(sizeof(tArvoreB));
    n->chave = chave;
    n->esq = NULL;
    n->dir = NULL;
    n->pai = NULL;
    
    return n;
};
/* -------------------------------------------------------------------------- */
tArvoreB *inclui(tArvoreB *no, int c)
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
int token_to_num(const char *str, int *indice)
{
    char token[100];
    int i = 0;
    if (str[*indice] == '('){
        (*indice)++;
        if  (!(ehNumero(str[*indice]))){
            (*indice)++;
            return 0;
        }
        
        while (ehNumero(str[*indice]))
        {
            token[i] = str[*indice];
            i++;
            (*indice)++;
        }
        token[i] = '\0';
        return 
            atoi(token);
    }
    
    (*indice)++;
    return 0; 
};
/* -------------------------------------------------------------------------- */
tArvoreB *montaarvore(const char *str)
{
    tArvoreB *raiz = NULL;
    int i = 0;
    raiz = inclui(NULL, token_to_num(str, &i));
    while (str[i] != '\0')
    {
        if (str[i] == '(' && ehNumero(str[i+1]))
            inclui(raiz, token_to_num(str, &i));
        else 
            i++; 
    } 
    return raiz;
};
/* -------------------------------------------------------------------------- */
void emordem(tArvoreB *no)
{   
    if (no != NULL)
    {
        emordem(no->esq);
        printf(" %d \n", no->chave); 
        emordem(no->dir);
    }
};
/* -------------------------------------------------------------------------- */