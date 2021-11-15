#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "arvoreBinariaBusca.h"

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
            return NULL;
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
    return NULL; 
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
void calculaChaveArvore(tArvoreB *no, int *chave){
    if (no != NULL)
    {
        calculaChaveArvore(no->esq, chave);
        (*chave) += no->chave; 
        calculaChaveArvore(no->dir, chave);
    }
}
/* -------------------------------------------------------------------------- */
void preordem(tArvoreB *no){
    if (no != NULL){
        printf(" %d \n", no->chave); 
        preordem(no->dir);
        preordem(no->esq);
    }
}
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
void arvoreResultante(tArvoreB *no)
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
tArvoreB *exclui(tArvoreB *no, tArvoreB *raiz)
{
    tArvoreB *s, *novaRaiz = raiz;
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
tArvoreB *sucessor(tArvoreB *no)
{
    tArvoreB *s = NULL;
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
void ajustaNoPai(tArvoreB *no, tArvoreB *novo)
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
tArvoreB *busca(tArvoreB *no, int chave)
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
tArvoreB *min(tArvoreB *no)
{
    if (no->esq == NULL)
        return no;
    else
        return min(no->esq);
};
